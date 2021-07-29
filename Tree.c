#include <string.h>
#include <stdlib.h>
#include <dirent.h>		//Header file to access directory structure
#include <errno.h>
#include <stdio.h>



int a = -1;			//integer to traverse through levels of directories
int fcount = 0, dcount = 0;	//Counts no. of files and folders


void ifiles(const char *name){

	DIR *dir;
	char * occ,  space[128], line[128], buf[128];
	int i;
	struct dirent *filename;

	//error if directory does not found
	if (!(dir = opendir(name))){
		printf("tree : '%s' : %s\n", name, strerror(errno));
        	return;
        }
	if (!(filename = readdir(dir))){
		printf("%s\n", strerror(errno));
		return;
	}

	
	if(a >= 0){
		occ = strrchr(name,'/');
		i = occ - name;
		strncpy(buf, name+i+1, strlen(name));	
	}
	printf("%s\n", buf);
	do {
		if (filename->d_type == DT_DIR) {     	
			char path[1024];
			snprintf(path, sizeof(path), "%s/%s", name, filename->d_name);
			if (strcmp(filename->d_name, ".") == 0 || strcmp(filename->d_name, "..") == 0)
				continue;
			a++;
			dcount++;			
			ifiles(path);
		}
		else{					
			
			
			printf("%s\n", filename->d_name);	
			
			a = -1;
			fcount++;
			}			
		
	} while ((filename = readdir(dir)));
	closedir(dir);
}


void files(const char *name)
{
	DIR *dir;
	char * occ,  space[128], line[128], buf[128];
	int i;
	struct dirent *filename;
	strcpy(space,"");
	strcpy(buf, "");
	strcpy(line, "|-----");
	if (!(dir = opendir(name))){
		printf("tree : '%s' : %s\n", name, strerror(errno));
        	return; 
        }
	if (!(filename = readdir(dir))){
		printf("%s\n", strerror(errno));
		return;
	}
	for(i=0;i<=a;i++)
		strcat(space, "|\t");
	if(a >= 0){
		occ = strrchr(name,'/');
		i = occ - name;
		strncpy(buf, name+i+1, strlen(name));	
	}
	printf("%s%s", space, line);
	printf("%s\n", buf);
	do {
		if (filename->d_type == DT_DIR) {
			char path[1024];
			snprintf(path, sizeof(path), "%s/%s", name, filename->d_name);
			if (strcmp(filename->d_name, ".") == 0 || strcmp(filename->d_name, "..") == 0)
				continue;
			a++;
			dcount++;
			files(path);
		}
		else{
			
			printf("%s%s%s\n", space, line, filename->d_name);
		
			
			a = -1;
			fcount++;
			}
		
	} while ((filename = readdir(dir)));
	closedir(dir);
}


void folders(const char *name)
{
	DIR *dir;
	char * occ,  space[128], line[128], buf[128];
	int i;
	struct dirent *filename;
	strcpy(space, "");
	strcpy(buf, "");
	strcpy(line, "|-----");
	if (!(dir = opendir(name))){
		printf("tree : '%s' : %s\n", name, strerror(errno));
		return;
	}
	if (!(filename = readdir(dir))){
		printf("%s\n", strerror(errno));
		return;
	}
	for(i=0;i<=a;i++)
		strcat(space, "|\t");
	if(a >= 0){
		occ = strrchr(name, '/');
		i = occ - name;
		strncpy(buf, name+i+1, strlen(name));	
	}
	do {
		if (filename->d_type == DT_DIR) {
			char path[1024];
			snprintf(path, sizeof(path), "%s/%s", name, filename->d_name);
			if (strcmp(filename->d_name, ".") == 0 || strcmp(filename->d_name, "..") == 0)
				continue;
			a++;
			printf("%s%s", space, line);
			printf("%s\n", filename->d_name);
			dcount++;
			folders(path);
		}
		else{             
			a = -1;
			fcount++;
		}
	}while ((filename = readdir(dir)));
	closedir(dir);
}


void printhelp(void){
	FILE *fp;
	char c, *s="help.txt";
	fp = fopen(s, "r");
	if(fp == NULL){
		printf("cann't open file");
		exit(0);
	}
	c=fgetc(fp);
	while(c != EOF){
		printf("%c", c);
		c=fgetc(fp);
	}
	fclose(fp);
}


