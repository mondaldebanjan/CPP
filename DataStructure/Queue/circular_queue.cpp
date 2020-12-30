/*
To implement circular queue Using Array
1.create an empty queue
2.insert an element
3.remove an element 
4.show info
5.clear the whole queue
*/
#include<iostream>
using namespace std;

class ArrayQueue{
    private:
    int front,rear;
    int capacity;
    int *arr;

    public:
    ArrayQueue(int c){
        capacity=c;
        arr=new int[capacity];
        front=rear=-1;
    }

    bool isEmpty();
    bool isFull();
    void ShowInfo();
    void enq(int item);
    void deq();

};

bool
ArrayQueue::isEmpty(){
    if(front==-1)
        return true;
    else
        return false;
}

bool
ArrayQueue::isFull(){
    if((front==0 && rear==capacity-1 )
    || (rear==(front-1)%(capacity-1)) )    //Scenario when front is index 4 rear is index 3 capacity is 5
        return true;
    else
        return false;
}

void
ArrayQueue::enq(int item){
    if(isFull())
        cout<<"Cannot insert Queue is full!"<<endl;
    else{
        front = (front==-1) ? 0 : front;
        rear  = (rear==capacity-1) ? 0 : rear+1;  
        arr[rear]=item;
    }
    ShowInfo();
}

void
ArrayQueue::deq(){
    if(isEmpty())
        cout<<"Cannot insert Queue is full!"<<endl;
    else{
        arr[front]=0;
        if(front==rear)
            front=rear=-1;
        else
            front  = (front==capacity-1) ? 0 : front+1;  
    }
    ShowInfo();
}

void
ArrayQueue::ShowInfo(){
    if(isEmpty())
        cout<<"Queue is empty!"<<endl;
    else{
        if(isFull())
            cout<<"Queue is Full!"<<endl;
        cout<<"Eelements Are :"<<endl;
        cout<<"----------------"<<endl;
        for(int i=0;i<capacity;i++){
            cout<<arr[i]<<" ";
            if(i==front)
                cout << " <- front";
            if(i==rear)
                cout << " <- rear";
            cout <<endl;
        }
    }
}


int main(){
    int a,item;
    ArrayQueue *aq = new ArrayQueue(5);
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
                aq->enq(item);
                break;
            }
            case 3:aq->deq();break;
            case 4:aq->ShowInfo(); break;
        }
    }
}