// your code here
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>

int main(int argc, char** argv){
	if (argc<3) {
		printf("Too few args.\n");
		exit(1);
	}
	pid_t p1 = fork();

	if(p1 == 0){
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);
		printf("child1: %d + %d = %d\n",a,b,a+b);
		exit(0);
	}
	pid_t p2 = fork();
	if(p2 == 0){
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);
		printf("child2: %d - %d = %d\n",a,b,a-b);
		exit(0);
	}
	pid_t p3 = fork();
	if(p3 == 0){
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);
		printf("child3: %d * %d = %d\n",a,b,a*b);
		exit(0);
	}
	pid_t p4 = fork();
	if(p4 == 0){
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);
		printf("child4: %d / %d = %d\n",a,b,a/b);
		exit(0);
	}
	waitpid(p1, NULL, 0);
    	waitpid(p2, NULL, 0);
    	waitpid(p3, NULL, 0);
    	waitpid(p4, NULL, 0);

	printf("parent: done.\n");
}




