#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>

int randomint() {
	int id = getpid();
	return id % 6;
}

int main() {
	printf("%d about to create %d child processes\n", getpid(), 2);
	pid_t p, q;
	(p = fork()) && (q = fork());
	//if (p < 0) perror("p fork fail");
	//if (q < 0) perror("q fork fail");
	if (p == 0) {
		// child p code
		int prand = randomint();
		printf("%d %dsec\n", getpid(), prand);
		sleep(prand);
		printf("%d finished after %dsec\n", getpid(), prand);
	} else if (q == 0) {
		// child q code
		int qrand = randomint();
		printf("%d %dsec\n", getpid(), qrand);
		sleep(qrand);
		printf("%d finished after %dsec\n", getpid(), qrand);
	} else {
		// parent code
	}
	return 0;
}
