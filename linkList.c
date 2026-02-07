#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
}

void traverse(struct node * head
{
    struct node* current = head;

    while(current != NULL) {
        printf("%d", current->data);
        current=current-> next;
    }
};
)


int main() {
    scruct node 
    return 0
}