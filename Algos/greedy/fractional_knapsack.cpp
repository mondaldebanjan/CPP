/*
To implement fractional knapsack problem:
1.Uses generic/metaprogrammed bubblesort that works with any object
2.Operator overleaded for Items = <
3.Maximises the profit using ration prifit/weight
*/

#include<iostream>
#include<algorithm>
#include <chrono>


using namespace std;
using namespace std::chrono; 

struct Item{
    int value;
    int weight;

    bool operator>(const Item& a){
        if((double)value/weight>(double)a.value/a.weight)
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
            if(arr[j+1] > arr[j]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

bool cmp(struct Item a, struct Item b) 
{ 
    double r1 = (double)a.value / (double)a.weight; 
    double r2 = (double)b.value / (double)b.weight; 
    return r1 > r2; 
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    double sum=0;
    //Sort Using bubblesort
    SortArray(arr,n);
    //sort Using stl sort
    //sort(arr,arr+n,cmp);
    for(int i=0;i<n;i++){
        if(arr[i].weight<=W){
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

    auto start = high_resolution_clock::now(); 
  
    // Call the function, here sort() 
    cout<<"Maximum profit : "<< fractionalKnapsack(50, arr, 3)<<endl;

    // Get ending timepoint 
    auto stop = high_resolution_clock::now(); 
  
    // Get duration. Substart timepoints to  
    // get durarion. To cast it to proper unit 
    // use duration cast method 
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 

   
}

