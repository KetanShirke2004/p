#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

/* Create / Insert node */
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

/* Find minimum value node */
struct node* minValueNode(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

/* Delete node from BST */
struct node* deleteNode(struct node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        /* Node found */
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        /* Node with two children */
        struct node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
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

/* Main */
int main() {
    struct node *root = NULL;
    int ch, x;

    while (1) {
        printf("\n1.Insert\n2.Inorder\n3.Delete\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            root = insert(root, x);
        }
        else if (ch == 2) {
            inorder(root);
        }
        else if (ch == 3) {
            printf("Enter value to delete: ");
            scanf("%d", &x);
            root = deleteNode(root, x);
        }
        else
            break;
    }
    return 0;
}
