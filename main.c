#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100

typedef struct {
    char description[100];
    int done;

} Task;

Task tasks[MAX_TASKS];
int numTasks = 0;
int taskIndex = 0;


void add_task() {
    if (numTasks == MAX_TASKS) {
        printf("Tasks List is full.\n");
        return;
    }

    printf("Enter new task : ");
    fgets(tasks[numTasks].description, sizeof(tasks[numTasks].description), stdin);
    tasks[numTasks].description[strcspn(tasks[numTasks].description, "\n")] = '\0';
    tasks[numTasks].done = 0;
    numTasks++;

    printf("Task succesfully added.\n");
}

void mark_done() {
    printf("Enter task number (starts from 0): ");
    scanf("%d", &taskIndex);
    getchar();

    if (taskIndex >= 0 && taskIndex < numTasks) {
        tasks[taskIndex].done = 1;
        printf("Task marked as done.\n");

    } else {
        printf("Wrong number.\n");
    }

    while (getchar() != '\n');
}

void list_all_tasks() {
    char task_num;
    printf("Tasks List :\n");
    for (int i = 0; i < numTasks; i++) {
        if(tasks[i].done == 1){
            printf("%d : %s  done\n", i, tasks[i].description);

        }
        else{
        printf("%d : %s\n", i, tasks[i].description);
    }}
}

void list_remaining_tasks() {
    printf("List of remaining Tasks :\n");
    for (int i = 0; i < numTasks; i++) {
        if (!tasks[i].done) {
            printf("%d : %s\n", i, tasks[i].description);
        }
    }
}

void list_completed_tasks() {
    printf("List of ended tasks :\n");
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].done) {
            printf("%d : %s\n", i, tasks[i].description);
        }
    }
}

void show_menu() {
    printf("\nMenu :\n");
    printf("1. Add a Task\n");
    printf("2. Mark Task as done\n");
    printf("3. List of every tasks\n");
    printf("4. List of remaining tasks\n");
    printf("5. List of ended tasks\n");
    printf("0. Leave\n");
}

int main() {
    int choice;

    while (1) {
        show_menu();
        printf("Enter a choice between 0 and 5 : ");
        scanf("%d", &choice);

        while (getchar() != '\n');

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                mark_done();
                break;
            case 3:
                list_all_tasks();
                break;
            case 4:
                list_remaining_tasks();
                break;
            case 5:
                list_completed_tasks();
                break;
            case 6:
                printf("Ciao !\n");
                exit(0);
            default:
                printf("Invalidated choice !\n Try again !\n");
        }
    }

    return 0;
}
