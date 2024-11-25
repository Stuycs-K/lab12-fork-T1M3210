#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>

int main() {
	pid_t p;
	p = fork();
	if (p < 0) {
		perror("fork fail");
	}
	printf("%d about to create %d child processes\n", getpid(), 2);
	return 0;
}
