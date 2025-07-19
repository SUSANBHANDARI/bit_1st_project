//#include <stdio.h>
//#include <conio.h>
//
//int main() {
//    int ch;
//        ch = getch();  // Reads key instantly without waiting for Enter
//        if (ch == 0 || ch == 224) { // Arrow keys send two codes
//            ch = getch();          // Read the second part
//            if (ch == 77) {        // 75 is the code for Left Arrow
//                printf("?? Left arrow key pressed!\n");
//            }
//        }
//    return 0;
//}

#include <stdio.h>
#include <conio.h>

int main() {
    int ch;
    while(1)
    {
    	ch=getch();
    	if(ch == 0 || ch == 224)
    	{
    		ch=getch();
    		if(ch == 75)
    		{
   		 		printf("L\n");
			}
			else if(ch==77)
			{
				printf("R\n");
			}
		}
	}
    
	return 0;
}
