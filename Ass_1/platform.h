#ifndef PLATFORM_H
#define PLATFORM_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct Platform{
    struct Post *post;
    struct Post *lastViewedPost;
}Platform;

Platform *createPlatform();
bool addPost(char *username, char *caption);
Post *viewPost(int n);
#endif