#include <stdio.h>
#include <stdlib.h>
struct n{
    int x;
    struct n *next;

};
typedef struct n node;
void show(node *r){
    while(r!=NULL){
        printf("\n%d",r->x);
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
    node*iter;
    iter=root;
    int i=0;
    for(i=0;i<5;i++){
        ekle(iter,i*i);
    }
    show(root);
    printf("\n----Araya Eleman Ekleme----");
    for(i=0;i<3;i++){
        iter=iter->next;
    }
    node*temp;
    temp=(node*)malloc(sizeof(node));
    temp->next=iter->next;
    iter->next=temp;
    temp->x=25;
    show(root);

}
