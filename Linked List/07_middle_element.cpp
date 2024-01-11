#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *link;
};

Node *head = NULL;
void add(int d){
    Node *a = new Node();
    a->data = d;
    a->link = NULL;
    if(head == NULL){
        head = a;
    }
    else{
        Node *temp = head;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link = a;
    }
}

void showMid(){
    Node *slow = head;
    Node *fast = head;
    if(head == NULL){
        cout<<"Empty list!";
    }
    else{
        while(fast != NULL && fast->link != NULL){
            slow = slow->link;
            fast = fast->link->link;
        }
    }
    cout<<"middle element is: "<<slow->data<<endl;
}

void print(Node *temp){
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
}

int main (){
    int n,x;
    cout<<"Enter the number of node: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the value of Node"<<i+1<<": ";
        cin>>x;
        add(x);
    }
    print(head);
    showMid();
    return 0;
}