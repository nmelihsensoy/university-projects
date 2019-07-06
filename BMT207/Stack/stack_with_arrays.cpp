/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "stack_with_arrays.cpp"
 * 
 * Stack Implementation with using arrays
 *
 */

#include <iostream>
using namespace std;

struct stack{
    int top;
    int ssize;
    int *d;
};

stack *init(int dsize=10){
    stack *n = new stack;
    n->top = -1;
    n->ssize = dsize;
    n->d = NULL;
    return n;
}

void push(stack *s, int x){
    if(s->top == -1){
        s->d = new int[s->ssize];
    }
    if(s->top == s->ssize-1){
        cout<<x<<": Stack Overflow."<<endl;
        return;
    }
    s->d[++s->top] = x;
}

void pop(stack *s){
    if(s->top == -1){
        cout<<"Stack Underflow."<<endl;
        return;
    }
    s->d[s->top--];
}

void print_s(stack *s){
    if(s->top == -1){
        cout<<"Stack Empty."<<endl;
        return;
    }
    for(int i=0; i<=s->top; i++){
        cout<<s->d[i]<<", ";
    }
    cout<<endl;
}

void print_top(stack *s){
    if(s->top != -1) cout<<s->d[s->top]<<endl;
}

int main(){

    stack *s1 = init(4);
    print_s(s1);
    push(s1, 12);
    push(s1, 13);
    push(s1, 14);
    push(s1, 15);
    push(s1, 16);
    print_s(s1);

    pop(s1);
    pop(s1);
    pop(s1);
    pop(s1);
    pop(s1);
    print_s(s1);

    push(s1, 33);
    push(s1, 35);
    print_s(s1);
    
    return 0;
}