#include <stdio.h> 
#include <string.h>


int check_bhost(char *file, char *host_name){

	FILE *fp = fopen(file, "r");
	if(fp == NULL){
		printf("cannot open file: %s\n", file);
		return -1;
	}

	// file read 
	char line[1024];
	
	while(fgets(line, sizeof(line), fp) != NULL){
		char *pos = strstr(line,",");
		printf("%s",pos + 1);

		if(!strcmp(pos, host_name)){
			printf("%s is in the block_host", host_name);
			fclose(fp);
			return 1; 
		}else{
			
			printf("%s is not in the block_host", host_name);
			fclose(fp);
			return 0;
		}

	}
}




int main(void) {
    char* host_name = "test.gilgil.net";
    char* file_name = "top-1m.csv";
    check_bhost(file_name, host_name);

    return 0;
}