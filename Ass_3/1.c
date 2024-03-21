#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int value;
    int index;
    struct node *next;
}node;

typedef struct table{
    node **tabArr;
    int tabSize;
}table;

table *CreateTable(int tabSize){
    table *newTable = (table*)malloc(sizeof(table));
    newTable->tabSize = tabSize;
    newTable->tabArr = (node**)malloc(sizeof(node*) * tabSize);
    for (int i = 0; i < tabSize; i++) {
        newTable->tabArr[i] = NULL;
    }
    return newTable;
}

node *CreateNode(int value, int index){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->index = index;
    newNode->next = NULL;
    return newNode;
}

node *CreateLine(int value, int index, int i,table *tab){
    node *newNode = CreateNode(value, index);
    return newNode;
}

table *find(int value, int index, table *tab){
    int i = 0;
    while(tab->tabArr[i] != NULL){
        if (tab->tabArr[i]->value == value - 1) {
            tab->tabArr[i]->next = CreateNode(value, index);
            return tab;
        } else if (tab->tabArr[i]->value >= value) {
            break;
        }
        i++;
    }
    if (tab->tabArr[i] == NULL){
        tab->tabArr[i]->next = CreateNode(value, index);
    } 
    return tab;
}

void MakeHash(int value, int index, table *tab){
    int i=0;
    if(index == 0){
        tab->tabArr[0]->next = CreateNode(value, index);
        i++;
    }
    else{
        tab = find(value,index,tab);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    table *tab = CreateTable(n);
    for(int i=0;i<n;i++){
        MakeHash(arr[i],i,tab);
    }
}
