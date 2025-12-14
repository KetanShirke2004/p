#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

/* Create / Insert in BST */
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

/* Inorder */
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Preorder */
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Postorder */
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* Search in BST */
void search(struct node *root, int key) {
    if (root == NULL) {
        printf("Element not found\n");
        return;
    }
    if (root->data == key) {
        printf("Element found\n");
        return;
    }
    if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

/* Main */
int main() {
    struct node *root = NULL;
    int ch, x;

    while (1) {
        printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Exit\n");
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
            preorder(root);
        else if (ch == 4)
            postorder(root);
        else if (ch == 5) {
            printf("Enter value to search: ");
            scanf("%d", &x);
            search(root, x);
        }
        else
            break;
    }
    return 0;
}
