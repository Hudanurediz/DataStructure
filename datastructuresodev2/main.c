#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char Stack[150];
int top = -1;
int Max =150;
void push(char value);
void pop();

void push(char value){
    if(top == Max-1){
        ;
    }else{
    top++;
    Stack[top] = value;
    }
}
void pop(){
    if(top== -1){
        ;
    }else{
        top--;
    }
}
bool isMatching(char character1, char character2){
    if(character1 == '(' && character2 == ')')
        return true;
    else if(character1 == '{' && character2 == '}')
        return true;
    else if(character1 == '[' && character2 == ']')
        return true;
    else
        return false;
}

void main() {
    char text[Max];
    printf("Karakter dizisi giriniz: ");
    scanf("%s", text);
    int length=strlen(text);
    int i=0;
    for(i;i<length;i++){
        if(text[i] == '(' || text[i] == '{' || text[i] == '['){
            push(text[i]);
           }
        else if(text[i] == ')' || text[i] == '}' || text[i] == ']'){
            if(!top== -1 || isMatching(Stack[top], text[i])){
                pop();
            }
            else{
                top++;
                break;
            }
        }
    }
    if(top== -1){
        printf("Parantezler eslesiyor");
    }else{
        printf("Parantezler eslesmiyor");
    }
}
