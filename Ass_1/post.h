#ifndef POST_H
#define POST_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct Post{
    char username[10];
    char content[10];
    struct Comment *c;
    struct Post *next;
    struct Post *prev;
}Post;

Post *createPost(char *username,char *content);

#endif