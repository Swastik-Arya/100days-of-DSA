#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

struct node* merge(struct node *head1, struct node *head2) {
    struct node *head = NULL, *temp = NULL;

    while(head1 != NULL && head2 != NULL) {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));

        if(head1->data < head2->data) {
            newnode->data = head1->data;
            head1 = head1->next;
        } else {
            newnode->data = head2->data;
            head2 = head2->next;
        }

        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    while(head1 != NULL) {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = head1->data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
        head1 = head1->next;
    }

    while(head2 != NULL) {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = head2->data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
        head2 = head2->next;
    }

    return head;
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct node *head1 = createList(n);

    scanf("%d", &m);
    struct node *head2 = createList(m);

    struct node *result = merge(head1, head2);

    while(result != NULL) {
        printf("%d ", result->data);
        result = result->next;
    }

    return 0;
}
