#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "schedulers.h"
#include "list.h"
#include "cpu.h"

/* Shortest Job First scheduler
 * Looks at the cpu burst time and
 * sends the shortest jobs to the 
 * cpu first.
*/

struct node* head;

void add(char *name, int priority, int burst) {
    struct task* temp = malloc(sizeof(struct task));
    temp->name = name;
    temp->priority = priority;
    temp->burst = burst;
    insert(&head, temp);
}

void schedule() {
    // loop until list is empty
    while (head != NULL) {
        struct node* tempNode = head;
        struct task* tempTask = head->task;
        struct task* quickestTask = tempTask;

        // find the shortest job
        while (tempNode->next != NULL) {
            tempNode = tempNode->next;
            tempTask = tempNode->task;
            if (tempTask->burst < quickestTask->burst) {
                quickestTask = tempTask;
            }
        }

        // run the shortest job & remove from list
        run(quickestTask, quickestTask->burst);
        delete(&head, quickestTask);
    }
}
