#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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

    root = createNode(arr[0]);
    queue[rear++] = root;
    // int levels = 1;



    for (int i = 1; i < n; ++i) {
        tree* parent = queue[front];

        if (arr[i] != 0) {
            tree* newNode = createNode(arr[i]);
            parent->lc = newNode;
            queue[rear++] = newNode;

            // if ((i & (i + 1)) == 0) { // Check if a new level has started
            //     ++levels; // Increment levels count
            // }
        }

        ++i;
        if (i < n && arr[i] != 0) {
            tree* newNode = createNode(arr[i]);
            parent->rc = newNode;
            queue[rear++] = newNode;
        }

        //  if (i < n && (i % (2 * levels)) == 0) { // Check if a new level has started
        //     ++levels; // Increment levels count
        // }

        ++front;

        
        
    }

    free(queue);
    // printf("levels : %d\n",levels);
    return root;
}




// int findLevels(tree *root) {
//     if (root == NULL)
//         return 0;
//     else {
//         int leftHeight = findLevels(root->lc);
//         int rightHeight = findLevels(root->rc);
//         return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
//     }
// }
int minPhones(tree *root) {
    if (root == NULL)
        return 0;

    int left_with = minPhones(root->lc);
    int right_with = minPhones(root->rc);

    if (root->lc != NULL && root->rc != NULL) {
        return left_with + right_with + 1;
    } else if (root->lc != NULL || root->rc != NULL) {
        return left_with + right_with + 1;
    } else {
        return 1;
    }
}



void PreOrder(tree *temp) {
    if (temp != NULL) {
        printf("%d ",temp->data);
        PreOrder(temp->lc);
        PreOrder(temp->rc);
    }
}

void PostOrder(tree *temp){
    if(temp != NULL){
        PostOrder(temp->lc);
        PostOrder(temp->rc);
        printf("%d ",temp->data);
    }
    else{
        return;
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
    printf("\nPostorder Traversal: ");
    PostOrder(T);

    printf("%d\n", minPhones(T));
    return 0;
}
