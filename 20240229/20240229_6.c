#include <stdio.h>

static int j = 0;
float const xconst= 99.9;
#define yconst 88.8

void up(void)
{
	/* k is set to 0 when the program starts. The line is then "ignored"
	* for the rest of the program (i.e. k is not set to 0 every time up()
	* is called)
	*/
	static int k = 0;
	j++;
	k++;
	printf("up() called. k= %2d, j= %2d xconst= %2.2f yconst= %2.2f\n", k , j, xconst, yconst);
}
void down(void)
	{
	static int k = 0;
	j--;
	k--;
	printf("down() called. k= %2d, j= %2d\n", k , j);
}
int main(void){
	int i;
	/* call the up function 3 times, then the down function 2 times */
	for (i = 0; i < 3; i++)	up();
	for (i = 0; i < 2; i++)	down();
	
	return 0;
}
