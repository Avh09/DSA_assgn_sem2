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
tree *MakeTree(int arrSize, int *arr, tree *rootNode, int parentIndex){
    int l = 2*parentIndex + 1;
    int r = 2*parentIndex + 2;

    if(l>arrSize || r>arrSize){
        return rootNode;
    }

    if(rootNode == NULL){
        tree *new = createNode(arr[parentIndex]);
        rootNode = new;
    }

    if(rootNode->lc == NULL && rootNode->rc == NULL){
        if(l<arrSize){
            if(arr[l] != 0){
                rootNode->lc = createNode(arr[l]);
            }
        }
        if(r<arrSize){
            if(arr[r] != 0){
                rootNode->rc = createNode(arr[r]);
            }
        }
    }

    MakeTree(arrSize, arr, rootNode->lc, l);
    MakeTree(arrSize, arr, rootNode->rc, r);

    return rootNode;
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


int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    T = MakeTree(n, arr, T, 0);
    PreOrder(T);


}