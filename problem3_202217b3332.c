#include <stdio.h>

// Declare the stack array, choice variable, stack size, top variable, and a temporary variable x
int stack[100], choice, n, top, x, i;

// Function prototypes
void push(void);
void pop(void);
void display(void);

int main() {
    // Initialize the top of the stack to -1 (indicating an empty stack)
    top = -1;

    // Ask the user for the size of the stack (up to 100)
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d", &n);

    // Display the menu for stack operations
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");

    // Loop to continuously take the user's choice and perform the corresponding stack operation
    do {
        printf("\n Enter the Choice:");
        scanf("%d", &choice);

        // Perform the operation based on the user's choice
        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\t EXIT POINT ");
                break;
            default:
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
        }
    } while(choice != 4);

    return 0;
}

// Function to push an element onto the stack
void push() {
    if(top >= n - 1) {
        // Check if the stack is full
        printf("\n\tSTACK is overflow");
    } else {
        // Push the element onto the stack
        printf(" Enter a value to be pushed:");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

// Function to pop an element from the stack
void pop() {
    if(top <= -1) {
        // Check if the stack is empty
        printf("\n\t Stack is underflow");
    } else {
        // Pop the element from the stack
        printf("\n\t The popped element is %d", stack[top]);
        top--;
    }
}

// Function to display the elements in the stack
void display() {
    if(top >= 0) {
        // Display the stack elements from top to bottom
        printf("\n The elements in STACK \n");
        for(i = top; i >= 0; i--) {
            printf("\n%d", stack[i]);
        }
        printf("\n Press Next Choice");
    } else {
        // Indicate that the stack is empty
        printf("\n The STACK is empty");
    }
}
