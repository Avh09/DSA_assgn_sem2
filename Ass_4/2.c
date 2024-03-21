#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int x;
    int y;
}Node;

void insertX(Node **arr,int index, int x){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = 0;
    arr[index] = newNode;
    arr[index]->x = x;
}

void insertY(Node **arr, int index, int y){
    arr[index]->y = y;
}

int compare(const void *a, const void *b){
    const Node *A = *(const Node **)a;
    const Node *B = *(const Node **)b;
    if (A->y > B->y)
        return -1;
    else if (A->y < B->y)
        return 1;
    else{
        return 0;
    }
}

int comparePosY(const void *a, const void *b){
    const Node *A = *(const Node **)a;
    const Node *B = *(const Node **)b;
    if (A->x > B->x)
        return 1;
    else if (A->x < B->x)
        return -1;
    else{
        return 0;
    }
}

int compareNegY(const void *a, const void *b){
    const Node *A = *(const Node **)a;
    const Node *B = *(const Node **)b;
    if (A->x > B->x)
        return -1;
    else if (A->x < B->x)
        return 1;
    else{
        return 0;
    }
}

int main(){
    int n,k,posYindex = 0,negYindex = 0,flag = 0;
    scanf("%d %d",&n,&k);
    int *x = (int *)malloc(sizeof(int) * n);
    int *y = (int *)malloc(sizeof(int) * n);
    Node **arr = (Node **)malloc(sizeof(Node *) * n);
    Node **posY = (Node **)malloc(sizeof(Node *) * n);
    Node **negY = (Node **)malloc(sizeof(Node *) * n);
    int sum = k;
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
        insertX(arr,i,x[i]);

    }
    for(int i=0;i<n;i++){
        scanf("%d",&y[i]);
        insertY(arr,i,y[i]);
        sum += y[i];
    }

    // printf("Values stored in the t:\n");
    // for (int i = 0; i < n; ++i) {
    //     printf("%d %d\n", arr[i]->x,arr[i]->y);
    // }
    if(sum < 0){
        printf("NO");
        return 0;
    }

    qsort(arr,n,sizeof(Node),compare);

    // printf("Values after sorting:\n");
    // for (int i = 0; i < n; ++i) {
    //     printf("%d %d\n", arr[i]->x,arr[i]->y);
    // }

    for(int i=0;i<n;i++){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->x = arr[i]->x;
        newNode->y = arr[i]->y;
        
        if(arr[i]->y >= 0){
            posY[posYindex] = newNode;
            posYindex++;
        }
        else{
            negY[negYindex] = newNode;
            negYindex++;
        }
    }

    qsort(posY,posYindex,sizeof(Node),comparePosY);
    int posSum = k;

    // printf("Values after posY sorting:\n");
    // for (int i = 0; i < posYindex; ++i) {
    //     printf("%d %d\n", posY[i]->x,posY[i]->y);
    // }

    for(int i=0;i<posYindex;i++){
        
        if(posY[i]->x<=posSum){
            posSum += posY[i]->y;
            continue;
        }
        else{
            flag = 1;
            break;
        }
    }

    // printf("\n***\n");
    // printf("posSum : %d\n",posSum);

    qsort(negY,negYindex,sizeof(Node),compareNegY);
    int negSum = posSum;

    // printf("Values after negY sorting:\n");
    // for (int i = 0; i < negYindex; ++i) {
    //     printf("%d %d\n", negY[i]->x,negY[i]->y);
    // }

    for(int i=0;i<negYindex;i++){
        if(negY[i]->x<=negSum){
            negSum += negY[i]->y;
            continue;
        }
        else{
            flag = 1;
            break;
        }
    }

    if(flag == 0){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;
}