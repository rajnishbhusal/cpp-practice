#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }

        ~Node(){
            if(next!=NULL){
			    delete next;
		    }
            cout<<"Deleting Node with Data "<< data <<endl;
        }
};

class List{
    public:
        Node* head;
        Node* tail;

        List(){
            head = NULL;
            tail = NULL;
        }

        Node* getHead(){
            return head;
        }

        void push_front(int val){
            Node* n = new Node(val);
            if (head==NULL){
                head = n;
                tail = n;
            }
            else{
                n->next = head;
                head = n;
            }
        }

        void push_back(int val){
            Node* n = new Node(val);
            if (head == NULL){
                head = n;
                tail = n;
            }
            else{
                tail->next = n;
                tail = n;
            }
        }

        void insert(int val, int pos){
            if (pos==0){
                push_front(val);
            }
            else{
                Node* n = new Node(val);
                Node* temp = head;
                for (int i=1; i<pos; i++){
                    temp = temp->next;
                }
                n->next = temp->next;
                temp->next = n; 
            }
        }

        void nodeDelete(int pos){
            if (pos==0){
                Node* temp = head;
                head = head->next;
                temp->next = NULL;
                delete temp;
            }
            else{
                Node* temp1=head;
                for (int i=1; i<pos; i++){
                    temp1 = temp1->next;
                }
                Node* temp2 = temp1->next;
                Node* temp3 = temp2->next;
                temp1->next = temp3;
                temp2->next = NULL;
                delete temp2;
            }
        }

        void deleteTail(){
            Node* temp = head;
            while(temp->next->next!=NULL){
                temp = temp->next;
            }
            Node* temp2 = temp->next;
            temp->next = NULL;
            delete temp2;
        }

        ~List(){
            if(head!=NULL){
			    delete head;
			    head = NULL;
		    }
        }
};