/*
To implement job scheduling problem:
1. Maximises the profit picking and putting feasible jobs in time slot.
*/

#include<iostream>
#include<bits/stdc++.h>
#include <utility>

using namespace std;

struct Job{
    int id;
    int dead;
    int profit;
};

bool cmp(Job a,Job b){
    return a.profit > b.profit;
}

int findMaxDeadline(Job arr[], int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(arr[i].dead>max)
            max=arr[i].dead;
    }
    return max;
}

//return number of jobs and profit
pair<int,int> JobScheduling(Job arr[], int n) 
{ 
    int numJobs=0,totalProfit=0;
    int maxDeadline = findMaxDeadline(arr,n);
    // Sorting decending profit
    int *seqarr = new int[maxDeadline+1];
    
    sort(arr,arr+n,cmp);
    for(int i=0;i<n;i++){
        // cout<<"id :"<<arr[i].id<<" profit:"<<arr[i].profit<<endl;
        for(int j=arr[i].dead;j>=1;j--){
            if(seqarr[j]==0){
                numJobs++;
                totalProfit += arr[i].profit;
                seqarr[j]=arr[i].id;
                break;
            }
        }
    }

    cout<<"Job id picked in sequence as : "<<endl;
    for(int i=1;i<=maxDeadline;i++){
        if(seqarr[i])
            cout<<seqarr[i]<<" ";
    }
    cout<<endl;
    return make_pair(numJobs, totalProfit);
} 

int main()
{
    Job arr[]={
        Job{1,4,20},
        Job{2,1,10},
        Job{3,1,40},
        Job{4,1,30}
    };

    pair<int,int> ans = JobScheduling(arr, 4);
    cout<<ans.first<< " "<<ans.second<<endl;
    
}