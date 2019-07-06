/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "stack_with_lists.cpp"
 * 
 * Stack Implementation with using linked lists
 *
 */

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

struct stack{
    node *top = NULL; 
};

void push(stack *s, int x){
    node *n = new node;
    n->data = x;
    n->next = s->top;
    s->top = n;
}

void pop(stack *s){
    if(s->top == NULL){
        cout<<"Stack Underflow."<<endl;
        return;
    }
    node *temp = s->top;
    s->top = s->top->next;
    free(temp);
}

void print_s(stack *s){
    node *iter = s->top;
    while(iter != NULL){
        cout<<iter->data<<", ";
        iter = iter->next;
    }
    cout<<endl;
}

int main(){

    stack *s1 = new stack;

    push(s1, 14);
    push(s1, 16);
    push(s1, 22);
    print_s(s1);

    pop(s1);
    pop(s1);
    print_s(s1);

    return 0;
}