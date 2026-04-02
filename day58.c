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

int search(int inorder[], int start, int end, int value)
{
    for(int i = start; i <= end; i++)
    {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

struct node* buildTree(int preorder[], int inorder[], int start, int end, int *preIndex)
{
    if(start > end)
        return NULL;

    struct node* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if(start == end)
        return root;

    int inIndex = search(inorder, start, end, root->data);

    root->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

void postorder(struct node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n;
    scanf("%d", &n);

    int preorder[100], inorder[100];

    for(int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;
    struct node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    postorder(root);

    return 0;
}
