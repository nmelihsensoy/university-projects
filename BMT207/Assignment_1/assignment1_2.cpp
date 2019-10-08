/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "assignment1_2.cpp"
 * 
 * Create a linked list structure. Create a 2 instance of this linked list.
 * Then write a function that can insert first lists elements to the other list in reverse position.
 *
 */

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

void insert(node **head, int x){
    node *n = new node;
    n->data = x;
    n->next = NULL;
    if(*head == NULL){
        *head = n;
        return;
    }
    node *iter = *head;
    while(iter->next != NULL) iter = iter->next;
    iter->next = n;
}

void print_l(node *head){
    if(head == NULL) return;
    cout<<head->data<<", ";
    print_l(head->next);
}

void reverse_to(node **h1, node **h2){
    if(*h1 == NULL) return;
    reverse_to(&(*h1)->next, h2);
    insert(h2, (*h1)->data);
}

int main(){
    
    node *list1_head=NULL, *list2_head=NULL;
    insert(&list1_head, 15);
    insert(&list1_head, 16);
    insert(&list1_head, 17);
    insert(&list1_head, 18);
    insert(&list1_head, 19);
    insert(&list1_head, 20);
    insert(&list1_head, 21);
    insert(&list1_head, 22);
    print_l(list1_head);

    reverse_to(&list1_head, &list2_head);
    cout<<endl;
    print_l(list2_head);
    cout<<endl;

    return 0;
}