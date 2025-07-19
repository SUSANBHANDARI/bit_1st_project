#include <stdio.h>
#include<string.h>
#include<stdlib.h>
/*
0+1=1
1+1=2
2+1=3
3+1=4
4+1=5
5+1=6
6+1=7,
7+1=8,
8+1=9,19-10=9
9+1=10,99+1=001
*/
int main() 
{
	char a[10]="0",b[10];
	char add='1',car=0;
	int i,j=0,cou=0;
	for(i=0;i<=199;i++)
	{
		top:
		if(a[cou]!='9')
		{
			a[cou]=a[cou]+add-48+car;
			car='0'-'0';
			add='1';
		}
		else if(a[cou]=='9')
		{
			car='1';
			a[cou]='0';
			cou++;
			if(a[cou]=='\0')
			{
				a[cou]='0';
				a[cou+1]='\0';
			}
			add='0'-'0';
			goto top;
		}	
		cou=0;
		strcpy(b,a);
		strrev(b);	
		printf("\n%s",b);
	}
	return 0;
}


