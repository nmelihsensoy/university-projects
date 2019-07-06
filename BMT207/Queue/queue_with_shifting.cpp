/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "queue_with_shifting.cpp"
 * 
 * Queue Implementation using arrays with array shifting 
 *
 */

#include <iostream>
using namespace std;

struct queue{
    int front;
    int rear;
    int ssize;
    int *d;
};

queue *init(int s){
    queue *q = new queue;
    q->front = 0;
    q->rear = 0;
    q->ssize = s;
    q->d = NULL;
    return q;
}

void enqueue(queue *q, int x){
    if(q->rear == q->ssize){
        cout<<"Overflow"<<endl;
        return;
    }
    if(q->d == NULL){
        q->d = new int[q->ssize];
    }
    q->d[q->rear++] = x;
}

void dequeue(queue *q){
    if(q->front == q->rear){
        cout<<"Underflow"<<endl;
    }else{
        q->d[++q->front];
        for(int i=q->front; i<q->rear; i++){
            q->d[i-q->front] = q->d[i];
        }
        q->rear -= q->front;
        q->front = 0;
    }
}

void print_q(queue *q){
    if(q->rear == 0) return;
    for(int i = q->front; i<q->rear; i++){
        cout<<q->d[i]<<", ";
    }
    cout<<endl;
}

int main(){

    queue *q1 = init(4);

    enqueue(q1, 15);
    enqueue(q1, 17);
    enqueue(q1, 22);
    enqueue(q1, 32);
    print_q(q1);

    dequeue(q1);
    dequeue(q1);
    dequeue(q1);
    dequeue(q1);

    enqueue(q1, 78);
    enqueue(q1, 67);
    enqueue(q1, 87);
    enqueue(q1, 98);
    print_q(q1);

    return 0;
}