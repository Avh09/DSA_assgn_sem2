#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    int value;
    struct Node *next;
};

struct HashMap
{
    int capacity;
    struct Node **arr;
};

void initializeHashMap(struct HashMap *hm, int capacity)
{
    hm->capacity = capacity;
    hm->arr = (struct Node **)malloc(sizeof(struct Node *) * (capacity + 1));
    for (int i = 0; i <= capacity; ++i)
        hm->arr[i] = NULL;
}

int hashFunction(struct HashMap *hm, int key)
{
    int a = key % (hm->capacity);
    // if(a == 0){
    //     return 1;
    // }
    return a;
}

struct HashMap *delete(struct HashMap *h, struct Node *parent, struct Node *temp)
{
    parent->next = temp->next;
    free(temp);
    return h;
}

void insert(struct HashMap *hm, int key, int value)
{
    int index = hashFunction(hm, key);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    if (hm->arr[index] == NULL)
    {
        hm->arr[index] = newNode;
    }
    else
    {
        struct Node *temp = hm->arr[index];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void NewInsert(struct HashMap *hm, int key, int value)
{
    // printf("5 ");
    int index = hashFunction(hm, key);
    // printf("4 ");
    if (hm->arr[index] == NULL)
    {
        // printf("3 ");
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->key = key;
        newNode->value = value;
        newNode->next = NULL;
        hm->arr[index] = newNode;
    }
    else
    {
        struct Node *temp = hm->arr[index];
        struct Node *par = NULL;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                if (temp->value < value)
                {
                    temp->key = key;
                    temp->value = value;
                    return;
                }
                else
                {
                    return;
                }
            }
            par = temp;
            temp = temp->next;
        }

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->key = key;
        newNode->value = value;
        newNode->next = NULL;
        par->next = newNode;
        return;
    }
}

int search(struct HashMap *hm, int key, int idx)
{
    int index = hashFunction(hm, key);
    struct Node *temp = hm->arr[index];
    while (temp != NULL)
    {
        if (temp->key == key && temp->value >= idx)
        {
            // printf("%d  ",temp->value) ;
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

int NewSearch(struct HashMap *h, int key, int idx)
{
    int index = hashFunction(h, key);
    struct Node *temp = h->arr[index];
    struct Node *parent = temp;
    int store = 0, flag = 0;
    while (temp != NULL)
    {
        if (temp->key == key && temp->value >= idx)
        {
            if (temp->value > store)
            {
                store = temp->value;
                flag = 1;
            }
        }
        parent = temp;
        temp = temp->next;
        // printf("%d ", temp->key);
    }
    if (flag == 0)
    {
        return -1;
    }
    else
    {
        return store;
    }
}

int main()
{
    int n, max_key = 0;
    scanf("%d", &n);
    int *book = (int *)malloc(sizeof(int) * n);
    struct HashMap hm;
    initializeHashMap(&hm, 1000000);
    struct HashMap dp;
    initializeHashMap(&dp, 1000000);

    int maxLength = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &book[i]);
        insert(&hm, book[i], i);
        int key = book[i];
        int prevKey = key - 1;
        int index = search(&hm, prevKey, -1);
        // int idx2 = search(&dp, prevKey, -1);

        // printf("%d ",index);
        int dpValue = 1;
        if (index != -1)
        {
            int idx2 = NewSearch(&dp, prevKey, -1);
            if (idx2 != -1)
            {
                dpValue = idx2 + 1;
            }
            // printf("%d ",search(&dp, prevKey));
        }

        // printf("%d  ",search(&hm, prevKey));
        NewInsert(&dp, key, dpValue);
        // insert(&dp, key, dpValue);

        if (dpValue > maxLength)
        {
            maxLength = dpValue;
            max_key = key;
        }
    }

    // printf("Values stored in the hash map:\n");
    // for (int i = 1; i <= hm.capacity; ++i) { // Adjust loop to start from 1
    //     struct Node* current = hm.arr[i];
    //     printf("Bucket %d: ", i);
    //     while (current != NULL) {
    //         printf("(%d, %d) ", current->key, current->value);
    //         current = current->next;
    //     }
    //     printf("\n");
    // }

    // printf("Values stored in the hash map:\n");
    // for (int i = 0; i < dp.capacity; ++i) { // Adjust loop to start from 1
    //     struct Node* current = dp.arr[i];
    //     printf("Bucket %d: ", i);
    //     while (current != NULL) {
    //         printf("(%d, %d) ", current->key, current->value);
    //         current = current->next;
    //     }
    //     printf("\n");
    // }

    // printf("%d\n",maxIndex);
    printf("%d\n", maxLength);
    int prev = 0;
    for (int i = max_key - maxLength + 1; i <= max_key; ++i)
    {
        prev = search(&hm, i, prev);
        if (prev >= 0)
        {
            printf("%d ", prev);
        }
        else
        {
            printf("0 ");
        }
    }
    // printf("\n");

    return 0;
}