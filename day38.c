#include <stdio.h>
#include <string.h>

int deque[100];
int front = -1, rear = -1;

void push_front(int x)
{
    if(front == -1)
    {
        front = rear = 0;
        deque[front] = x;
    }
    else if(front > 0)
    {
        deque[--front] = x;
    }
}

void push_back(int x)
{
    if(front == -1)
    {
        front = rear = 0;
        deque[rear] = x;
    }
    else
    {
        deque[++rear] = x;
    }
}

void pop_front()
{
    if(front == -1)
        return;

    if(front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back()
{
    if(front == -1)
        return;

    if(front == rear)
        front = rear = -1;
    else
        rear--;
}

void display()
{
    if(front == -1)
        return;

    for(int i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    printf("\n");
}

void reverse()
{
    int i = front, j = rear, temp;
    while(i < j)
    {
        temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

void sort()
{
    int i, j, temp;
    for(i = front; i <= rear; i++)
    {
        for(j = i + 1; j <= rear; j++)
        {
            if(deque[i] > deque[j])
            {
                temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
        }
    }
}

int size()
{
    if(front == -1)
        return 0;
    return rear - front + 1;
}

int empty()
{
    if(front == -1)
        return 1;
    return 0;
}

int main()
{
    int n, x;
    char op[20];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op,"push_front")==0)
        {
            scanf("%d",&x);
            push_front(x);
        }
        else if(strcmp(op,"push_back")==0)
        {
            scanf("%d",&x);
            push_back(x);
        }
        else if(strcmp(op,"pop_front")==0)
            pop_front();

        else if(strcmp(op,"pop_back")==0)
            pop_back();

        else if(strcmp(op,"front")==0)
        {
            if(!empty())
                printf("%d\n", deque[front]);
            else
                printf("-1\n");
        }

        else if(strcmp(op,"back")==0)
        {
            if(!empty())
                printf("%d\n", deque[rear]);
            else
                printf("-1\n");
        }

        else if(strcmp(op,"size")==0)
            printf("%d\n", size());

        else if(strcmp(op,"empty")==0)
            printf("%d\n", empty());

        else if(strcmp(op,"reverse")==0)
            reverse();

        else if(strcmp(op,"sort")==0)
            sort();

        else if(strcmp(op,"display")==0)
            display();
    }

    display();

    return 0;
}
