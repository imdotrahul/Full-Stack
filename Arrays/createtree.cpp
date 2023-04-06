#include<iostream>
#include<algorithm>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* insertintotree(int data, Node*head)
{
    Node* newnode = new Node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    
    
    if(head == NULL)
    {
        head = newnode;
        return head;
    }
    

    else{
        Node*ptr = new Node();
        if(data)
    }
}

int main(){

}