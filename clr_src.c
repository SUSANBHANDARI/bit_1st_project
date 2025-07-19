#include <stdio.h>

// Clears the console screen using ANSI escape codes
void clear_screen() 
{
    printf("\e[1;1H\e[2J");
}

// Dummy member update function
void mem_upd(int n){
    printf("Updating member #%d...\n", n);
    // simulate update work
    printf("Member updated successfully!\n");
}

int main()
{
    int mem_ch;
    int n=1;
    while (1) {
        clear_screen(); // Clear before showing menu

        printf("===== MEMBER MENU =====\n");
        printf("1. MEMBER UPDATE\n");
        printf("2. EXIT\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &mem_ch) != 1) {
            printf("Invalid input. Exiting...\n");
            break;
        }

        // Flush leftover input
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);

        switch (mem_ch) {
            case 1:
                clear_screen();
                mem_upd(n);
                printf("\nPress Enter to return to menu...");
                getchar(); // wait for user to press Enter
                break;
            case 2:
                printf("Exiting...\n");
                return;
            default:
                printf("Please enter 1 or 2.\n");
                printf("Press Enter to continue...");
                getchar();
        }
    }
}

