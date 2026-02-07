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

void insert(int x, int flag)
{
    struct node *current = head; // start point

    // creating temp value to assign
    struct node *temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }

    if (flag == 0)
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
        temp->prev = current;
    }
    else
    {
        struct node *prev = NULL;

        while (current != NULL && current->data != flag)
        {
            prev = current;
            current = current->next;
        }

        temp->next = current->next;
        temp->prev = current;
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