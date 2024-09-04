#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void typeline(char *op, char *fn) {
    int fh = open(fn, O_RDONLY), n = atoi(op), lines = 0; 
    char c;
    while (n < 0 && read(fh, &c, 1) > 0) 
	    if (c == '\n') {
		    lines++;
	    }
    		lseek(fh, 0, SEEK_SET);
    		while (read(fh, &c, 1) > 0 && (n == 0 || c != '\n' || lines-- > -n)){
		       	printf("%c", c);
		}
    		close(fh);
}

void main() {
    char buff[80], *args[10];
    while (1) {
	int i=0;
        printf("\nmyshell$ ");
        fgets(buff,80, stdin);
	buff[strlen(buff)-1]='\0';
        
        args[i] = strtok(buff, "  ");
    	while (args[++i] = strtok(NULL, " "));
        if (!strcmp(args[0], "typeline")){
                typeline(args[1], args[2]);
        }
        else{
                printf("Bad command.\n");

        }
    }
}
