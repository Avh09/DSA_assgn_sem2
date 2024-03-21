#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int data;
    struct tree *lc;
    struct tree *rc;
} tree;

tree *createNode(int data) {
    tree *newNode = (tree*)malloc(sizeof(tree));
    newNode->data = data;
    newNode->lc = NULL;
    newNode->rc = NULL;
    return newNode;
}

tree *insertLevelOrder(tree* root, int *arr, int n) {
    if (n <= 0)
        return NULL;

    tree** queue = (tree**)malloc(n * sizeof(tree*));
    int front = 0;
    int rear = 0;
    int levels = 0; // Initialize levels count to 0
    int nodesInCurrentLevel = 0; // Initialize nodes count for the current level

    root = createNode(arr[0]);
    queue[rear++] = root;
    ++nodesInCurrentLevel;

    for (int i = 1; i < n; ++i) {
        tree* parent = queue[front];

        if (arr[i] != 0) {
            tree* newNode = createNode(arr[i]);
            parent->lc = newNode;
            queue[rear++] = newNode;
            ++nodesInCurrentLevel;
        }

        ++i;
        if (i < n && arr[i] != 0) {
            tree* newNode = createNode(arr[i]);
            parent->rc = newNode;
            queue[rear++] = newNode;
            ++nodesInCurrentLevel;
        }

        if (--nodesInCurrentLevel == 0) { // Check if the current level is completed
            ++levels; // Increment levels count
            nodesInCurrentLevel = rear - front; // Update nodes count for the next level
        }

        ++front;
    }

    free(queue);
    printf("Levels: %d\n", levels);
    return root;
}

void PreOrder(tree *temp) {
    if (temp != NULL) {
        printf("%d ",temp->data);
        PreOrder(temp->lc);
        PreOrder(temp->rc);
    }
}

int main() {
    tree *T = NULL;
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }

    T = insertLevelOrder(T, arr, n);
    printf("Preorder Traversal: ");
    PreOrder(T);

    return 0;
}
