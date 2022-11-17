#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
node* siraliEkle(node *r,int x){
    if(r==NULL){//bagli liste bossa
        r=(node*)malloc(sizeof(node));
        r->next=NULL;
        r->x=x;
        return r;
    }
    if(r->x >x){//gelen deger kucukse,bu islemde root degisir
        node*temp;
            temp=(node*)malloc(sizeof(node));
            //temp->next=NULL;
            temp->x=x;
            temp->next=r;
            return temp;
    }
    node *iter=r;//iter dolassin diye tanımladik
    while(iter->next !=NULL && iter->next->x < x){
        iter=iter->next;
    }
    node*temp;
    temp=(node*)malloc(sizeof(node));
    temp->next=iter->next;
    iter->next=temp;
    temp->x=x;
    return r;
}
int main()
{
    node*root;
    root=NULL;//sirali ekleme isleminde baslangicta root null,burdan baslanarak linked liste ekleme yapilacak
    node*iter;
    iter=root;
    for(int i=0;i<5;i++){
        int j=pow(-2,i);
        root=siraliEkle(root,j);
    }
    show(root);

}
