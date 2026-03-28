#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    struct node *temp;
    int value;

    if(top == NULL)
        return 0;

    temp = top;
    value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

int main()
{
    char postfix[100];
    int i = 0, a, b, result;

    fgets(postfix, sizeof(postfix), stdin);

    while(postfix[i] != '\0')
    {
        if(isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            b = pop();
            a = pop();

            if(postfix[i] == '+')
                result = a + b;
            else if(postfix[i] == '-')
                result = a - b;
            else if(postfix[i] == '*')
                result = a * b;
            else if(postfix[i] == '/')
                result = a / b;

            push(result);
        }
        i++;
    }

    printf("%d", pop());

    return 0;
}
