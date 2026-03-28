#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int hd;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    newnode->hd = 0;
    return newnode;
}

void verticalOrder(struct node* root)
{
    if(root == NULL)
        return;

    struct node* queue[200];
    int front = 0, rear = 0;

    int map[200][200];
    int count[200] = {0};

    int offset = 100;

    queue[rear++] = root;

    while(front < rear)
    {
        struct node* temp = queue[front++];
        int hd = temp->hd + offset;

        map[hd][count[hd]++] = temp->data;

        if(temp->left)
        {
            temp->left->hd = temp->hd - 1;
            queue[rear++] = temp->left;
        }

        if(temp->right)
        {
            temp->right->hd = temp->hd + 1;
            queue[rear++] = temp->right;
        }
    }

    for(int i = 0; i < 200; i++)
    {
        if(count[i] > 0)
        {
            for(int j = 0; j < count[i]; j++)
                printf("%d ", map[i][j]);
            printf("\n");
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[100];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* nodes[100];

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    for(int i = 0; i < n; i++)
    {
        if(nodes[i] != NULL)
        {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];

            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    verticalOrder(nodes[0]);

    return 0;
}
