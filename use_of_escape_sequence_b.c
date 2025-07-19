#include <stdio.h>

int main() {
	char a,p[15];
	int i=0;
	do
	{
		a=getch();
		if(a!='y'&&a!=8)
		{
			putchar(a);
			p[i]=a;
			i++;
		}
		else if(a==8)
		{
			i--;
			printf("\b");//use of "\b" move the cursor one character backward
			//printf("\b ");//use of "\b " move the cursor one character backward and replaces the backward character with space.
			               //After printing the space, the cursor moves forward again—so now it sits after the space.
		}
	}while(a!='y');
    return 0;
}
