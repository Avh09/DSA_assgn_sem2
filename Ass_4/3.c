#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int dist_trav = 0;
int time_taken = 0;
int n, k, d, p, flag = 0;

typedef struct Node {
    int distance;
    int time;
} Node;

typedef Node* Element;

typedef struct stHeap {
    int iSize;
    int iCapacity;
    Element *pElements;
} stHeap;

typedef stHeap * Heap;

Heap CreateHeap(size_t capacity) {
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

void InsertminHeap(Heap H, Element n) {
    int i;
    if (H->iSize >= H->iCapacity + 1) {
        printf("\nHeap is full\n");
        return;
    }
    // Allocate memory for the new element
    H->pElements[H->iSize + 1] = (Element)malloc(sizeof(Node));
    assert(H->pElements[H->iSize + 1] != NULL);

    for (i = ++H->iSize; H->pElements[i / 2]->time > n->time; i /= 2) {
        H->pElements[i] = H->pElements[i / 2];
    }
    H->pElements[i] = n;
}


Element Extractmin(Heap H) {
    int i, child;
    Element MinElement, Last;
    if (H->iSize <= 0) {
        return H->pElements[0];
    }
    MinElement = H->pElements[1];
    Last = H->pElements[H->iSize--];
    for (i = 1; i * 2 <= H->iSize; i = child) {
        child = 2 * i;
        if (child != H->iSize && H->pElements[child + 1]->time < H->pElements[child]->time) {
            child++;
        }
        if (Last->time > H->pElements[child]->time) {
            H->pElements[i] = H->pElements[child];
        }
        else {
            break;
        }
    }
    H->pElements[i] = Last;
    return MinElement;
}

void checkHeap(Heap H, int *dist_trav, int *time_taken, int *k) {
    if (H->iSize > 0) {
        Element a = Extractmin(H);

        if (*dist_trav + *k >= d) {
            flag = 1;
            return;
        }
        else if (H->iSize >= 0 && a->distance - *dist_trav >= 0) {
            *k = *k - (a->distance - *dist_trav) + p;
            *dist_trav = a->distance;
            *time_taken += a->time;
            return;
        }
        else {
            return;
        }
    }
    else {
        if (*dist_trav + *k >= d) {
            flag = 1;
            return;
        }
    }
}

int compare(const void* a, const void* b) {
    const Node* A = *(const Node**)a;
    const Node* B = *(const Node**)b;
    if (A->distance > B->distance)
        return 1;
    else if (A->distance < B->distance)
        return -1;
    else {
        return 0;
    }
}

void insertDist(Node** arr, int index, int distance) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->distance = distance;
    newNode->time = 0;
    arr[index] = newNode;
    arr[index]->distance = distance;
}

void insertTime(Node** arr, int index, int time) {
    arr[index]->time = time;
}

int main() {
    scanf("%d %d %d %d", &n, &k, &d, &p);
    int* dist = (int*)malloc(sizeof(int) * n);
    int* time = (int*)malloc(sizeof(int) * n);
    Heap H = CreateHeap(n);
    Node** arr = (Node**)malloc(sizeof(Node*) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &dist[i]);
        insertDist(arr, i, dist[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &time[i]);
        insertTime(arr, i, time[i]);
    }

    qsort(arr, n, sizeof(Node*), compare);

    for (int i = 0; i < n; i++) {
        if (k >= arr[i]->distance - dist_trav) {
            InsertminHeap(H, arr[i]);
        }
        else if (H->iSize <= 0) {
            break;
        }
        else {
            i--;
            checkHeap(H, &dist_trav, &time_taken, &k);
        }
    }

    for (int i = H->iSize; i > 0; i--) {
        checkHeap(H, &dist_trav, &time_taken, &k);
    }
    if (H->iSize == 0) {
        if (dist_trav + k >= d)
            flag = 1;
    }

    if (flag == 1) {
        printf("%d", time_taken);
    }
    else {
        printf("-1 ");
        printf("%d", dist_trav + k);
    }

    return 0;
}
