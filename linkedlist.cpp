#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int value){
        data=value;
        next=nullptr;
    }
};

void insertatstart(Node* &head,int value){
    Node* newNode=new Node(value);
    newNode->next=head;
    head=newNode;
}

void insertatend(Node* &head,int value){
    Node* newNode=new Node(value);
    if(head==nullptr){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
}

void insertatposition(Node* &head,int position,int value){
    Node* newNode=new Node(value);
    if(position==0){
        newNode->next=head;
        head=newNode;
        return;
    }
    Node* temp=head;
    for(int i=1;i<position;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

void deleteatstart(Node* &head){
    if(head==nullptr){
        return;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
}

void deleteatend(Node* &head){
    if(head==nullptr){
        return;
    }
    if(head->next==nullptr){
        delete head;
        head=nullptr;
        return;
    }
    Node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
}

void deleteatposition(Node* &head,int position){
    if(head==nullptr){
        return;
    }
    if(position==0){
        deleteatstart(head);
        return;
    }
    Node* temp=head;
    for(int i=1;i<position;i++){
        temp=temp->next;
    }
    Node* del=temp->next;
    temp->next=del->next;
    delete del;
}

void display(Node* &head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* head=new Node(10);
    Node* newNode1=new Node(20);
    head->next=newNode1;
    Node* newNode2=new Node(30);
    newNode1->next=newNode2;

    insertatstart(head,5);
    insertatend(head,40);
    insertatposition(head,2,15);

    deleteatstart(head);
    deleteatend(head);
    deleteatposition(head,1);

    display(head);
    return 0;
}
