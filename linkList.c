#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node* head = NULL;

void insert(int num) {
    struct node * temp = malloc(sizeof(struct node));
    temp->data = num;
    temp->next=NULL;

    
    if(head==NULL) {
        head=temp;
        return;
    }
    struct node* current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = temp;

}

void traverse(struct node * begginging)
{
    struct node* current = begginging;

    while(current != NULL) {
        printf("%d --->", current->data);
        current=current->next;
    }
};

void delete(int x) {
    struct node * current = head;
    struct node * prev = NULL;
    while(current->data!=x) {
        prev = current;
        current = current->next;
    }
    if(current==NULL) {
        return;
    }
    if(prev == NULL) {
        head=current->next;
    }
    prev->next = current->next;
    free(current);
}



int main() {
    insert(10);
    insert(20);
    insert(30);
    traverse(head);
    delete(20);
    printf("\n-------------------------------\n");
    traverse(head);
    return 0;
}