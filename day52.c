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

struct node* LCA(struct node* root, int n1, int n2)
{
    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    struct node* left = LCA(root->left, n1, n2);
    struct node* right = LCA(root->right, n1, n2);

    if(left && right)
        return root;

    if(left != NULL)
        return left;
    else
        return right;
}

int main()
{
    int n, i, n1, n2;
    scanf("%d", &n);

    int arr[100];
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* nodes[100];

    for(i = 0; i < n; i++)
    {
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    for(i = 0; i < n; i++)
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

    scanf("%d %d", &n1, &n2);

    struct node* result = LCA(nodes[0], n1, n2);

    if(result != NULL)
        printf("%d", result->data);

    return 0;
}
