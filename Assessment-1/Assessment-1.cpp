#include <stdio.h>

// ===== FUNCTION DECLARATIONS =====
void displayMenu();
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
void waitForKey();

// ===== MAIN FUNCTION =====
int main() {
    int choice;
    float a, b, result;
    int invalidAttempts = 0;

    while (1) {
        displayMenu();

        // Menu choice validation
        printf("\nEnter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Only numbers are allowed.\n");
            scanf("%c"); scanf("%c");  // Flush invalid input
            invalidAttempts++;
            waitForKey();
            if (invalidAttempts >= 5) break;
            continue;
        }

        if (choice < 1 || choice > 5) {
            printf("Invalid input! Please enter a number between 1 and 5.\n");
            invalidAttempts++;
            waitForKey();
            if (invalidAttempts >= 5) break;
            continue;
        }

        if (choice == 5) {
            printf("Exiting the calculator. Thank you!\n");
            break;
        }

        // First number input
        printf("Enter first number: ");
        if (scanf("%f", &a) != 1) {
            printf("Invalid input! Only numbers are allowed.\n");
            scanf("%c"); scanf("%c");
            invalidAttempts++;
            waitForKey();
            if (invalidAttempts >= 5) break;
            continue;
        }

        // Second number input
        printf("Enter second number: ");
        if (scanf("%f", &b) != 1) {
            printf("Invalid input! Only numbers are allowed.\n");
            scanf("%c"); 
			scanf("%c");
            invalidAttempts++;
            waitForKey();
            if (invalidAttempts >= 5) break;
            continue;
        }

        // Perform operation
        switch (choice) 
		{
            case 1:result = add(a, b);
                printf("Result: %.2f + %.2f = %.2f\n", a, b, result);
                break;
            case 2:
                result = subtract(a, b);
                printf("Result: %.2f - %.2f = %.2f\n", a, b, result);
                break;
            case 3: result = multiply(a, b);
                printf("Result: %.2f * %.2f = %.2f\n", a, b, result);
                break;
            case 4:if (b != 0) 
					{
                    result = divide(a, b);
                    printf("Result: %.2f / %.2f = %.2f\n", a, b, result);
                	} 
					else 
					{
                    printf("Error: Division by zero is not allowed.\n");
                	}
                break;
        }

        waitForKey();  
    }

    printf("You have entered invalid inputs 5 times. Exiting the calculator.\n");
    return 0;
}

//FUNCTION DEFINITIONS 

void displayMenu() {
    printf("\n------ MENU DRIVEN CALCULATOR ------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
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

void waitForKey() {
    printf("Press Enter to continue...");
    fflush(stdout);
    scanf("%c"); 
    scanf("%c");  //wait for Enter
}

