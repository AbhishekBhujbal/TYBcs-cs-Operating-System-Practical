#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void search(char *str, char *fn) {
    int fh = open(fn, O_RDONLY);
    if (fh == -1) {
        printf("File not found.\n");
        return;
    }

    char buffer[256];
    int read_size, found = 0;
    while ((read_size = read(fh, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[read_size] = '\0';  
        char *line = strtok(buffer, "\n"); 

        while (line) {
            if (strstr(line, str)) {  
                printf("%s\n", line);
                found = 1;
            }
            line = strtok(NULL, "\n"); 
        }
    }

    if (!found) {
        printf("No matches found for '%s'.\n", str);
    }
    close(fh);
}

void main() {
    char buff[80], *args[10];
    while (1) {
        int i = 0;
        printf("\nmyshell$ ");
        fgets(buff, 80, stdin);
        buff[strlen(buff) - 1] = '\0';  

        args[i] = strtok(buff, " ");
        while (args[++i] = strtok(NULL, " "));

        if (!strcmp(args[0], "search")){
                   search(args[1], args[2]);
          
        } else {
            printf("Bad command.\n");
        }
    }
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

void search(char *fn, char op, char *pattern) {
    int fh = open(fn, O_RDONLY);
    if (fh < 0) {
        perror("Error opening file");
        return;
    }

    int count = 0, i = 0, j = 0;
    char buff[255], c, *p;
    while (read(fh, &c, 1) > 0) {
        buff[j++] = c;
        if (c == '\n') {
            buff[j] = '\0';  // Null-terminate the buffer
            j = 0;  // Reset buffer index
            i++;  // Line number
            if (op == 'f' && strstr(buff, pattern)) {
                printf("%d: %s", i, buff);
                break;
            } else if (op == 'a' || op == 'f') {
                if (strstr(buff, pattern)) {
                    printf("%d: %s", i, buff);
                }
            } else if (op == 'c') {
                for (p = buff; (p = strstr(p, pattern)); p++) {
                    count++;
                }
            }
        }
    }

    // Print the last line if it does not end with a newline
    if (j > 0) {
        buff[j] = '\0';
        if (op == 'f' && strstr(buff, pattern)) {
            printf("%d: %s", i + 1, buff);
        } else if (op == 'a') {
            if (strstr(buff, pattern)) {
                printf("%d: %s", i + 1, buff);
            }
        } else if (op == 'c') {
            for (p = buff; (p = strstr(p, pattern)); p++) {
                count++;
            }
        }
    }

    if (op == 'c') {
        printf("Total No.of Occurrences = %d\n", count);
    }

    close(fh);
}

int main() {
    char buff[80], *args[10];
    while (1) {
        printf("MyShell $ ");
        fflush(stdout);  // Ensure prompt is printed

        if (fgets(buff, sizeof(buff), stdin) == NULL) {
            perror("fgets");
            exit(1);
        }
        buff[strlen(buff) - 1] = '\0';  // Remove newline character

        // Tokenize the input command
        int i = 0;
        args[i] = strtok(buff, " ");
        while ((args[++i] = strtok(NULL, " ")) != NULL);

        // Check for exit command
        if (args[0] && strcmp(args[0], "exit") == 0) {
            break;
        }

        // Check for custom 'search' command
        if (args[0] && strcmp(args[0], "search") == 0) {
            if (args[1] && args[2] && args[3]) {
                if (fork() == 0) {  // Child process
                    search(args[2], args[1][0], args[3]);
                    exit(0);
                } else {
                    wait(NULL);  // Wait for child process to finish
                }
            } else {
                printf("Usage: search <f|a|c> <filename> <pattern>\n");
            }
        } else {
            // Execute system command
            if (fork() == 0) {  // Child process
                execvp(args[0], args);  // Execute the command
                perror("execvp");  // Exec failed
                exit(1);
            } else {
                wait(NULL);  // Wait for child process to finish
            }
        }
    }
    return 0;
}*/

/*#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void search(char *fn, char op, char *pattern) {
    int fh = open(fn, O_RDONLY), count = 0, i = 0, j = 0;
    char buff[255], c, *p;
    while (read(fh, &c, 1)) {
        buff[j++] = c;
        if (c == '\n') {
            buff[j] = '\0'; j = 0; i++;
            if ((op == 'f' && strstr(buff, pattern)) || op == 'a') printf("%d: %s", i, buff);
            if (op == 'c') for (p = buff; (p = strstr(p, pattern)); p++, count++);
            if (op == 'f' && strstr(buff, pattern)) break;
        }
    }
    if (op == 'c') printf("Total No.of Occurrences = %d\n", count);
    close(fh);
}

int main() {
    char buff[80], *args[10];
    while (1) {
        int i = 0;
        printf("\nmyshell$ ");
        fgets(buff, 80, stdin);
        buff[strlen(buff) - 1] = '\0'; 

        args[i] = strtok(buff, " ");
        while ((args[++i] = strtok(NULL, " ")) != NULL);

        if (!strcmp(args[0], "search")) {
            if (args[1] && args[2] && args[3]) {
                search(args[3], args[1][0], args[2]);
            } 
        } else {
            printf("Bad command.\n");
        }
    }
}*/
/*#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void search(char *fn, char op, char *pattern) {
    int fh = open(fn, O_RDONLY), count = 0, i = 0, j = 0;
    char buff[255], c, *p;
    while (read(fh, &c, 1)) {
        buff[j++] = c;
        if (c == '\n') {
            buff[j] = '\0'; j = 0; i++;
            if ((op == 'f' && strstr(buff, pattern)) || op == 'a') printf("%d: %s", i, buff);
            if (op == 'c') for (p = buff; (p = strstr(p, pattern)); p++, count++);
            if (op == 'f' && strstr(buff, pattern)) break;
        }
    }
    if (op == 'c') printf("Total No.of Occurrences = %d\n", count);
    close(fh);
}
int main() {
    char buff[80], *args[10];
    while(1){
            int i=0;
            printf("\nmyshell$");
            fgets(buff, 80, stdin);
            buff[strlen(buff) - 1] = '\0';
            args[i]=strtok(buff,"  ");
            while(args[++i]=strtok(NULL,"  "));
            if (!strcmp(args[0], "search")){
                    search(args[3], args[1][0], args[2]);
            }
            else{
                    printf("Bad command.\n");
            }
    }
}*/


/*#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//void make_toks(char *s, char *tok[]) {
  //  for (int i = 0; (tok[i++] = strtok(s, " ")); s = NULL);
//}

void search(char *fn, char op, char *pattern) {
    int fh = open(fn, O_RDONLY), count = 0, i = 0, j = 0;
    char buff[255], c, *p;
    if (fh == -1) return printf("File %s Not Found\n", fn);
    while (read(fh, &c, 1)) {
        buff[j++] = c;
        if (c == '\n') {
            buff[j] = '\0', j = 0, i++;
            if (strstr(buff, pattern)) {
                if (op == 'f') return printf("%d: %s", i, buff);
                if (op == 'a') printf("%d: %s", i, buff);
                if (op == 'c') for (p = buff; (p = strstr(p, pattern)); p++, count++);
            }
        }
    }
    if (op == 'c') printf("Total No.of Occurrences = %d\n", count);
    close(fh);
}

int main() {
    char buff[80], *args[10];
    while(1){ 
	    int i=0;
	    printf("\nmyshell$");
	    fgets(buff, 80, stdin);
	    buff[strlen(buff) - 1] = '\0';
	    args[i]=strtok(buff,"  ");
	    while(args[++i]=strtok(NULL,"  "));
	    if (!strcmp(args[0], "search")){
		    search(args[3], args[1][0], args[2]);
	    }
            else{
		    printf("Bad command.\n");
	    }
    }
}*/
