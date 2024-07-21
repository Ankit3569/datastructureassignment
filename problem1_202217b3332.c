#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 20 // Increased to ensure sufficient space

/* Function prototypes */
void create();
void insert();
void deletion();
void search();
void display();

/* Global variables */
int b[MAX], n, pos, e, i;

void main() {
    int ch;
    char g = 'y';

    do {
        printf("\n Main Menu");
        printf("\n 1. Create \n 2. Delete \n 3. Search \n 4. Insert \n 5. Display\n 6. Exit \n");
        printf("\n Enter your Choice: ");
        scanf("%d", &ch);

        /* The following switch will call the appropriate choice provided by the user */
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf(" \n Enter the correct choice:");
        }
        printf("\n Do you want to continue (y/n)?: ");
        scanf(" %c", &g);
    } while (g == 'y' || g == 'Y');

    getch();
}

void create() {
    printf("\n Enter the number of nodes: ");
    scanf("%d", &n);

    /* The loop should run till we get the ‘n’ inputs */
    for (i = 0; i < n; i++) {
        printf("\n Enter Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    printf("\n Enter the position you want to delete: ");
    scanf("%d", &pos);

    if (pos >= n) {
        printf("\n Invalid Location.");
    } else {
        for (i = pos; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;
    }

    printf("\n The Elements after deletion:");
    for (i = 0; i < n; i++) {
        printf("\t%d", b[i]);
    }
}

void search() {
    int found = 0;
    printf("\n Enter the Element to be searched: ");
    scanf("%d", &e);

    for (i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Value is in the %d Position\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Value %d is not in the list.\n", e);
    }
}

void insert() {
    printf("\n Enter the position you need to insert: ");
    scanf("%d", &pos);

    if (pos > n || pos < 0 || n >= MAX) {
        printf("\n Invalid Location.");
    } else {
        for (i = n; i > pos; i--) {
            b[i] = b[i - 1];
        }

        printf("\n Enter the element to insert: ");
        scanf("%d", &e);
        b[pos] = e;
        n++;
    }

    printf("\n The list after insertion:");
    display();
}

void display() {
    printf("\n The Elements of the list ADT are:");
    for (i = 0; i < n; i++) {
        printf("\n%d", b[i]);
    }
}
