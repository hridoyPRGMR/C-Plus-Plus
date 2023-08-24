#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }

};
void insertAtHead(Node* &head,int data){
    Node* newNode=new Node(data);

    if(head==nullptr){
        head=newNode;
        return;
    }

    newNode->next=head;
    head=newNode;

}


Node* reverseLinked(Node* &head){

    if(head==nullptr || head->next==nullptr){
        return head;
    }

    Node* prev=nullptr;
    Node* curr=head;
    Node* forward=nullptr;

    while(curr!=nullptr){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }

    return prev;

}

void print(Node* &head){

    Node* temp=head;

    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){

    Node* node=nullptr;
    Node* head=node;

    insertAtHead(head,5);
    insertAtHead(head,4);
    print(head);
    insertAtHead(head,3);
    print(head);

    Node* temp=reverseLinked(head);
    print(temp);


return 0;
}
