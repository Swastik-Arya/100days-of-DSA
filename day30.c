#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef;
    int exp;
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
        scanf("%d %d",&newnode->coef,&newnode->exp);
        newnode->next=NULL;

        if(head==NULL)
            head=temp=newnode;
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }

    temp=head;

    while(temp!=NULL)
    {
        if(temp->exp==0)
            printf("%d",temp->coef);
        else if(temp->exp==1)
            printf("%dx",temp->coef);
        else
            printf("%dx^%d",temp->coef,temp->exp);

        if(temp->next!=NULL)
            printf(" + ");

        temp=temp->next;
    }

    return 0;
}
