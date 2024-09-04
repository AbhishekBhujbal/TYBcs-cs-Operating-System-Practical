#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void count(char *fn, char op) {
    int fh = open(fn, O_RDONLY), cc = 0, wc = 0, lc = 0;
    char c;
    while (read(fh, &c, 1) > 0) {
        if (c == ' '){
	       	wc++;
	}
        else if (c == '\n') {
	       	wc++; 
		lc++;
   	}
        cc++;
    }
    if (op == 'c') printf("no.of Characters: %d\n", cc - 1);
    if (op == 'w') printf("no.of Words: %d\n", wc);
    if (op == 'l') printf("no.of Lines: %d\n", lc + 1);
    close(fh);
}

void main() {
    
    char buff[80], *args[10];
    while (1) {
	    int i = 0;
        printf("myshell$ ");
        fgets(buff, 80, stdin);
        buff[strlen(buff)-1] = '\0';
        
       	args[i] = strtok(buff, " ");
        while (args[++i] = strtok(NULL, " "));
        if (!strcmp(args[0], "count")){
	       	count(args[2], args[1][0]);
	}
        else {
		printf("Bad command.\n");
	}
    }
    
}
