#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>

void list(char *dn, char op) {
    DIR *dp = opendir(dn); 
    struct dirent *entry;
    int dc = 0, fc = 0;
    
    while ((entry = readdir(dp))) {
        if (op == 'f' && entry->d_type == DT_REG){
	       	printf("%s\n", entry->d_name);
	}
        if (op == 'n') { 
		if (entry->d_type == DT_DIR) 
			dc++; 
		if (entry->d_type == DT_REG) 
			fc++; 
	}
        if (op == 'i' && entry->d_type == DT_REG){ 
		printf("%s\t%ld\n", entry->d_name, entry->d_fileno);
	}
    }
    if (op == 'n'){
	    printf("%d Dir(s)\t%d File(s)\n", dc, fc);
    }
    closedir(dp);
}

void main() {
    char buff[80], *args[10];
    while (1) {
	int i = 0;
        printf("myshell$ ");
       	fgets(buff, 80, stdin);
        buff[strlen(buff) - 1] = '\0';
        args[i] = strtok(buff, " ");
        while (args[++i] = strtok(NULL, " "));
        if (!strcmp(args[0], "list")){
	       	list(args[2], args[1][0]);
	}
	else{
		printf("Bad command.\n");
		  
	}
       
    }

}
