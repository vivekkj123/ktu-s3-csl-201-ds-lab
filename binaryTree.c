#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(struct node** root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }

    if (data <= (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

struct node* find_min(struct node* root) {
    if (root->left == NULL) {
        return root;
    }
    return find_min(root->left);
}

void delete(struct node** root, int data) {
    if (*root == NULL) {
        return;
    }

    if (data < (*root)->data) {
        delete(&(*root)->left, data);
    } else if (data > (*root)->data) {
        delete(&(*root)->right, data);
    } else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else if ((*root)->left == NULL) {
            struct node* temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            struct node* temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            struct node* temp = find_min((*root)->right);
            (*root)->data = temp->data;
            delete(&(*root)->right, temp->data);
        }
    }
}

void inorder_traversal(struct node* root) {
    if (root == NULL) {
        return;
    }

    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

int main() {
    struct node* root = NULL;
    int n, i, x;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &x);
        insert(&root, x);
    }

    printf("In-order traversal before deletion:\n");
    inorder_traversal(root);
    printf("\n");

    printf("Enter the number of elements to be deleted: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &x);
        delete(&root, x);
    }

    printf("In-order traversal after deletion:\n");
    inorder_traversal(root);
    printf("\n");

    return 0;
}
