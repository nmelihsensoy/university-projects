/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "binary_tree.cpp"
 * 
 * Binary Tree Implementation
 *
 */

#include <iostream>

using namespace std;

struct btree{
    int data;
    btree *left;
    btree *right;
};

btree *add(btree *r, int x){
    if(r == NULL){
        r = new btree;
        r->data = x;
        r->left = NULL;
        r->right = NULL;
        return r;
    }
    if(r->data < x){
        r->right = add(r->right, x);
    }else{
        r->left = add(r->left, x);
    }
    return r;
}

void traverse_inorder(btree *r){ //Left Root Right
    if(r == NULL) return;
    traverse_inorder(r->left);
    cout<<r->data<<", ";
    traverse_inorder(r->right);
}

void traverse_preorder(btree *r){ //Root Left Right
    if(r == NULL) return;
    cout<<r->data<<", ";
    traverse_preorder(r->left);
    traverse_preorder(r->right);
}

void traverse_postorder(btree *r){ // Left Right Root
    if(r == NULL) return;
    traverse_postorder(r->left);
    traverse_postorder(r->right);
    cout<<r->data<<", ";
}

btree *max(btree *r){
    while(r->right != NULL) r = r->right;
    return r;
}

btree *max_rec(btree *r){
    if(r->right == NULL) return r;
    return max_rec(r->right);
}

btree *min(btree *r){
    while(r->left != NULL) r = r->left;
    return r;
}

btree *min_rec(btree *r){
    if(r->left == NULL) return r;
    return min_rec(r->left);
}

int count(btree *r){
    if(r == NULL) return 0;
    return count(r->right) + 1 + count(r->left);
}

btree *search(btree *r, int x){
    if(r == NULL) return r;
    if(r->data == x) return r;
    else if(r->data < x) return search(r->right, x);
    else if(r->data >= x) return search(r->left, x);
    else return NULL;
}

btree *search2(btree *r, int x){
    if(r == NULL || r->data == x) return r;
    if(r->data < x) return search2(r->right, x);
    return search2(r->left, x);
}

btree *del_leaf(btree *r, int x){
    if(r == NULL) return r;
    if(r->data == x && r->left == NULL && r->right == NULL){
        return NULL;
    }else if(r->data < x) return del_leaf(r->right, x);
    else del_leaf(r->left, x);
    return r;
}

btree *del(btree *r, int x){
    if(r == NULL) return r;
    if(r->data == x){ 
        if(r->left == NULL && r->right == NULL){ //node is a leaf
            return NULL;
        }
        if(r->left == NULL){ //node is a parent and has child on right node
            r->data = min(r->right)->data; //swap data with min node
            r->right = del(r->right, min(r->right)->data); //recurse until find x or finish tree
            return r;
        }//node is a parent and has child on left node
        r->data = max(r->left)->data; //swap data
        r->left = del(r->left, max(r->left)->data); // recurse until find x or finish tree
        return r;
    }else if(r->data < x) r->right = del(r->right, x); //if x > current node data continue to right
    else r->left = del(r->left, x);//if x < current node data continue to left
    return r;
}

int main(){

    btree *b1 = NULL;
    b1 = add(b1, 15);
    b1 = add(b1, 6);
    b1 = add(b1, 3);
    b1 = add(b1, 2);
    b1 = add(b1, 4);
    b1 = add(b1, 7);
    b1 = add(b1, 13);
    b1 = add(b1, 18);
    b1 = add(b1, 17);
    b1 = add(b1, 20);
    traverse_inorder(b1);
    cout<<endl;
    b1 = del(b1, 20);
    b1 = del(b1, 13);
    traverse_inorder(b1);
    cout<<endl;
    cout<<"Count:"<<count(b1)<<" Min:"<<min(b1)->data<<" Max:"<<max(b1)->data<<endl;
    int s = 13;
    if(search(b1, s) != NULL) cout<<s<<": found!"<<endl;
    else cout<<s<<" didn't found."<<endl;
    return 0;
}
