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

void pushBack(Node* &node,int data){

    Node* newNode=new Node(data);

    if(node==nullptr){
        node=newNode;
        return;
    }

    Node* temp=node;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;

}

void print(Node* &node){

    Node* temp=node;

    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}

void popFront(Node* &head){

    Node* temp=head;
    head=head->next;

    delete temp;
}

void popBack(Node* &head){

    Node* end=head;
    Node* prev=nullptr;

    while(end->next){
        prev=end;
        end=end->next;
    }
    prev->next=nullptr;
    delete end;
}

void pop(Node* &head,int pos){

    Node* temp=head;
    Node* prev=head;

    for(int i=0; i<pos; i++){
        if(i==0 and pos==1){
            head=head->next;
            delete temp;
        }
        else{
            if(i==pos-1 and temp){
                prev->next=temp->next;
                delete temp;
            }
            else{
                prev=temp;
                if(prev==nullptr){
                    break;
                }
                temp=temp->next;
            }
        }
    }
}

void deleteN(Node* &head,int val){


    if(head==nullptr){
        cout<<"value not present here"<<endl;
        return;
    }

    if(head->data==val){
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    }

    deleteN(head->next,val);
}

int main(){

    Node* node=nullptr;

    pushBack(node,33);
    pushBack(node,10);
    pushBack(node,15);
    pushBack(node,34);
    pushBack(node,16);

    //deleting by pos
    /*
    popFront(node);
    popBack(node);
    pop(node,2);
    */
    print(node);

    deleteN(node,99);

    print(node);

return 0;
}

