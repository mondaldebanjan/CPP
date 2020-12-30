/*
To implement circular queue Using Linked List
1.create an empty queue
2.insert an element
3.remove an element 
4.show info
5.clear the whole queue
*/
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int d){
        data=d;
        next=NULL;
    }
};

class LLQueue{
    private:
    Node* front;
    Node* rear;
    int size;

    public:
    LLQueue():front(NULL),rear(NULL){
    }

    bool isEmpty();
    void ShowInfo();
    void enq(int item);
    void deq();
};

bool
LLQueue::isEmpty(){
    if(front==NULL)
        return true;
    else
        return false;
}


void
LLQueue::enq(int item){
    Node* newNode = new Node(item);
    if(newNode==NULL)//heap memory full case
    {
        cout<<"Cannot insert Queue is full!"<<endl;
        return;
    }
    if(front==NULL){
        front=newNode;
        rear=newNode;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
    }
    size++;
}

void
LLQueue::deq(){
    if(isEmpty())
        cout<<"Queue is empty!"<<endl;
    else
    {
        Node *temp=front;
        front=front->next;
        delete temp;
        size--;
        ShowInfo();
    }
    
}

void
LLQueue::ShowInfo(){
    cout<<"-------INFO------"<<endl;
    if(isEmpty())
        cout<<"Queue is empty!"<<endl;
    else{
        cout << "Size -> "<< size<<endl;
        Node* temp=front;
        while(temp!=NULL){
            cout<<temp->data;
            if(temp==front)
                cout << " <- front";
            if(temp==rear)
                cout << " <- rear";
            cout<<endl;
            temp=temp->next;
        }
    }
}


int main(){
    int a,item;
    LLQueue *lq = new LLQueue();
    while(true){
        cout<<"\n1.create an empty queue\n"
            "2.insert an element\n"
            "3.remove an element \n"  
            "4.show info \n"
            "5.clear the whole queue \n"<<endl;
        cin >> a;
        switch(a){
            case 2:
            {
                cout<<"\nEnter item:"<<" ";
                cin>>item;
                lq->enq(item);
                break;
            }
            case 3:lq->deq();break;
            case 4:lq->ShowInfo(); break;
        }
    }
}