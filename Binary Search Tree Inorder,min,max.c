#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

/* Insert in BST */
struct node* insert(struct node *root, int x) {
    if (root == NULL) {
        struct node *new = (struct node*)malloc(sizeof(struct node));
        new->data = x;
        new->left = new->right = NULL;
        return new;
    }
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

/* Inorder Traversal */
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Find minimum */
void findMin(struct node *root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    while (root->left != NULL)
        root = root->left;
    printf("Minimum element: %d\n", root->data);
}

/* Find maximum */
void findMax(struct node *root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    while (root->right != NULL)
        root = root->right;
    printf("Maximum element: %d\n", root->data);
}

/* Main */
int main() {
    struct node *root = NULL;
    int ch, x;

    while (1) {
        printf("\n1.Insert\n2.Inorder\n3.Find Min\n4.Find Max\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            root = insert(root, x);
        }
        else if (ch == 2)
            inorder(root);
        else if (ch == 3)
            findMin(root);
        else if (ch == 4)
            findMax(root);
        else
            break;
    }
    return 0;
}
