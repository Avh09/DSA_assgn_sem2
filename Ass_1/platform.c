#include "reply.h"
#include "comment.h"
#include "post.h"
#include "platform.h"
Platform *platform;

Platform *createPlatform(){
    platform = (Platform*)malloc(sizeof(Platform));
    platform->lastViewedPost = NULL;
    return platform;
}

bool addPost(char *username, char *caption){
    if(platform == NULL){
        platform->lastViewedPost = NULL;
        return false;
    }
    else{
        platform->Post *newPost;+++++
        platform->newPost = createPost(username,caption);
        platform->lastViewedPost = newPost;
        return true;
    }
}

Post *viewPost(int n){
    if(platform->lastViewedPost == NULL){
        return NULL;
    }
    platform->post *temp = platform->lastViewedPost;
    if(n == 1){
        return platform->lastViewedPost;
    }
    else{
        for(int i=2;i<=n;i++){
            platform->temp = platform->temp->prev; 
        }
        return platform->temp;
    }
}