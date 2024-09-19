#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
static void catch_function(int signal) {
	puts("Interactive attention signal caught.");
}
int main(void) {
	if (signal(SIGINT, catch_function) == SIG_ERR) {
		// SIG_ERR is not a valid signal number.
		// When the user presses Ctrl+C, 
		// the signalHandler (catch_function) function will be called
		fputs("The Ctrl+C occurred with error under setting a signal handler.\n", stderr);
		return EXIT_FAILURE;
	}
	puts("Raising the interactive attention signal.");
	if (raise(SIGINT) != 0) {	
	// the raise function is used to send a signal to the current process.
	// It is the interrupt signal, often generated when the user presses Ctrl+C in the terminal
		fputs("Error raising the signal.\n", stderr);
		return EXIT_FAILURE;
	}
	puts("Exiting.");
	return 0;
}
