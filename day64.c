#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node* next;
};

struct node* adj[100];
int visited[100];
int queue[100];

struct node* createNode(int v)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = NULL;
    return newnode;
}

void addEdge(int u, int v)
{
    struct node* newnode = createNode(v);
    newnode->next = adj[u];
    adj[u] = newnode;

    newnode = createNode(u);
    newnode->next = adj[v];
    adj[v] = newnode;
}

void bfs(int s)
{
    int front = 0, rear = 0;

    visited[s] = 1;
    queue[rear++] = s;

    while(front < rear)
    {
        int v = queue[front++];
        printf("%d ", v);

        struct node* temp = adj[v];
        while(temp)
        {
            if(!visited[temp->vertex])
            {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int n, m, s;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
    {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    scanf("%d", &s);

    bfs(s);

    return 0;
}
