#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head1=NULL,*head2=NULL,*temp,*newnode;
    int n,m,i,len1=0,len2=0,diff;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head1==NULL)
            head1=temp=newnode;
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }

    scanf("%d",&m);

    for(i=0;i<m;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head2==NULL)
            head2=temp=newnode;
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }

    temp=head1;
    while(temp!=NULL)
    {
        len1++;
        temp=temp->next;
    }

    temp=head2;
    while(temp!=NULL)
    {
        len2++;
        temp=temp->next;
    }

    struct node *p=head1;
    struct node *q=head2;

    if(len1>len2)
    {
        diff=len1-len2;
        for(i=0;i<diff;i++)
            p=p->next;
    }
    else
    {
        diff=len2-len1;
        for(i=0;i<diff;i++)
            q=q->next;
    }

    while(p!=NULL && q!=NULL)
    {
        if(p->data==q->data)
        {
            printf("%d",p->data);
            return 0;
        }
        p=p->next;
        q=q->next;
    }

    printf("No Intersection");

    return 0;
}
