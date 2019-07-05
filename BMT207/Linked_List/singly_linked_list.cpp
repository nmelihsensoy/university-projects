/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "singly_linked_list.cpp"
 * 
 * Singly Linked List Implementation
 *
 */

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

void printList(node *h){
    if(h == NULL){cout<<"List Empty"<<endl; return;}
    while(h != NULL){
        cout<<h->data<<", ";
        h = h->next;
    }
    cout<<endl;
}

void insert_last(node **h, node **t, int x){
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    if(*h == NULL){
        *h = temp;
        *t = temp; 
    }else{
        (*t)->next = temp;
        *t = temp; 
    }   
}

void insert_first(node **h, node **t, int x){
    node *temp = new node;
    temp->data = x;
    if(*h == NULL){
        temp->next = NULL;
        *h = temp;
        *t = temp;
    }else{
        temp->next = *h;
        *h = temp;
    }
}

void insert_after(node **h, node **t, int s, int x){
    if(*h == NULL){
        insert_first(h, t, x);
    }else{
        node *srch = *h;
        node *n = new node;
        while(srch->data != s && srch->next != NULL) srch = srch->next;
        if(srch->data != s) cout<<"didn't found.'"<<x<<"': inserted to last"<<endl;
        else (*t) = n;

        n->data = x;
        n->next = srch->next;
        srch->next = n; 

        srch = NULL;
        free(srch);
    }
}

void insert_before(node **h, node **t, int s, int x){
    if(*h == NULL){
        insert_first(h, t, x);
    }else{
        node *srch = *h;
        while(srch->next->data != s && srch->next->next != NULL) srch = srch->next;
        if(srch->next->data != s){
            cout<<"didn't found.'"<<x<<"': inserted to last"<<endl;
            insert_last(h, t, x);
        }else{
            node *n = new node;
            n->data = x;
            n->next = srch->next;
            srch->next = n;
        }

        srch = NULL;
        free(srch);
    }
}

void remove(node **h, node **t, int s){
    if(*h == NULL){
        cout<<"List Empty"<<endl;
    }else{
        node *srch = *h;
        node *prev = NULL;
        while(srch->data != s && srch->next != NULL){
            prev = srch;
            srch = srch->next;
        }

        if(srch->data != s){
            cout<<"'"<<s<<"': didn't found"<<endl;
            srch = NULL;
            free(srch);
        }else{
            prev->next = srch->next;
            free(srch);
        }
        prev = NULL;
        free(prev);
    }
}

void remove_first(node **h, node **t){
    if(*h == NULL){
        cout<<"List Empty"<<endl;
    }else{
        node *temp = *h;
        *h = (*h)->next;
        free(temp);
    }
}

void remove_last(node **h, node **t){
    if(*h == NULL){
        cout<<"List Empty"<<endl;
    }else{
        node *temp = *h;
        node *prev = NULL;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        *t = prev;
        free(temp);
    }
}

void insert_sorted(node **h, node **t, int x){
    if(*h == NULL){
        insert_first(h, t, x);
        return;
    }
    if(x < (*h)->data){
        insert_first(h, t, x);
        return;
    }
    node *temp = *h;
    while(temp->next != NULL && x > temp->next->data){
        temp = temp->next;
    }
    insert_after(h, t, temp->data, x);
}

void traverse(node *h){
    if(h == NULL){
        cout<<endl;
        return;
    }
    cout<<h->data<<", ";
    traverse(h->next);
}   

void swap(node *a, node *b){
    node temp;
    temp.data = a->data;
    a->data = b->data;
    b->data = temp.data;
}

void reverse(node **h, node **t){
    node *current, *prev, *next;
    current = *h;
    prev = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *h = prev;
}

int main(){

    node *head=NULL, *tail=NULL;
    /**
    insert_last(&head, &tail, 20);
    insert_last(&head, &tail, 31);
    insert_last(&head, &tail, 22);
    insert_first(&head, &tail, 99);
    insert_last(&head, &tail, 7);
    insert_first(&head, &tail, 87);
    insert_after(&head, &tail, 100, 487);
    insert_after(&head, &tail, 487, 488);
    insert_before(&head, &tail, 999, 666);
    insert_before(&head, &tail, 666, 888);
    
    printList(head);
    remove(&head, &tail, 666);
    remove_last(&head, &tail);
    remove_last(&head, &tail);
    **/
    insert_sorted(&head, &tail, 6);
    insert_sorted(&head, &tail, 10);
    insert_sorted(&head, &tail, 300);
    insert_sorted(&head, &tail, 31);
    insert_sorted(&head, &tail, 12);
    insert_sorted(&head, &tail, 100);
    insert_sorted(&head, &tail, 1);

    traverse(head);
    reverse(&head, &tail);
    //swap(head, tail);
    //swap(head, head->next->next);
    traverse(head);
    return 0;
}