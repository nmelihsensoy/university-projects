/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "assignment1_1.cpp"
 * 
 * Convert given string infix expression to the postfix expression. After that evaluate expression and print out. 
 * Also program must be works with first in first out princible.
 *
 */

#include <iostream>
#include <sstream> 
using namespace std;

string infix_to_postfix(string infix);
int infix_evalution(string infix);
int postfix_evalution(string postfix);

/* LIST */

struct node{
    string data;
    node *next;
};

struct list{
    node *head;
    int cnt;
};

list *init_l(){
    list *l = new list;
    l->head = NULL;
    l->cnt = 0;
    return l;
}

void insert_first(list *l, string x){
    node *n = new node;
    n->data = x;
    n->next = NULL;
    l->cnt++;
    if(l->head == NULL) l->head = n;
    else{
        n->next = l->head;
        l->head = n;
    }
}

void insert(list *l, string x){
    node *n = new node;
    n->data = x;
    n->next = NULL;
    l->cnt++;
    if(l->head == NULL) { l->head = n; return; };

    node *iter = l->head;
    while(iter->next != NULL) iter = iter->next;
    iter->next = n;
}

void remove_first(list *l){
    if(l->head == NULL) return;
    node *temp = l->head;
    l->head = l->head->next;
    l->cnt--;
    free(temp);
}

node *get_last(list *l){
    node *iter = l->head;
    while(iter->next && iter->next->next != NULL) iter = iter->next;
    return iter;
}

node *get_first(list *l){
    return l->head;
}

int get_count(list *l){
    return l->cnt;
}

bool isEmpty(list *l){
    if(l->head == NULL) return true;
    return false;
}

void remove_last(list *l){
    if(l->head == NULL) return;
    if(l->head->next == NULL){
        free(l->head);
        l->head = NULL;
        return;
    }

    node *iter = get_last(l);
    l->cnt--;
    free(iter->next);
    iter->next = NULL;
}

void push(list *l, string x){
    insert_first(l, x);
}

string pop(list *l){
    string t = l->head->data;
    remove_first(l);
    return t;
}

void enque(list *l, string x){
    insert(l, x);
}

string deque(list *l){
    string t = l->head->data;
    remove_first(l);
    return t;
}

void print_list(list* l){
    node *iter = l->head;
    while(iter != NULL){
        cout<<iter->data<<", ";
        iter = iter->next;
    }
    cout<<endl;
}

string list_str(list *l){
    string s="";
    node *iter = l->head;
    while(iter != NULL){
        s += iter->data;
        iter = iter->next;
    }
    return s;
}

/* LIST END */

/* OPERATION QUEUE */

struct operation{
    string infix;
    string postfix;
    int infix_result;
    int postfix_result;
    operation *next;
};

struct op_queue{
    operation *front;
    operation *rear;
    int cnt;
};

op_queue *init_op_q(){
    op_queue *n = new op_queue;
    n->front = NULL;
    n->rear = NULL;
    n->cnt = 0;
    return n;
}

void add_to_queue(op_queue *oq, string inf_data){
    operation *n = new operation;
    n->infix = inf_data;
    n->postfix = "";
    n->infix_result = 0;
    n->postfix_result = 0;
    n->next = NULL;

    cout<<"Siraya Eklendi: "<<inf_data<<endl;
    oq->cnt++;

    if(oq->front == NULL){
        oq->front = n;
        oq->rear = n;
        return;
    }else{
        oq->rear->next = n;
        oq->rear = n;
    }

}

void do_operation(op_queue *oq){
    if(oq->front == NULL){
        //cout<<"Sirada bekleyen islem yok."<<endl;
        cout<<"There is no operation waiting in queue."<<endl;
        return;
    }
    
    operation *temp = oq->front;
    temp->postfix = infix_to_postfix(temp->infix);
    temp->infix_result = infix_evalution(temp->infix);
    temp->postfix_result = postfix_evalution(temp->postfix);

    //cout<<"Yapilan İslem: "<<temp->infix<<" Infix Sonuc:"<<temp->infix_result<<" Postfix: "<<temp->postfix<<" Postfix Sonuc:"<<temp->postfix_result<<" ";
    cout<<"Operation: "<<temp->infix<<" Infix Result:"<<temp->infix_result<<" Postfix: "<<temp->postfix<<" Postfix Result:"<<temp->postfix_result<<" ";

    //if(oq->cnt-1 != 0) cout<<"Bekleyen Islem: "<<oq->cnt-1;
    //else cout<<"Bekleyen Islem: Yok";
    
    if(oq->cnt-1 != 0) cout<<"Waiting Operation: "<<oq->cnt-1;
    else cout<<"There is no waiting operation.";

    cout<<endl;
    oq->cnt--;
    oq->front = oq->front->next;
    free(temp);
}

/* OPERATION QUEUE END */

bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isOperand(char c){
    return !isOperator(c) && c != '(' && c != ')';
}

int precedence(char c){
    if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    else if(c == '^') return 3;
    return 0;
}

/*
    +, - : 1
    *, / : 2
    ^    : 3
*/
int precedence(string s){
    if(s.compare("+") == 0 || s.compare("-") == 0) return 1;
    else if(s.compare("*") == 0 || s.compare("/") == 0) return 2;
    else if(s.compare("^") == 0) return 3;
    return 0;
}

