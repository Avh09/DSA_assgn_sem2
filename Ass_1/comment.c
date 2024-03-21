#include "reply.h"
#include "comment.h"
#include "post.h"
#include "platform.h"

Comment *createComment(char *username,char *content){
    Comment *comment = (Comment*)malloc(sizeof(Comment));
    strcpy(comment->username,username);
    strcpy(comment->content,content);
    return comment;

}