/*
To implement fractional knapsack problem:
1.Uses generic/metaprogrammed bubblesort that works with any object
2.Operator overleaded for Items = <
3.Maximises the profit using ration prifit/weight
*/

#include<iostream>
using namespace std;

struct Item{
    int value;
    int weight;

    bool operator<(const Item& a){
        if((double)value/weight<(double)a.value/a.weight)
            return true;
        else
            return false;
    }

    Item& operator=(const Item& a){
        value=a.value;
        weight=a.weight;
        return *this;
    }
};

//Bubble Sort to sort given arry..
//Expecting to overload < operator of user defined types
template <typename T>
void SortArray(T arr[],int n){
    T temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1] < arr[j]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    double sum=0;
    SortArray(arr,n);
    for(int i=n-1;i>=0;i--){
        if(arr[i].weight<W){
            sum+=arr[i].value;
            W-=arr[i].weight;
        }
        else {
            sum+=((double)arr[i].value/arr[i].weight)*W;
            break;
        }
    }
    return sum;
}

int main(){
    Item arr[]={
        Item{60,10},
        Item{100,20},
        Item{120,30}
    };

    cout<<"Maximum profit : "<< fractionalKnapsack(50, arr, 3)<<endl;
}

