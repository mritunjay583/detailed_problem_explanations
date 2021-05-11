#include<bits/stdc++.h>

using namespace std;

class DoublyLinkedList{
    public:
        DoublyLinkedList *left;
        int value;
        DoublyLinkedList *right;
        DoublyLinkedList(int _value):value(_value),left(NULL),right(NULL){} //parametrized constructor
        DoublyLinkedList():left(NULL),right(NULL){} //default constructor
        ~DoublyLinkedList(){free(left);free(right);}
};

class Stack{
    public:
        DoublyLinkedList *topPointer;
        DoublyLinkedList *midPointer;
        int count;
        Stack(){
            topPointer = NULL;
            midPointer = NULL;
            count = 0;
        }
        void push(int x);
        void pop();
        int top();
        int mid();
        void deleteMid();
};

void Stack::pop(){
    if(topPointer==NULL){
        return;
    }
    DoublyLinkedList *temp = topPointer;
    topPointer = topPointer->left;
    temp->left=NULL;
    free(temp);
    if(midPointer->right!=NULL){
        if(count%2==0){
            midPointer = midPointer->left;
        }
    }
    count--;
}

void Stack::push(int x){
    if(topPointer==NULL){
        topPointer = new DoublyLinkedList(x);
        midPointer = topPointer;
        count++;
        return;
    }
    DoublyLinkedList *temp = new DoublyLinkedList(x);
    temp->left=topPointer;
    topPointer->right=temp;
    topPointer = temp;
    count++;
    if(count%2!=0){
        midPointer = midPointer->right;
    }
}
int Stack::top(){
    if(topPointer==NULL){
        return -1;
    }
    return topPointer->value;
}
int Stack::mid(){
    if(midPointer==NULL){
        return -1;
    }else{
        if(count%2==0)
            return midPointer->right->value;
        else
            return midPointer->value;
    }
}
int main(){
    Stack st;
    for(int i=1;i<=10;i++){
        st.push(i);
        cout<<"top = "<<st.top()<<endl;
        cout<<"mid = "<<st.mid()<<endl;
    }
}