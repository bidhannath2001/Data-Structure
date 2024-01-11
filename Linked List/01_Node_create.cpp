#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *link;
};

Node *head = NULL; // Global
int main() {
    Node *First = new Node();
    Node *Second = new Node();
    Node *Third = new Node();

    First->data = 1;
    Second->data = 2;
    Third->data = 3;

    head = First;
    First->link = Second;
    Second->link = Third;
    Third->link = NULL;

    Node *temp = head;      //coping the head in temp due to move this.

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->link;
    }

    return 0;
}
