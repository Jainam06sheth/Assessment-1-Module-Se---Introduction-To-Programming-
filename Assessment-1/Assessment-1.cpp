#include <stdio.h>

// ===== FUNCTION DECLARATIONS =====
void displayMenu();
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
void waitForKey();
void flushInput();

// ===== MAIN FUNCTION =====
int main() {
    int choice;
    float a, b, result;
    int totalCalculations = 5;  

    // Print menu once before loop
    displayMenu();

    for (int i = 0; i < totalCalculations; i++) {
        printf("\nEnter Your choice : ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            flushInput();
            waitForKey();
            displayMenu();  // Reprint menu
            continue;
        }

        if (choice < 1 || choice > 4) {
            printf("Invalid choice !!!!\n");
            waitForKey();
            displayMenu();  // Reprint menu
            continue;
        }

        printf("Enter first number : ");
        if (scanf("%f", &a) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            flushInput();
            waitForKey();
            displayMenu();  // Reprint menu
            continue;
        }

        printf("Enter second number : ");
        if (scanf("%f", &b) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            flushInput();
            waitForKey();
            displayMenu();  // Reprint menu
            continue;
        }

        // Perform selected operation
        switch (choice) {
            case 1:
                result = add(a, b);
                printf("Addition = %.2f\n", result);
                break;
            case 2:
                result = subtract(a, b);
                printf("Subtraction = %.2f\n", result);
                break;
            case 3:
                result = multiply(a, b);
                printf("Multiplication = %.2f\n", result);
                break;
            case 4:
                if (b != 0) {
                    result = divide(a, b);
                    printf("Division = %.2f\n", result);
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;
        }

        waitForKey();
        displayMenu();  // Reprint menu after each calculation
    }

    return 0;
}

// ===== FUNCTION DEFINITIONS =====

void displayMenu() {
    printf("\nMENU\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
}

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}

void flushInput() {
    char temp;
    while (scanf("%c", &temp) == 1 && temp != '\n');
}

void waitForKey() {
    char temp;
    printf("Press any key to continue...");
    fflush(stdout);
    flushInput();
    scanf("%c", &temp);
}
