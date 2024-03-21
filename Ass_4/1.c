#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include<limits.h>

int dist_trav = 0;
int time_taken = 0;
int n, k, d, p, flag = 0;

typedef struct Node{
    int distance;
    int time;
}Node;

typedef Node* Element;

typedef struct stHeap{
    int iSize;
    int iCapacity;
    Element *pElements;
}stHeap;

typedef stHeap * Heap;

Heap CreateHeap(size_t capacity){
    Heap H;
    assert(capacity > 0);
    H = (Heap)malloc(sizeof(stHeap));
    assert(H != NULL);
    H->pElements = (Element *)malloc(sizeof(Element) * (capacity + 1));
    assert(H->pElements != NULL);
    H->iCapacity = capacity;
    H->iSize = 0;
    H->pElements[0] = (Element)malloc(sizeof(Node));
    H->pElements[0]->time = -1;
    H->pElements[0]->distance = -1;
    return H;
}

void InsertminHeap(Heap H, Element n){
    int i;
    if(H->iSize >= H->iCapacity + 1){
        printf("\nHeap is full\n");
        return;
    }
    // Allocate memory for the new element
    H->pElements[H->iSize + 1] = (Element)malloc(sizeof(Node));
    assert(H->pElements[H->iSize + 1] != NULL);

    for(i = ++H->iSize; H->pElements[i/2]->time > n->time; i /= 2){
        H->pElements[i] = H->pElements[i/2];
    }
    H->pElements[i] = n;
}


void insertDist(Node **arr,int index, int distance){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->distance = distance;
    newNode->time = 0;
    arr[index] = newNode;
    arr[index]->distance = distance;
}

void insertTime(Node **arr, int index, int time){
    arr[index]->time = time;
}

int compare(const void *a, const void *b){
    const Node *A = *(const Node **)a;
    const Node *B = *(const Node **)b;
    if (A->distance > B->distance)
        return 1;
    else if (A->distance < B->distance)
        return -1;
    else{
        return 0;
    }
}

Element Extractmin(Heap H){
    int i,child;
    Element MinElement, Last;
    if(H->iSize <= 0){
        // printf("\nEmpty heap\n");
        return H->pElements[0];
    }
    MinElement = H->pElements[1];
    Last = H->pElements[H->iSize --];
    for(i=1;i*2<=H->iSize;i=child){
        child = 2*i;
        if(child != H->iSize && H->pElements[child + 1]->time < H->pElements[child]->time){
            child ++;
        }
        if(Last->time > H->pElements[child]->time){
            H->pElements[i] = H->pElements[child];
        }
        else{
            break;
        }
    }
    H->pElements[i] = Last;
    return MinElement;
}

void checkHeap(Heap H,int *dist_trav, int *time_taken, int *k){
    if(H->iSize > 0){
        Element a = Extractmin(H);

        if(*dist_trav + *k >= d){
            flag = 1;
            return;
        }
        else if(H->iSize >= 0 && a->distance - *dist_trav >= 0){
            *k = *k - (a->distance - *dist_trav) + p;
            *dist_trav = a->distance;
            *time_taken += a->time;
            // printf("\n***\n");

            // printf("dist_trav, k, min : %d %d %d\n",*dist_trav,*k,H->pElements[1]->distance);
            // fflush(stdout);
            return;
        }
        // else if(H->iSize > 0){
        //     checkHeap(H,dist_trav,time_taken,k);
        // }
        else{
            return;
        }

    }
    else{
        if(*dist_trav + *k >= d){
            flag = 1;
            return;
        }

    }
    
    

}

int main(){
    scanf("%d %d %d %d",&n,&k,&d,&p);
    int *dist = (int *)malloc(sizeof(int) * n);
    int *time = (int *)malloc(sizeof(int) * n);
    Heap H = CreateHeap(n);
    Node **arr = (Node **)malloc(sizeof(Node *) * n);
    for(int i=0;i<n;i++){
        scanf("%d",&dist[i]);
        insertDist(arr,i,dist[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&time[i]);
        insertTime(arr,i,time[i]);
    }

    // printf("Values stored in the t:\n");
    // for (int i = 0; i < n; ++i) {
    //     printf("%d %d\n", arr[i]->distance,arr[i]->time);
    // }
    qsort(arr,n,sizeof(Node),compare);

    // printf("Values after sorting:\n");
    // for (int i = 0; i < n; ++i) {
    //     printf("%d %d\n", arr[i]->distance,arr[i]->time);
    // }

    for(int i=0;i<n;i++){
        // printf("dist_trav, i, arr[i]->distance : %d %d %d\n",dist_trav,i,arr[i]->distance);
        // fflush(stdout);
        if(k >= arr[i]->distance - dist_trav){
            // printf("if : dist_trav, i : %d %d\n",dist_trav,i);
            // printf("i : %d\n",i);
            // fflush(stdout);
            InsertminHeap(H,arr[i]);
            // for(int i=1;i<=H->iSize;i++){
            //     printf("before blahhhh %d %d \n",dist_trav,H->pElements[i]->distance);
            // }
        }
        else if(H->iSize <= 0){
            break;
        }
        else{
            // for(int i=1;i<=H->iSize;i++){
            //     printf("%d ",H->pElements[i]->distance);
            // }
            
            i--;
            checkHeap(H,&dist_trav,&time_taken,&k);
            // printf("else : dist_trav, i : %d %d\n",dist_trav,i);
            // fflush(stdout);
        }
    }

    // for(int i=1;i<=H->iSize;i++){
    //             printf("before blahhhh %d %d \n",dist_trav,H->pElements[i]->distance);
    //         }
    // printf("size : %d\n",H->iSize);
    for(int i=H->iSize;i>0;i--){
        // printf("\n**************\n");
        checkHeap(H,&dist_trav,&time_taken,&k);
        // printf("dist_trav : %d\n",dist_trav);

    }
    if(H->iSize == 0){
        if(dist_trav + k >= d)
        flag = 1;

    }
    // checkHeap(H,&dist_trav,&time_taken,&k);
        

    // for(int i=1;i<=H->iSize;i++){
    //             printf("blahhhh %d ",H->pElements[i]->distance);
    //         }
    
    if(flag == 1){
        printf("%d",time_taken);
    }
    else{
        printf("-1 ");
        printf("%d",dist_trav + k);
    }
}