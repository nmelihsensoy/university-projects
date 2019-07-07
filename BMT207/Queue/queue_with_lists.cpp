/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "queue_with_lists.cpp"
 * 
 * Queue Implementation using lists
 *
 */

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

struct queue{
    node *head;
    node *tail;
    int cnt;
};

queue *init(){
    queue *n = new queue;
    n->cnt = 0;
    n->head = NULL;
    n->tail = NULL;
    return n;
}
void enqueue(queue *q, int x){
    node *n = new node;
    n->data = x;
    n->next = NULL;
    if(q->head == NULL){
        q->head = n;
        q->tail = n;
    }else{
        q->tail->next = n;
        q->tail = n;
    }
    q->cnt++;
}

void dequeue(queue *q){
    if(q->head == NULL) return;
    node *temp = q->head;
    q->head = q->head->next;
    free(temp);
}

void print_q(queue *q){
    node *iter = q->head;
    while(iter != NULL){
        cout<<iter->data<<", ";
        iter = iter->next;
    }
    cout<<endl;
}

int main(){

    queue *q1 = init();

    enqueue(q1, 15);
    enqueue(q1, 65);
    enqueue(q1, 85);
    enqueue(q1, 35);
    print_q(q1);

    dequeue(q1);
    dequeue(q1);
    print_q(q1);

    return 0;
}