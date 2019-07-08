/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "circular_queue_array_2.cpp"
 * 
 * Circular Queue Implementation using arrays.
 *
 */

#include <iostream>
using namespace std;

struct queue{
    int front;
    int rear;
    int cnt;
    int _size;
    int *d;
};

queue *init(int s=10){
    queue *q1 = new queue;
    q1->front = 0;
    q1->rear = 0;
    q1->cnt = 0;
    q1->_size = s;
    q1->d = NULL;
    return q1;
}

void enque(queue *q, int x){
    if(q->d == NULL) q->d = new int[q->_size];
    if(q->cnt == q->_size) return;
    q->d[q->rear] = x;
    q->rear = (q->rear+1)%q->_size;
    q->cnt++;
}

void deque(queue *q){
    if(q->cnt == 0) return;
    q->d[q->front];
    q->front = (q->front+1)%q->_size;
    q->cnt--;
}

void print_q(queue *q){
    for(int i=0; i<q->cnt; i++){
        cout<<q->d[(i+q->front)%q->_size]<<", ";
    }
    cout<<endl;
}

int main(){

    queue *q1 = init();

    for(int i=0; i<10; i++){
        enque(q1, (i+1)*10);
    }
    print_q(q1);

    deque(q1);
    deque(q1);
    deque(q1);
    deque(q1);
    for(int i=0; i<5; i++){
        enque(q1, (i+1)*10);
    }
    deque(q1);
    deque(q1);
    print_q(q1);

    return 0;
}