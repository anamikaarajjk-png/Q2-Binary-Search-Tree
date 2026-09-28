#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int bstSearch(struct Node* root, int key, int *comparisons) {
    while (root != NULL) {
        (*comparisons)++;

        if (key == root->data)
            return 1;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return 0;
}

int linearSearch(int arr[], int n, int key, int *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++;

        if (arr[i] == key)
            return 1;
    }
    return 0;
}

int main() {
    int arr[] = {45, 20, 60, 10, 30, 50, 70, 25, 55};
    int n = 9;

    struct Node* root = NULL;

    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    printf("BST Traversals\n\n");

    printf("Inorder   : ");
    inorder(root);

    printf("\nPreorder  : ");
    preorder(root);

    printf("\nPostorder : ");
    postorder(root);

    printf("\n\nSearch Results\n");

    int keys[] = {25, 55, 90};

    for (int i = 0; i < 3; i++) {
        int key = keys[i];
        int bstComp = 0;
        int linearComp = 0;

        int bstResult = bstSearch(root, key, &bstComp);
        int linearResult = linearSearch(arr, n, key, &linearComp);

        printf("\nKey = %d\n", key);

        printf("BST Search       : %s\n", bstResult ? "Found" : "Not Found");
        printf("BST Comparisons  : %d\n", bstComp);

        printf("Linear Search    : %s\n", linearResult ? "Found" : "Not Found");
        printf("Linear Comparisons: %d\n", linearComp);
    }

    return 0;
}
