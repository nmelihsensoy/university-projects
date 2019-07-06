/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "circular_doubly_linked_list.cpp"
 * 
 * Circular Doubly Linked List Implementation
 *
 */

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};

struct list{
    node *head;
    node *tail;
};

list *init(){
    list *l = new list;
    l->head = NULL;
    l->tail = NULL;
    return l;
}

node *insert(list *l, int x){
    node *n = new node;
    n->data = x;
    if(l->head == NULL){
        n->prev = NULL;
        n->next = NULL;
        l->head = n;
        l->tail = n;
    }else{
        n->prev = l->tail;
        n->next = l->head;//l->tail->next
        l->tail->next = n;
        l->tail = n;
        l->head->prev = n;
    }
    return l->head;
}

void remove(list *l, int s){
    node *iter = l->head;
    while(iter->data != s && iter->next != NULL) iter = iter->next;
    if(iter == l->head){
        l->head->next->prev = l->tail;
        l->tail->next = l->head->next;
        l->head = l->head->next;
    }else if(iter == l->tail){
        l->tail = iter->prev;
        iter->prev->next = iter->next;
        iter->next->prev = iter->prev;
    }else{
        iter->prev->next = iter->next;
        iter->next->prev = iter->prev;
    }
    free(iter);
}

void printList(list* l){
    node *iter = l->head;
    do{
        cout<<iter->data<<", ";
        iter = iter->next;
    }while(iter != l->head);
    cout<<endl;
}

void printList2(list *l){
    node *iter = l->head;
    while(iter->next != l->head){
        cout<<iter->data<<", ";
        iter = iter->next;
    }
    cout<<l->tail->data<<", ";
    cout<<endl;
}

int main(){

    list *l1 = init();
    insert(l1, 15);
    insert(l1, 20);
    insert(l1, 22);
    insert(l1, 42);
    insert(l1, 82);
    insert(l1, 90);
    insert(l1, 70);
    insert(l1, 30);
    printList2(l1);
    remove(l1, 30);
    remove(l1, 15);
    remove(l1, 22);
    printList2(l1);

    return 0;
}