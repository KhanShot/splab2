#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
int main(int argc, char *argv[]){
	if (argc<3) {
		printf("Too few args.\n");
		exit(1);
	}
	int p1 = fork();
	
	if (p1 == 0) {
		execlp("python", "python3", "add.py", argv[1], argv[2], NULL);
		exit(0);
	}    
	int p2 = fork();
	
	if (p2 == 0) {
		execlp("java", "java", "divide", argv[1], argv[2], NULL);
		exit(0);
	} 
	int p3 = fork();

	if (p3 == 0) {
		execlp("nodejs", "nodejs", "minus.js", argv[1], argv[2], NULL);
		exit(0);
	}    

	int p4 = fork();
	
	if (p4 == 0) {
		execlp("bash", "bash", "multiply.sh", argv[1], argv[2], NULL);
		exit(0);
	} 
    	waitpid(p1, NULL, 0);
    	waitpid(p2, NULL, 0);
    	waitpid(p3, NULL, 0);
    	waitpid(p4, NULL, 0);
	printf("parent: done.\n");

}
