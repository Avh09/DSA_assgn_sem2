#include "reply.h"
#include "comment.h"
#include "post.h"
#include "platform.h"

Post *createPost(char *username,char *content){
    if(platform->post == NULL){
        Post *newPost = (Post*)malloc(sizeof(Post));
        strcpy(platform->newPost->username,username);
        strcpy(platform->newPost->content,content);
        platform->newPost->comment = NULL;
        platform->newPost->next = NULL;
        platform->newPost->prev = NULL;
        platform->post = newPost;
        platform->post *temp = post;
        platform->temp->next = NULL;
        platform->temp->prev = NULL;
    }
    else{
        platform->post *newPost = (Post*)malloc(sizeof(Post));
        strcpy(platform->newPost->username,username);
        strcpy(platform->newPost->content,content);
        platform->newPost->comment = NULL;
        platform->post *post = newPost;
        platform->post *temp1 = platform->temp;
        platform->temp->next = platform->post;
        platform->temp = platform->post;
        platform->temp->prev = platform->temp1;
    }
    return post;
}

