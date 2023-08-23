#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int data){
        this->data=data;
        this->prev=nullptr;
        this->next=nullptr;
    }

    //for deletion
    ~Node(){
        int value=this->data;
        if(next!=nullptr){
            delete next;
            next=nullptr;
        }
        cout<<"memory is free for node with data: "<<value<<endl;
    }

};

//get linkedlist size
int getLength(Node* &head){
    int len=0;
    Node* temp=head;
    while(temp!=nullptr){
        len++;
        temp=temp->next;
    }
    return len;
}

//print LinkedList
void print(Node* &head){
    Node *temp=head;

    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//Insert at Head
void insertAtHead(Node* &head,Node* &tail,int data){

    Node* newNode=new Node(data);

    if(head==nullptr){
        head=newNode;
        tail=newNode;
        return;
    }

    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}

//Insert at tail
void insertAtTail(Node* &head,Node* &tail,int data){

    Node* newNode=new Node(data);

    if(tail==nullptr){
        tail=newNode;
        head=newNode;
        return;
    }

    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;

}

//Insert at position
void insertAtPosition(Node* &head,Node* &tail,int pos,int data){


    Node* nodeToInsert=new Node(data);
    cout<<nodeToInsert->data<<" <->inserted at position->"<<pos<<endl;

    if(pos==1){
        insertAtHead(head,tail,data);
        return ;
    }

    Node* temp=head;
    int cnt=1;
    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }

    if(temp->next==nullptr){
        insertAtTail(head,tail,data);
        return;
    }

    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;

}

void deleteNode(Node* &head,Node* &tail,int pos){

    if(pos==1){
        Node* temp=head;
        temp->next->prev=nullptr;
        head=temp->next;
        temp->next=nullptr;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prev=nullptr;
        int cnt=1;
        while(cnt<pos){
            prev=curr;
            curr=curr->next;
            cnt++;
        }

        curr->prev=nullptr;
        prev->next=curr->next;

        ///to handle tail
        if(prev->next==nullptr){
            tail=prev;
        }

        curr->next=nullptr;
        delete curr;
    }

}

int main(){

    Node* node=nullptr;
    Node* head=node;
    Node* tail=node;


    //insert at Head
    insertAtHead(head,tail,9);
    print(head);
    cout<<"Size: "<<getLength(head)<<endl;

    insertAtHead(head,tail,8);
    print(head);
    cout<<"Size: "<<getLength(head)<<endl;

    //insert at tail
    insertAtTail(head,tail,11);
    print(head);
    cout<<"size: "<<getLength(head)<<endl;

    //insert at position
    insertAtPosition(head,tail,3,100);
    print(head);
    cout<<"Size: "<<getLength(head)<<endl;

    //delete
    deleteNode(head,tail,4);
    print(head);
    cout<<"Size: "<<getLength(head)<<endl;

    insertAtPosition(head,tail,1,99);
    print(head);
    cout<<"Size: "<<getLength(head)<<endl;

    cout<<"head: "<<head->data<<endl;
    cout<<"tail: "<<tail->data<<endl;


return 0;
}
