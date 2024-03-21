#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int data;
    struct tree *lc;
    struct tree *rc;
}tree;

tree *T;

tree *createNode(int data){
    tree *newNode = (tree*)malloc(sizeof(tree));
    newNode->data = data;
    newNode->lc = NULL;
    newNode->rc = NULL;
    return newNode;
}
tree *insertLevelOrder(tree* root, int *arr){
    tree** queue = (tree**)malloc(100 * sizeof(tree*));
    int front = 0;
    int rear = 0;

    if (root == NULL) {
        root = createNode(arr[front]);
        return NULL;
    }

    queue[rear++] = root;

    while (front < rear) {
        tree* tempNode = queue[front++];

        if (tempNode->lc == NULL && arr[rear] != 0) {
            tempNode->lc = createNode(arr[rear]);
            break;
        }
        else {
            queue[rear++] = tempNode->lc;
        }

        if (tempNode->rc == NULL && arr[rear] != 0) {
            tempNode->rc = createNode(arr[rear]);
            break;
        }
        else {
            queue[rear++] = tempNode->rc;
        }
    }

    free(queue);
}

void PreOrder(tree *temp){
    if(temp != NULL){
        printf("%d ",temp->data);
        PreOrder(temp->lc);
        PreOrder(temp->rc);
    }
    else{
        return;
    }
}

int main() {
 
    struct Node *root;
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }


    tree *T = insertLevelOrder(T, arr);

    PreOrder(T);

    return 0;
}