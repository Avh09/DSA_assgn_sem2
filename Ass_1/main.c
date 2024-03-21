#include "reply.h"
#include "comment.h"
#include "post.h"
#include "platform.h"

extern Platform *platform;

int main(){
    char a[] = "ananya";
    char b[] = "hello";
    // Reply *r = createReply(a,b);
    // Comment *com = createComment(a,b);
    // Post *po = createPost(a,b);
    Platform *platform = createPlatform();
    int add = addPost(a,b);
    struct Post *po = viewPost(1);
    
    printf("%s",po->username);
}