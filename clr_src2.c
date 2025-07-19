
#include<stdio.h>
#include<stdlib.h>
int main()
{
	 int i, a;

    while (1) {
        system("CLS"); // Clear the console screen (works on Windows)
        printf("Hello world\n");

        printf("Enter two integers (negative to exit):\n");
        scanf("%d", &i);
        scanf("%d", &a);

        // Exit condition
        if (i < 0 || a < 0) {
            printf("Negative number detected. Exiting...\n");
            break;
        }

        // Process and display result
        printf("Sum of %d and %d is: %d\n", i, a, i + a);

        printf("Press Enter to continue...\n");
        getchar(); // Capture leftover newline
        getchar(); // Wait for Enter
    }

    return 0;
}
