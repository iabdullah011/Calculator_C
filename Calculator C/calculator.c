#include <stdio.h>
#include <math.h>
#include <string.h>

// Structure to store history
typedef struct {
    char name[50];
    double result;
} Operation;

// Function prototypes
void showMenu();
void performBasicOperation();
void performTrigonometricOperation();
void performPowerOperation(double *base, double *exponent);
void displayResults(double *result);
void displayHistory(Operation history[], int count);

int main() {
    char choice[10];
    Operation history[100];
    int historyCount = 0;

    printf("Welcome to the C Calculator!\n");

    do {
        showMenu();
        printf("Enter your choice (or 'exit' to quit): ");
        scanf("%s", choice);

        if (strcmp(choice, "basic") == 0) {
            performBasicOperation();
        } else if (strcmp(choice, "trig") == 0) {
            performTrigonometricOperation();
        } else if (strcmp(choice, "power") == 0) {
            double base, exponent, result;
            printf("Enter base: ");
            scanf("%lf", &base);
            printf("Enter exponent: ");
            scanf("%lf", &exponent);
            performPowerOperation(&base, &exponent);
            result = pow(base, exponent);
            displayResults(&result);

            // Store result in history
            strcpy(history[historyCount].name, "Power Calculation");
            history[historyCount].result = result;
            historyCount++;
        } else if (strcmp(choice, "history") == 0) {
            displayHistory(history, historyCount);
        } else if (strcmp(choice, "exit") != 0) {
            printf("Invalid choice, please try again.\n");
        }
    } while (strcmp(choice, "exit") != 0);

    printf("Thank you for using the calculator. Goodbye!\n");
    return 0;
}

// Display the menu
void showMenu() {
    printf("\n===== Calculator Menu =====\n");
    printf("Type 'basic'   - Perform basic operations (+, -, *, /).\n");
    printf("Type 'trig'    - Perform trigonometric calculations (sin, cos, tan).\n");
    printf("Type 'power'   - Perform power calculations.\n");
    printf("Type 'history' - View calculation history.\n");
    printf("Type 'exit'    - Quit the program.\n");
    printf("===========================\n");
}

// Perform basic arithmetic operations
void performBasicOperation() {
    double num1, num2, result;
    char op;

    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op); // Space before %c to handle newline character
    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0)
                result = num1 / num2;
            else {
                printf("Error: Division by zero is not allowed.\n");
                return;
            }
            break;
        default:
            printf("Invalid operator.\n");
            return;
    }
    printf("Result: %.2lf\n", result);
}

// Perform trigonometric operations
void performTrigonometricOperation() {
    double angle, result;
    char trigFunc[10];

    printf("Enter trigonometric function (sin, cos, tan): ");
    scanf("%s", trigFunc);
    printf("Enter angle in degrees: ");
    scanf("%lf", &angle);

    double radians = angle * M_PI / 180.0; // Convert to radians

    if (strcmp(trigFunc, "sin") == 0) {
        result = sin(radians);
    } else if (strcmp(trigFunc, "cos") == 0) {
        result = cos(radians);
    } else if (strcmp(trigFunc, "tan") == 0) {
        result = tan(radians);
    } else {
        printf("Invalid trigonometric function.\n");
        return;
    }
    printf("Result: %.2lf\n", result);
}

// Perform power operation using pointers
void performPowerOperation(double *base, double *exponent) {
    printf("Base: %.2lf, Exponent: %.2lf\n", *base, *exponent);
}

// Display results using pointers
void displayResults(double *result) {
    printf("The result is: %.2lf\n", *result);
}

// Display calculation history
void displayHistory(Operation history[], int count) {
    if (count == 0) {
        printf("No history available.\n");
        return;
    }
    printf("\nCalculation History:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2lf\n", history[i].name, history[i].result);
    }
}
