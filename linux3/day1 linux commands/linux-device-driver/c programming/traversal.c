#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int a;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *insert()
{
    int data;
    printf("Enter Data [-1 for start inserting left or right]\n");
    scanf("%d", &data);
    if (data == -1)
        return NULL;

    struct Node *nn = (struct Node *)malloc(sizeof(struct Node));  // Corrected typecasting
    nn->a = data;
    printf("Enter Left Node Data\n");
    nn->left = insert();
    printf("Enter Right Node Data\n");
    nn->right = insert();
    return nn;
}

void preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->a);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->a);
    inorder(root->right);
}

void postorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->a);
}

int main()
{
    root = insert();
    printf("Printing the data in the list[preOrder Traversal]\n");
    preorder(root);

    printf("\nPrinting the data in the list[inOrder Traversal]\n");
    inorder(root);

    printf("\nPrinting the data in the list[postOrder Traversal]\n");
    postorder(root);

    return 0;
}
