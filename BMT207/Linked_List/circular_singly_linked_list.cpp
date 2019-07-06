/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "circular_singly_linked_list.cpp"
 * 
 * Circular Singly Linked List Implementation
 *
 */

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *insert(node *h, int x){
    node *n = new node;
    n->data = x;
    if(h == NULL){
        n->next = NULL;
        h = n;
    }else{
        node *iter = h;
        while(iter->next != h && iter->next != NULL) iter = iter->next;
        iter->next = n;
        n->next = h;
    }
    return h;
}

node *remove(node *h, int s){
    node *iter = h;
    node *prev = NULL;
    while(iter->data != s){
        prev = iter;
        iter = iter->next;
    }

    if(iter == h){
        node *last = h;
        while(last->next != h && last->next != NULL) last = last->next;
        h = iter->next;
        last->next = iter->next;
    }else{
        prev->next = iter->next;
    }

    prev = NULL;
    free(iter);
    free(prev);

    return h;
}

void printList(node *h){
    node *iter = h;
    do{
        cout<<iter->data<<", ";
        iter = iter->next;
    }while(iter != h);
    cout<<endl;
}

int main(){
    node *head=NULL;
    head = insert(head, 13);
    insert(head, 45);
    insert(head, 66);
    insert(head, 77);
    insert(head, 99);
    insert(head, 85);
    insert(head, 35);
    insert(head, 33);
    printList(head);

    head = remove(head, 13);
    remove(head, 77);
    remove(head, 33);
    printList(head);

    return 0;
}