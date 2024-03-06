#include <stdio.h>

int main(void)
{
	int x = 0;
	int y = 0;
	y = (x ? 10 : 6); /* The parentheses are technically not necessary as assignment
	has a lower precedence than the conditional operator, but
	it's there for clarity. */
	printf("%d \n", y);
	return 0;
}

