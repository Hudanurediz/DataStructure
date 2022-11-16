#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    struct n *next;

};
typedef struct n node;
void show(node *r){
    while(r!=NULL){
        printf("%d\n",r->x);
        r=r->next;
    }
}
void ekle(node *r,int x){
    while(r->next!=NULL){
        r=r->next;
    };
    r->next=(node*)malloc(sizeof(node));
    r->next->x=x;
    r->next->next= NULL;
}
int main()
{
    node*root;
    root=(node*)malloc(sizeof(node));
    root->x=10;
    root->next=NULL;
    /*root->next=(node*)malloc(sizeof(node));
    root->next->x=20;
    root->next->next=NULL;//null kontrolu

    //printf("%d\n",iter->x);
    //iter=iter->next;
    printf("%d\n",iter->x);
    while(iter->next !=NULL){
        printf("%d\n",iter->x);
        iter=iter->next;
    }
    printf("---------------------\n");
    */
    node*iter;
    iter=root;
    int i=0;
    for(i=0;i<5;i++){
        /*iter->next=(node*)malloc(sizeof(node));
        iter=iter->next;
        iter->x=(i*i)+i;
        iter->next=NULL;*/
        ekle(iter,i*i);
    }
    show(root);

}
