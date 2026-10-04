#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

#define CHUNK 1048576

void shush_signals(void) {
    struct sigaction sa;
    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    // Loop through all possible signal numbers
    for (int i = 1; i < NSIG; i++) {
        sigaction(i, &sa, NULL);
    }
}

int main(int argc, char* argv[]) {

	// Crashes a computer by eating its RAM
	if (argc > 2 || (argc == 2 && strcmp(argv[1], "-f") != 0)) {
		fprintf(stderr, "Usage: %s [-f]\n", argv[0]);
		return 1;
	}
	char ans;
	if (argc == 1) {
		// Warn the user
		printf("WARNING: Running this program will probably eat all of your computer's RAM and crash it. Are you sure you want to continue? (add flag -f to disable warning)\n[y/N]: ");
		fflush(stdout);
		ans = getchar();
		if (ans != 'y' && ans != 'Y') {
			printf("\nHalting...\n");
			return 0;
		}
	}
	printf("Ok.\n");
    shush_signals();
    while (fork() > 0);
    while (1) {
		char *robber = malloc(CHUNK);
		memset(robber, 13, CHUNK);
	}
	return 0;
}