int do_math(int a, int b, char c){
    switch(c){
        case '+' : return a + b; break;
        case '-' : return a - b; break;
        case '*' : return a * b; break;
        case '/' : return a / b; break;
        default : return 0;
    }
}

string infix_to_postfix(string infix){
    list *st = init_l();
    string output="";
    for(int i=0; i<infix.length(); i++){
        if(isOperand(infix[i])){ //if operand append to the output string
            output += infix[i];
            continue;
        }

        if(infix[i] == '('){ //if incoming char is '(' push to the stack
            push(st, "(");
            continue;
        }

        if(infix[i] == ')'){ //if incoming char is ')'
            while(!isEmpty(st) && st->head->data.compare("(") != 0){ //pop and append to the output string until find a '('
                output += pop(st);
            }
            pop(st); //discard '(' that we found
            continue;
        }

        if(isOperator(infix[i])){
            if(isEmpty(st) || st->head->data.compare("(") == 0){ //stack is empty or has '(' on the top 
                string op = "";
                op += infix[i]; 
                push(st, op); //push the operator
            }else{
                while(!isEmpty(st) && st->head->data.compare("(") != 0 
                        && precedence(st->head->data) >= precedence(infix[i])){
                    output += pop(st);  //pop and append to the string until see '('
                }
                string op = "";
                op += infix[i];
                push(st, op);
            }
        }
    }

    while(!isEmpty(st)){
        output += pop(st);
    }

   return output;
}

void evalution_step(list *operand_s, list *operator_s){
    stringstream ss;
    ss.str("");
    ss<<do_math(stoi(pop(operand_s)), stoi(pop(operand_s)), pop(operator_s)[0]);
    push(operand_s, ss.str());
}

int infix_evalution(string infix){
    list *operator_s = init_l();
    list *operand_s = init_l();
    stringstream ss;
    
    for(int i=0; i<infix.length(); i++){
        if(isOperand(infix[i])){ //if operand append to the output string
            ss.str("");
            ss<<infix[i];
            push(operand_s, ss.str());
            continue;
        }

        if(infix[i] == '('){ //if incoming char is '(' push to the stack
            push(operator_s, "(");
            continue;
        }

        if(infix[i] == ')'){ //if incoming char is ')'
            while(!isEmpty(operator_s) && operator_s->head->data.compare("(") != 0){ //pop and append to the output string until find a '('
                evalution_step(operand_s, operator_s);
            }
            pop(operator_s); //discard '(' that we found
            continue;
        }

        if(isOperator(infix[i])){
            if(isEmpty(operator_s) || operator_s->head->data.compare("(") == 0){ //stack is empty or has '(' on the top 
                string op = "";
                op += infix[i]; 
                push(operator_s, op); //push the operator
            }else{
                while(!isEmpty(operator_s) && operator_s->head->data.compare("(") != 0 
                        && precedence(operator_s->head->data) >= precedence(infix[i])){
                    evalution_step(operand_s, operator_s);
                }
                string op = "";
                op += infix[i];
                push(operator_s, op);
            }
        }
    }

    while(!isEmpty(operator_s)){
        evalution_step(operand_s, operator_s);
    }

   return stoi(operand_s->head->data);
}

int postfix_evalution(string postfix){
    list *st = init_l();
    stringstream ss;

    for(int i=0; i<postfix.length(); i++){
        if(isOperand(postfix[i])){
            ss.str("");
            ss<<postfix[i];
            push(st, ss.str());
            continue;
        }
        
        if(isOperator(postfix[i])){
            ss.str("");
            ss<<do_math(stoi(pop(st)), stoi(pop(st)), postfix[i]);
            push(st, ss.str());
            continue;
        }
    }
    return stoi(st->head->data);
}

int main(){
    /* EXAMPLE */
    list *l1 = init_l();
    list *st1 = init_l();
    list *que1 = init_l();

    op_queue *oq = init_op_q();
    add_to_queue(oq, "4*(9-(2+3))");
    add_to_queue(oq, "1*(9-(2+3))");
    add_to_queue(oq, "(1+2)*(2+3)*(4-2)");
    cout<<endl;
    do_operation(oq);
    do_operation(oq);
    do_operation(oq);
    cout<<endl<<endl;
    /* EXAMPLE END */
    
    string user_infix;
    char user_choice;
    while(user_choice != '4'){
        //cout<<"Sirada "<<oq->cnt<<" islem var."<<endl;
        //cout<<"1-Siraya Ekle // 2-Sıradakini Hesapla // 3-Tumunu Hesapla // 4-Cikis"<<endl;
        //cout<<"Secim: ";
        cout<<oq->cnt<<" operation in queue."<<endl;
        cout<<"1-Enque // 2-Evaluate // 3-Evaluate All // 4-Exit"<<endl;
        cout<<"Choice: ";
        cin>>user_choice;

        cout<<endl;
        if(user_choice == '1'){
            //cout<<"Infix Ifadeyi Giriniz(Bosluksuz): ";
            cout<<"Enter infix expression: ";
            cin>>user_infix;
            add_to_queue(oq, user_infix);
        }else if(user_choice == '2'){
            do_operation(oq);
        }else if(user_choice == '3'){
            for(int i=0; i<oq->cnt; i++){
                do_operation(oq);
            }
        }
        cout<<endl;
    }

    return 0;
}