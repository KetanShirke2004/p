#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

/* Create binary tree */
struct node* create() {
    int x;
    struct node *new;

    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    new = (struct node*)malloc(sizeof(struct node));
    new->data = x;

    printf("Enter left child of %d\n", x);
    new->left = create();

    printf("Enter right child of %d\n", x);
    new->right = create();

    return new;
}

/* Inorder Traversal */
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Preorder Traversal */
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Postorder Traversal */
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* Main */
int main() {
    struct node *root = NULL;
    int ch;

    while (1) {
        printf("\n1.Create Tree\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1)
            root = create();
        else if (ch == 2)
            inorder(root);
        else if (ch == 3)
            preorder(root);
        else if (ch == 4)
            postorder(root);
        else
            break;
    }
    return 0;
}
