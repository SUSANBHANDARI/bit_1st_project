//ASCII VALUE of '*' = 42
//#include <stdio.h>
//#include <conio.h>
//
//int main() {
//    char str[100];
//    int index = 0;
//    char ch;
//
//    printf("Type something! Press 'Backspace' to delete, 'y' to submit and exit:\n");
//
//    while (1) {
//        ch = getch();  // read a character without waiting for Enter
//
//        if (ch == 'y' || ch == 'Y') {
//            str[index] = '\0';  // terminate the string
//            printf("\nFinal input: %s\n", str);
//            break;
//        } else if (ch == '\b') {  // handle backspace
//            if (index > 0) {
//                index--;
//                printf("\b \b"); // erase last character from console
//            }
//        } else if (index < sizeof(str) - 1) {
//            str[index++] = ch;
//            putchar(ch);  // display typed character
//        }
//    }
//
//    return 0;
//}

#include <stdio.h>
#include <conio.h>//for getch() and for putch()
#include <string.h>

int main() {
    char p[20];          // Input buffer
    int len = 0;         // Current length of text
    int cursor = 0;      // Cursor position
    int i,a;
    printf("Press Enter to finish:\n");
    while (1) {
        a = getch(); // First getch()

   if (a == 0 || a == 224) {
    a = getch(); // Second getch() for extended key

    if (a == 75 && cursor > 0) {         // Left arrow
        printf("\b");                    // Moves cursor back
        cursor--;
    }
    else if (a == 77 && cursor < len) {  // Right arrow
        putch(p[cursor]);                // Moves forward visually
        cursor++;
    }

    continue; // Skip rest of the loop for arrow keys
}

        // Enter key ends input
        if (a == 13) 
		{
            break;
        }

        // Backspace
        else if (a == 8 && cursor > 0) 
		{
            cursor--;
            len--;
            for (i = cursor; i < len; i++) 
			{
                p[i] = p[i+1];
            }

            printf("\b");
            for (i = cursor; i < len; i++) 
			{
                putch(p[i]);
            }
            printf(" \b");

            for (i = len; i > cursor; i--) 
			{
                printf("\b");
            }
        }

        // Regular printable characters
        else if (a >= 32 && a <= 126 && len < 19) 
		{
            for (i = len; i > cursor; i--) 
			{
                p[i] = p[i-1];
            }

            p[cursor] = a;
            len++;

            for (i = cursor; i < len; i++) 
			{
                putch(p[i]);
            }

            for (i = len; i > cursor + 1; i--) 
			{
                printf("\b");
            }

            cursor++;
        }
    }

    p[len] = '\0'; // Null-terminate string
    printf("\nPassword is: %s\n", p);

    return 0;
}
