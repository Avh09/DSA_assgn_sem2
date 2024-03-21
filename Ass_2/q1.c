#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    struct tree *left;
    struct tree *right;
    int data;
}tree;

tree *createNode(int data){
    tree *newNode = malloc(sizeof(tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}



int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    // for(int i=0;i<n;i++){
    //     if(i==0 && arr[i] == 1){
    //         root = createNode(T, arr[i]);
    //         temp = root;
    //         if(arr[2*i + 1] == 1){
    //             temp->left = createNode;
    //         }
    //         if(arr[2*i + 2] == 1){
    //             temp->right = createNode;
    //         }
    //         if(temp->left != NULL){
    //             temp = temp->left;
    //         }
    //         else if(tem;p->right != NULL){
    //             temp = temp->right;
    //         }
    //         else{
    //             break;
    //         }

    //     }
    //     else{
    //         for(i=)
    //         if(arr[2*i + 1] == 1){
    //             temp->left = createNode;
    //         }
    //         if(arr[2*i + 2] == 1){
    //             temp->right = createNode;
    //         }
    //         if(temp->left != NULL){
    //             temp = temp->left;
    //         }
    //         else if(tem;p->right != NULL){
    //             temp = temp->right;
    //         }
    //         else{
    //             i++;
    //             func();

    //         }

    //     }
    // }

    if(arr[0] == 1){
        root = createNode;
        temp = root;
    }
    int i=0;
    while(){
        if(arr[2*i + 1] == 1){
            temp->left = createNode(T, arr[2*i + 1]);

        }
        if(arr[2*i + 2] == 1){
            temp->right = createNode(T, arr[2*i + 2]);
            
        }
        if(temp->left != NULL || temp->right != NULL){
            if(temp->left != NULL){
                
            }
        }
    }
        

    
}