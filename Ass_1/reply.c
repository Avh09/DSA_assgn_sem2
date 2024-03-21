#include "reply.h"
#include "comment.h"
#include "post.h"
#include "platform.h"
Reply *createReply(char *username,char *content){
    Reply *reply = (Reply*)malloc(sizeof(Reply));
    strcpy(reply->username,username);
    strcpy(reply->content,content);
    return reply;

}