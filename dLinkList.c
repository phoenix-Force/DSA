#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int x, int flag) {
    struct node *current = head;

    struct node *temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }

    if (flag == 0) {   // insert at end
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
        temp->prev = current;   // 🔥 FIX HERE
    } 
    else {
        while (current != NULL && current->data != flag)
            current = current->next;

        if (current == NULL) {
            free(temp);
            return;
        }

        temp->next = current->next;
        temp->prev = current;

        if (current->next != NULL)
            current->next->prev = temp;

        current->next = temp;
    }
}


void traverse(int num, bool backward) {
    struct node *current = head;

    while (current != NULL && current->data != num)
        current = current->next;

    if (current == NULL) return;

    if (backward) {
        while (current != NULL) {
            printf("[%p, %d, %p] <=> ",
                   (void*)current->prev,
                   current->data,
                   (void*)current->next);
            current = current->prev;
        }
    } else {
        while (current != NULL) {
            printf("[%p, %d, %p] <=> ",
                   (void*)current->prev,
                   current->data,
                   (void*)current->next);
            current = current->next;
        }
    }
}


int main()
{

    insert(10, 0);
    insert(20, 0);
    insert(30, 0);
    insert(40, 0);
    traverse(10, false);
    printf("\n-------------------------------\n");
    insert(15, 10);
    insert(25, 20);
    traverse(10, false);
    printf("\n-------------------------------\n");
    traverse(40, true);
    return 0;
}