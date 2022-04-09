#include<iostream>
#include "list.h"
using namespace std;

int main(){

    List l;
    l.push_front(0); // 0
    l.push_back(2); // 0->2
    l.insert(1, 1); // 0->1->2
    l.push_back(3); // 0->1->2->3
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.deleteTail();

    Node* head = l.getHead();
    Node* temp = head;

    while(temp != NULL){
        cout<< temp->data << "->";
        temp = temp->next;
    }
    cout<< "NULL"<< endl;

    return 0;
}