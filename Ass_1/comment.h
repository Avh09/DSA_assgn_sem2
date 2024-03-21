#ifndef COMMENT_H
#define COMMENT_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct Comment{
    char username[10];
    char content[10];
    struct Reply *r;
}Comment;

Comment *createComment(char *username,char *content);

#endif