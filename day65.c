#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node* next;
};

struct node* adj[100];
int visited[100];

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

int dfs(int v, int parent)
{
    visited[v] = 1;

    struct node* temp = adj[v];
    while(temp)
    {
        int u = temp->vertex;

        if(!visited[u])
        {
            if(dfs(u, v))
                return 1;
        }
        else if(u != parent)
        {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

int main()
{
    int n, m;
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

    int hasCycle = 0;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            if(dfs(i, -1))
            {
                hasCycle = 1;
                break;
            }
        }
    }

    if(hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}
