#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *l;
    struct node *r;
} Node;

void insert(Node *node, int data, Node *parent, int b){
    if(node == NULL){
        node = new Node;
        if(b) parent->l = node;
        else parent->r = node;
        node->data = data;
    }
    else {
        if(node->data > data) insert(node->l, data, node, 1);
        else insert(node->r, data, node, 0);
    }
}

void print(Node * node){
    if(node == nullptr)  return;
    print(node->l);
    print(node->r);
    cout << node->data << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    Node * root = new Node;
    int data; cin >> data;
    root->data = data;
    while(true){
        cin >> data;
        if(cin.eof()) break;
        if(root->data > data) insert(root->l, data, root, 1);
        else insert(root->r, data, root, 0);
    }
    print(root);
    return 0;
}