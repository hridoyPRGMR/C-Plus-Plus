#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Stack{
public:
    int *arr;
    int top;
    int Size;

    Stack(int Size){
        this->Size=Size;
        arr=new int[Size];
        top=-1;
    }

    void push(int element){
        if(Size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
    }

    int peak(){
        if(top>=0 and top<Size){
            return arr[top];
        }
        else{
            cout<<"empty stack"<<endl;
            return -1;
        }
    }

    bool Empty(){
        if(top==-1)return true;
        else return false;
    }

};

int main(){

    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(3);
    st.push(3);
    st.push(3);

    cout<<st.peak()<<endl;
    st.pop();
    st.pop();
    //st.pop();
    cout<<st.peak()<<endl;

    if(st.Empty())cout<<"Empty"<<endl;
    else cout<<"Not Empty"<<endl;

return 0;
}
