#ifndef REPLY_H
#define REPLY_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct Reply{
    char username[10];
    char content[10];
}Reply;

Reply *createReply(char *username,char *content);

#endif