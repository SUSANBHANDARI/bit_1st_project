#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int sw1();
int sw2();
int main()
{
	sw1();
}
int sw1()
{
	int ch;
	while(1)
	{
		system("CLS");
		printf("\nEnter choice\n1 ch\n2 exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				sw2();
				break;
			case 2:
				return 0;
				break;
			default:
				printf("\nchoice 1-2\n");
		}
	}
	
}

int sw2()
{
	int ch,a;
	while(1)
	{
		system("CLS");
		printf("\nEnter choice\n1 HW\n2 exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				system("CLS");
				printf("Hello world\n");
				scanf("%d",&a);
//				printf("%d\n",a);
				break;
			case 2:
				return 0;
				break;
			default:
				printf("\nchoice 1-2\n");
		}	
	}

}
