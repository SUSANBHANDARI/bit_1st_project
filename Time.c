#include<stdio.h>
#include<string.h>
#include<time.h>
int main()
{
	char tm[50];
	strcpy(tm,__DATE__);
	printf("%s",tm);
}
