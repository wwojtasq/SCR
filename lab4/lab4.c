#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

#define BUFOR 5

int main (int argc, char const *argv[]){
	char my_string[BUFOR]
	if(argc<2){
		fprintf(stderr, "%s\n", "brak pliku");
		return 1;
	}
	if(argc>2){
		fprintf(stderr, "%s\n", "za duzo argumentow");
		return 1;
	}
	
	pid_t process, child_process;
	int pipe1[2];
	if(pipe(pipe1)==-1){
		fprintf(stderr, "pipe fail");
		return 1;
		}
	
	child_process=fork();
	if(child_process==0){
		close(pipe1[1]);
		while(read(pipe1[0],&my_string,BUFOR) !=0){
			printf("# %s #\n",my_string);
			for (int i=0; i<BUFOR; i++){
				my_string[i]='\0';
				}
			}
		close(pipe1[0]);
	}
	else {
		const char* filename=argv[1];
		FILE*fptr;
		
		if(fptr=fopen(filename, "r"))==NULL){
			fprintf(stderr, "%s\n", "blad przy otwieraniu pliku");
			return 1;
		}
		char buffer[BUFOR];
		close(pipe1[0]);
		while(fgets(buffer, BUFOR, fptr)!=NULL){
			write(pipe1[1],buffer,strlen(buffer));
			}
		fclose(fptr);
		close(pipe1[1]);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
return 0;
}
		
	
