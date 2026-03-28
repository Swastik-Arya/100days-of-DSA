#include <stdio.h>

int main()
{
    int queue[100], stack[100];
    int front = 0, rear = -1, top = -1;
    int n, i;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &queue[++rear]);
    }

    while(front <= rear)
    {
        stack[++top] = queue[front++];
    }

    front = 0;
    rear = -1;

    while(top != -1)
    {
        queue[++rear] = stack[top--];
    }

    for(i = 0; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}
