#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int check_bhost(char *file, char *host_name){

	FILE *fp = fopen(file, "r");
	if(fp == NULL){
		printf("cannot open file: %s\n", file);
		return -1;
	};

    printf("searching \n");
	printf("host_name : %s \n",host_name);

    char line[1024] = {0,};
    //host_name[strcspn(host_name, "\n")] = 0;
    bool find = false;

	while (fgets(line, sizeof(line), fp) != NULL) {
        //line[strcspn(line, "\n")] = 0;
     

        char *pos = strstr(line,",");
        pos += 1; 
        char *last_dot_pos = strrchr(pos, '\n');
        *last_dot_pos = '\0';
        char*post = strdup(pos);

		if(strcmp (post, host_name) == 0) {
			printf("pos%s \n", post);
			printf("host_name%s \n", host_name);
			printf("%s is in the block_host \n", host_name);
			find = true;
			break;
		}
		
	}

	if (find) {
		fclose(fp);
		return 1;
	} else {
		fclose(fp);
		return 0;
	}
};

int main() {
    check_bhost("top-1m.csv", "google.com");
    return 0;
}
