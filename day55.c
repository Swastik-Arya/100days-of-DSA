#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void rightView(struct node* root)
{
    if(root == NULL)
        return;

    struct node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear)
    {
        int size = rear - front;

        for(int i = 0; i < size; i++)
        {
            struct node* temp = queue[front++];

            if(i == size - 1)
                printf("%d ", temp->data);

            if(temp->left)
                queue[rear++] = temp->left;

            if(temp->right)
                queue[rear++] = temp->right;
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

    rightView(nodes[0]);

    return 0;
}
