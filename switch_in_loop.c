//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int ch;
//	while(1)
//	{
//	printf("Enter ch\n1. and 2.\n");
//	fflush(stdin);
//	scanf("%d",&ch);
//	{
//		switch(ch)
//		{
//		case 1:
//			system("CLS");
//			printf("one\n");
//			break;
//		case 2:
//			printf("two\n");
//			break;
//		default:
//			printf("default\n");
//		}
//	}
//	}
//}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int ch,a;

    while (1) {
    	system("CLS");
        printf("\nEnter your choice:\n");
        printf("1. Clear screen and display 'one'\n");
        printf("2. Display 'two'\n");
        printf("0. Exit program\n");
        printf("Choice: ");
        scanf("%d", &ch);
        fflush(stdin);
        switch (ch) {
            case 1:
                system("CLS"); // For Windows
                printf("one\n");
                getchar();
				break;
            case 2:
                printf("two\n");
                getchar();
                break;
//            case 0:
//                printf("Exiting...\n");
//                exit(0); // Ends the program
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

