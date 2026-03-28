#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head=NULL,*temp,*newnode;
    int n,i;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }

    temp->next=head;

    temp=head;

    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    while(temp!=head);

    return 0;
}
