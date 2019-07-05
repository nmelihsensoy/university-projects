/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "doubly_linked_list.cpp"
 * 
 * Doubly Linked List Implementation
 *
 */

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};

void insert_first(node **h, node **t, int x){
    node *n = new node;
    n->data = x;
    n->prev = NULL;
    if(*h == NULL){
        n->next = NULL;
        *h = n;
        *t = n;    
    }else{
        n->next = *h;
        (*h)->prev = n;
        *h = n;
    }
}

void insert_last(node **h, node **t, int x){
    node *n = new node;
    n->data = x;
    n->next = NULL;
    if(*h == NULL){
        n->prev = NULL;
        *h = n;
        *t = n;
    }else{
        n->prev = *t;
        (*t)->next = n;
        *t = n;
    }
}

void insert_after(node **h, node **t, int s, int x){
    node *n = new node;
    n->data = x;
    n->prev = NULL;
    n->next = NULL;
    if(*h == NULL){
        *h = n;
    }else{
        node *temp = *h;
        while(temp->data != s && temp->next != NULL) temp = temp->next;
        if(temp->next == NULL) *t = n;
        n->next = temp->next;
        n->prev = temp;
        temp->next = n;
    }
}

void insert_before(node **h, node **t, int s, int x){
    node *n = new node;
    n->data = x;
    if(*h == NULL){
        n->next = NULL;
        n->prev = NULL;
        *h = n;
    }else{
        node *temp = *h;
        while(temp->data != s && temp->next != NULL) temp = temp->next;
        if(temp->data != s){ //if couldn't find insert to the end
            n->prev = *t;
            n->next = NULL;
            (*t)->next = n;
            *t = n;
            return;
        }

        temp->prev->next = n;
        n->prev = temp->prev;
        n->next = temp;
        temp->prev = n;
    }
}

void insert_sorted(node **h, node **t, int x){
    node *n = new node;
    n->data = x;
    n->next = NULL;
    n->prev = NULL;
    if(*h == NULL){
        *h = n;
        *t = n;
        return;
    }
    if((*h)->data > x){
        n->next = *h;
        (*h)->prev = n;
        *h = n;
        return;
    }
    node *temp = *h;
    while(x > temp->data && temp->next != NULL) temp = temp->next;
    if(temp->next == NULL) *t = n;

    n->next = temp->next;
    temp->next = n;
    n->prev = temp;
}

void remove_first(node **h, node **t){
    if(*h == NULL){ cout<<"List Empty"; return;}
    node *temp = *h;
    (*h)->next->prev = NULL;
    *h = (*h)->next;
    free(temp);
}

void remove_last(node **h, node **t){
    if(*h == NULL){cout<<"List Empty"; return;};
    node *temp = *t;
    (*t)->prev->next = NULL;
    *t = (*t)->prev;

    temp->next = NULL;
    temp->prev = NULL;
    free(temp);
}

void remove(node **h, node **t, int s){
    if(*h == NULL){ cout<<"List Empty"; return; }
    node *temp = *h;
    while(temp->data != s && temp->next != NULL) temp = temp->next;
    
    if((*h)->data == s){temp->next->prev = temp->prev; *h = temp->next;}
    else if(temp->next == NULL){temp->prev->next = temp->next; *t = temp->prev;}
    else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    temp->next = NULL;
    temp->prev = NULL;
    free(temp);
}   

void traverse(node *h){
    if(h == NULL) return;
    cout<<h->data<<", ";
    traverse(h->next);
}

void traverse_rev(node *t){
    if(t == NULL) return;
    cout<<t->data<<", ";
    traverse_rev(t->prev);
}

int main(){

    node *head = NULL, *tail = NULL;
    
    /**
    insert_last(&head, &tail, 33);
    insert_last(&head, &tail, 37);
    insert_last(&head, &tail, 99);
    insert_after(&head, &tail, 999, 45);
    insert_after(&head, &tail, 999, 22);
    insert_before(&head, &tail, 999, 77);
    remove(&head, &tail, 77);
    **/
    insert_sorted(&head, &tail, 33);
    insert_sorted(&head, &tail, 3);
    insert_sorted(&head, &tail, 43);
    insert_sorted(&head, &tail, 100);
    insert_sorted(&head, &tail, 400);
    traverse(head);
    cout<<endl;
    traverse_rev(tail);

    return 0;
}