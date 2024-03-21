#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include<limits.h>

// int dist_trav = 0;
long long int time_taken = 0;
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
        H->pElements[i] = H->pElements[i/2];                               // DOUBTTTTTTTTTTTTTT
    }
    H->pElements[i] = n;
}


void insertDist(Node **arr,int index, int distance){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->distance = distance;
    newNode->time = 0;
    arr[index] = newNode;
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
        return H->pElements[0];
    }
    MinElement = H->pElements[1];
    Last = H->pElements[H->iSize --];                   // DOUBTTTTTTTTTTTTTTTTT
    for(i=1;i*2 <= H->iSize;i=child){
        child = 2*i;
        if(child != H->iSize && H->pElements[child + 1]->time < H->pElements[child]->time){
            child ++;
        }
        if(Last->time > H->pElements[child]->time){
            H->pElements[i] = H->pElements[child];              // DOUBTTTTTTTT
        }
        else{
            break;
        }
    }
    H->pElements[i] = Last;                                     // DOUBTTTTTTTTTTTTTTT
    return MinElement;
}

void checkHeap(Heap H,long long int *time_taken, int *k){
    if(H->iSize > 0){
        Element a = Extractmin(H);

        if(*k >= d){
        flag = 1;
        return;
        }
        else if(H->iSize >= 0 && a->distance >= 0){
            *k = *k + p;
            // *dist_trav = a->distance;
            *time_taken += a->time;

            return;
        }
        else{
            return;
        }

    }
    else{
        if(*k >= d){
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

    qsort(arr,n,sizeof(Node*),compare);                                   // CHANGEEEEEEEEEEE

    for(int i=0;i<n;i++){
        if(k >= arr[i]->distance){
            InsertminHeap(H,arr[i]);
        }
        else if(H->iSize <= 0){
            break;
        }
        else{            
            i--;
            checkHeap(H, &time_taken,&k);
        }
    }

    for(int i=H->iSize;i>0;i--){
        checkHeap(H,&time_taken,&k);

    }
    if(H->iSize == 0){
        if(k >= d)
        flag = 1;

    }
    
    if(flag == 1){
        printf("%lld",time_taken);
    }
    else{
        printf("-1 ");
        printf("%d",k);
    }

    printf("\n");
}

