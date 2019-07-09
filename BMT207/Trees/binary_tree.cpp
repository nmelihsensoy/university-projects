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

void traverse_inorder(btree *r){
    if(r == NULL) return;
    traverse_inorder(r->left);
    cout<<r->data<<", ";
    traverse_inorder(r->right);
}

void traverse_preorder(btree *r){
    if(r == NULL) return;
    cout<<r->data<<", ";
    traverse_preorder(r->left);
    traverse_preorder(r->right);
}

void traverse_postorder(btree *r){
    if(r == NULL) return;
    traverse_postorder(r->left);
    traverse_postorder(r->right);
    cout<<r->data<<", ";
}

btree *max(btree *r){
    while(r->right != NULL) r = r->right;
    return r;
}

btree *min(btree *r){
    while(r->left != NULL) r = r->left;
    return r;
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
    r->left = del_leaf(r->left, x);
    r->right = del_leaf(r->right, x);
    if(r->data == x && r->left == NULL && r->right == NULL){
        free(r);
        return NULL;
    }
    return r;
}


btree *del_leaf2(btree *r, int x){
    if(r == NULL) return r;
    if(r->data == x){
        if(r->left == NULL && r->right == NULL){
            free(r);
            return NULL;
        }
    }else if(r->data < x) r->right = del_leaf2(r->right, x);
    else r->left = del_leaf2(r->left, x);
    return r;
}

int main(){

    btree *b1 = NULL;
    b1 = add(b1, 15);
    add(b1, 16);
    add(b1, 20);
    add(b1, 18);
    add(b1, 23);
    add(b1, 5);
    add(b1, 12);
    add(b1, 13);
    add(b1, 3);
    add(b1, 10);
    add(b1, 6);
    add(b1, 7);
    traverse_inorder(b1);
    cout<<endl;
    del_leaf2(b1, 13);
    traverse_inorder(b1);
    cout<<endl;
    cout<<"Count:"<<count(b1)<<" Min:"<<min(b1)->data<<" Max:"<<max(b1)->data<<endl;
    if(search(b1, 13) != NULL) cout<<"Found!"<<endl;
    else cout<<"Didn't found."<<endl;
    return 0;
}
