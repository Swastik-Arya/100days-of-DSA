#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head=NULL,*temp,*newnode,*tail;
    int n,i,k,count=0;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL)
            head=temp=newnode;
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }

    scanf("%d",&k);

    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        count++;
    }

    count++;
    tail=temp;
    tail->next=head;

    k=k%count;
    int steps=count-k;

    temp=head;
    for(i=1;i<steps;i++)
        temp=temp->next;

    head=temp->next;
    temp->next=NULL;

    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}
