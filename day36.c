#include <stdio.h>

int main()
{
    int q[100], front = 0, rear = -1;
    int n, m, i;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &q[++rear]);
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        front = (front + 1) % n;
    }

    for(i = 0; i < n; i++)
    {
        printf("%d ", q[(front + i) % n]);
    }

    return 0;
}
