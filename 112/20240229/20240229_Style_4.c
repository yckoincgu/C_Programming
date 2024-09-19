#include <stdio.h>
int main(void) {
	int revenue = 80; 	// as of 2016
	int cost = 50;
	int roi; 			// return on investment in percent
	roi = (100 * (revenue - cost)) / cost; // formula from accounting book
	if (roi >= 0) { 	// we don't care about negative roi
		printf ("%d\n", roi);
	}
	return 0;
}
