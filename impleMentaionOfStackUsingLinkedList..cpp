#include<bits/stdc++.h>
using namespace std;

struct Node{
public:
    int data;
    Node *next;

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

class Stack{
    Node* top;
public:
    Stack(){
        top=nullptr;
    }

    void push(int element){
        Node* temp=new Node(element);
        temp->next=top;
        top=temp;
    }

    void pop(){
        Node* temp;
        if(top==nullptr){
            cout<<"Stack underflow"<<endl;
            exit(1);
        }
        else{
            temp=top;
            top=top->next;
            free(temp);
        }
    }

    bool Empty(){
        return top==nullptr;//if top is null return true;
    }

    int peak(){
        if(!Empty()){
            return top->data;
        }
        else{
            exit(1);
        }
    }

    void print(){
        Node* temp;
        if(top==nullptr){
            cout<<"empty stack"<<endl;
            exit(1);
        }
        else{
            temp=top;
            while(temp!=nullptr){
                cout<<temp->data<<" ";
                temp=temp->next;
                if(temp!=nullptr){
                    cout<<"->";
                }
            }
        }
    }

};

int main(){

    Stack st;

    //st.push(1);
    //st.push(2);
    st.pop();
    st.push(3);

    st.print();


return 0;
}
