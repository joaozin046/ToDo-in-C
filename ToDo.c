#include <stdio.h>
#include <stdlib.h>

typedef struct ToDo {
    char data[100];
    struct ToDo* link;
    int count;
} todo;

todo* start = NULL;

void welcomeUser();
void seeToDo();
void createToDo();
void delToDo();
void updateToDo();

int main() {
    int choice;
    welcomeUser();

    while (1) {
        printf("\n1. See Your ToDo List\n");
        printf("2. Create Your ToDos\n");
        printf("3. Delete Your ToDos\n");
        printf("4. Update Your ToDos\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                seeToDo();
                break;
            case 2:
                createToDo();
                break;
            case 3:
                delToDo();
                break;
            case 4:
                updateToDo();
                break;
            case 5:
                exit(0);
        }
    }
}

void welcomeUser() {
    printf("\n\n\n\n\n");
    printf("\t--------------------------------------------------\n\n");
    printf("\t############ YOUR TODO LIST APP ############\n\n");
    printf("\t--------------------------------------------------\n\n");
    printf("\n\n\n\t\tWelcome!\n\n");
}

void seeToDo() {
    system("clear"); // Use system-specific commands for clearing the screen
    todo* temp = start;

    if (start == NULL) {
        printf("\nEmpty TODO\n\n");
    }

    while (temp != NULL) {
        printf("%d) %s\n", temp->count, temp->data);
        temp = temp->link;
    }

    printf("\n\n");
}

void createToDo() {
    char k;
    todo* t;
    todo* temp;
    system("clear");

    while (1) {
        printf("Want to add? (y/n): ");
        fflush(stdin);
        scanf(" %c", &k);

        if (k == 'n') {
            break;
        } else {
            temp = (todo*)malloc(sizeof(todo));
            printf("Enter your TODO: ");
            fflush(stdin);
            fgets(temp->data,sizeof(temp->data), stdin);
            temp->count = 1;

            if (start == NULL) {
                start = temp;
                start->link = NULL;
            } else {
                t = start;
                while (t->link != NULL) {
                    t = t->link;
                }
                t->link = temp;
                temp->link = NULL;
            }
            fixcount();
        }
    }
}

void delToDo() {
    system("clear");
    int d;
    todo* temp1 = start;
    todo* temp = start->link;

    printf("Enter the number of the TODO you want to remove: ");
    scanf("%d", &d);

    if (temp1->count == d) {
        start = start->link;
        free(temp1);
        fixcount();
        return;
    }

    while (temp != NULL) {
        if (temp->count == d) {
            temp1->link = temp->link;
            free(temp);
            fixcount();
            return;
        } else {
            temp1 = temp;
            temp = temp->link;
        }
    }
}

void fixcount() {
    todo* temp = start;
    int i = 1;

    while (temp != NULL) {
        temp->count = i;
        i++;
        temp = temp->link;
    }
}

void updateToDo() {
    system("clear");
    todo* temp;
    todo* t;
    char k;

    while (1) {
        printf("Want to add? (y/n): ");
        fflush(stdin);
        scanf(" %c", &k);

        if (k == 'n') {
            break;
        }

        temp = (todo*)malloc(sizeof(todo));
        printf("Enter your TODO: ");
        fflush(stdin);
        fgets(temp->data,sizeof(temp->data), stdin);
        temp->link = NULL;

        t = start;

        while (t->link != NULL) {
            t = t->link;
        }

        t->link = temp;
        fixcount();
    }

    printf("\n\n");
}
