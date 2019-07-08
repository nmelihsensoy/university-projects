/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "queue_with_shifting.cpp"
 * 
 * Circular Queue Implementation using arrays.
 *
 */

#include <iostream>
using namespace std;

struct queue{
    int front;
    int rear;
    int ssize;
    int *d;
    int cnt;
};

queue *init(int s){
    queue *q = new queue;
    q->front = 0;
    q->rear = 0;
    q->ssize = s;
    q->d = NULL;
    q->cnt = 0;
    return q;
}

void enqueue(queue *q, int x){
    if(q->d == NULL){
        q->d = new int[q->ssize];
    }
    if(q->rear == q->ssize && q->cnt == q->ssize){
        cout<<"Overflow."<<endl;
        return;
    }
    if(q->rear == q->ssize && q->cnt < q->ssize){
        q->rear = 0;  
    }
    cout<<x<<": enqued."<<endl;
    q->d[q->rear++] = x;
    q->cnt++; 
}

void dequeue(queue *q){
    if(q->cnt <= 0){
        cout<<"Underflow."<<endl;
        return;
    }
    if(q->front == q->ssize-1){
        q->front = 0;
    }
    cout<<q->d[q->front++]<<": dequed"<<endl;
    q->cnt--;
}

void print_q(queue *q){
    if(q->cnt == 0) return;
    if(q->rear > q->front){
        for(int i=q->front; i<q->rear; i++){
            cout<<q->d[i]<<", ";
        }
    }else{
        for(int i=q->front; i<q->ssize; i++){
            cout<<q->d[i]<<", ";
        }
        for(int i=0; i<q->rear; i++){
            cout<<q->d[i]<<", ";
        }       
    }
    cout<<endl;
}

void print_q2(queue *q){
    for(int i=0; i<q->cnt; i++){
        cout<<q->d[(i+q->front)%q->ssize]<<", ";
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

    enqueue(q1, 33);
    enqueue(q1, 35);
    print_q(q1);

    dequeue(q1);
    dequeue(q1);
    dequeue(q1);
    dequeue(q1);
    print_q(q1);
    return 0;
}