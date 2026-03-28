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

struct node* insert(struct node* root, int data)
{
    if(root == NULL)
        return createNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

struct node* LCA(struct node* root, int n1, int n2)
{
    if(root == NULL)
        return NULL;

    if(n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);

    if(n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);

    return root;
}

int main()
{
    struct node* root = NULL;
    int n, i, x, n1, n2;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d %d", &n1, &n2);

    struct node* result = LCA(root, n1, n2);

    if(result != NULL)
        printf("%d", result->data);

    return 0;
}
