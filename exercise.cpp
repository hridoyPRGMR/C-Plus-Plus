#include<iostream>
using namespace std;
int size=0;


class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }

    ~Node(){
        int value=this->data;
        if(this->next!=nullptr){
            delete next;
            this->next=nullptr;
        }
        cout<<"Memory free for node with data: "<<value<<endl;
    }

};

void insertAtHead(Node* &head,int data)
{
    Node* newNode=new Node(data);
    newNode->next=head;
    head=newNode;
    size++;
}

void insertAtTail(Node* &head,int data)
{

    Node* newNode=new Node(data);

    if(head==nullptr)
    {
        size++;
        head=newNode;
        return;
    }

    Node* temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    size++;
}

void insertAtPosition(Node* &head,int pos,int data)
{

    Node* newNode=new Node(data);

    if(pos<1 || pos>size+1)
    {
        cout<<"Invalid"<<endl;
        return;
    }

    if(pos==1)
    {
        newNode->next=head;
        head=newNode;
        size++;
        return;
    }
    else
    {
        Node* temp = head;
        while (--pos > 1)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
}

void deleteNode(Node* &head,int pos){

    if(pos==1){
        Node* temp=head;
        head=head->next;
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
        prev->next=curr->next;
        curr->next=nullptr;
        delete curr;

    }
}

void print(Node* &head)
{

    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}

int main()
{

    Node* node=nullptr;

    insertAtHead(node,13);
    print(node);

    insertAtTail(node,14);
    print(node);

    insertAtPosition(node,1,99);
    print(node);

    deleteNode(node,2);
    print(node);

    return 0;
}