void ffiles(const char *name)
{
	DIR *dir;
	char * occ,  space[128], line[128], buf[128];
	int i;
	struct dirent *filename;
	strcpy(space, "");
	strcpy(buf, "");
	strcpy(line, "|-----");
	if (!(dir = opendir(name))){
		printf("tree : '%s' : %s\n", name, strerror(errno));
		return;
	}
	if (!(filename = readdir(dir))){
		printf("%s\n", strerror(errno));
		return;
	}
	for(i=0;i<=a;i++)
		strcat(space, "|\t");
	printf("%s%s", space, line);
	printf("%s\n", name);
	do {
		if (filename->d_type == DT_DIR) {
			char path[1024];
			snprintf(path, sizeof(path), "%s/%s", name, filename->d_name);
			if (strcmp(filename->d_name, ".") == 0 || strcmp(filename->d_name, "..") == 0)
				continue;
			a++;
			dcount++;
			ffiles(path);
		}
		else{

			printf("%s%s%s/%s\n", space, line, name, filename->d_name);
			
			a = -1;
			fcount++;
		}
		
	} while ((filename = readdir(dir)));
	closedir(dir);
}

 
void fifiles(const char *name){

	DIR *dir;
	char * occ,  space[128], line[128], buf[128];
	int i;
	struct dirent *filename;
	strcpy(space, "");
	strcpy(buf, "");
	strcpy(line, "|-----");
	if (!(dir = opendir(name))){
		printf("tree : '%s' : %s\n", name, strerror(errno));
        	return;
        }
	if (!(filename = readdir(dir))){
		printf("%s\n", strerror(errno));
		return;
	}
	
	strncpy(buf, name+1, strlen(name));	
	printf("%s\n", buf);
	do {
		if (filename->d_type == DT_DIR) {
			char path[1024];
			snprintf(path, sizeof(path), "%s/%s", name, filename->d_name);
			if (strcmp(filename->d_name, ".") == 0 || strcmp(filename->d_name, "..") == 0)
				continue;
			a++;
			dcount++;
			fifiles(path);
		}
		else{
			
			printf("%s/%s\n", name, filename->d_name);
			}
			
			a = -1;
			fcount++;
		
	} while ((filename = readdir(dir)));
	closedir(dir);
}

int main(int argc, char *argv[]){
	if(argc == 2) {
		if(argv[1] == NULL){ 
			files(".");
			printf("%d files and %d folders\n", fcount, dcount);
			return 0;
		}
		if(strcmp(argv[1],".") == 0){
			files(".");
			printf("%d files and %d folders\n", fcount, dcount);
			return 0;
		}
		if(strcmp(argv[1],"-h") == 0){
			printhelp();
			return 0;
		}
		else {
			files(argv[1]);
			printf("%d files and %d folders\n", fcount, dcount);
			return 0;
		}		
	}
	else if(argc == 3) {
		
		if(strcmp(argv[2],"-d") == 0){
			folders(argv[1]);
			printf("%d folders\n", dcount);
			return 0;
		}
		if(strcmp(argv[2],"-f") == 0){
			ffiles(argv[1]);
			printf("%d files and %d folders\n", fcount, dcount);
			return 0;
		}
		if(strcmp(argv[2],"-i") == 0){
			ifiles(argv[1]);
			printf("%d files and %d folders\n", fcount, dcount);
			return 0;
		}
		if(strcmp(argv[2],"-l") == 0){
			files(argv[1]);
			printf("%d files and %d folders\n", fcount, dcount);
			return 0;
		}
	}
	else {
		if((strcmp(argv[2],"-f") && strcmp(argv[3],"-i")) == 0){
			fifiles(argv[1]);
			printf("%d files and %d folders\n", fcount, dcount);
			return 0;
		}
		if((strcmp(argv[2],"-i") && strcmp(argv[3],"-f")) == 0){
			fifiles(argv[1]);
			printf("%d files and %d folders\n", fcount, dcount);
			return 0;
		}
		else {
			files(".");
			printf("%d files and %d folders\n", fcount, dcount);
			return 0;
		}
	}
	return 0;
}


	

