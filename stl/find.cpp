/*
How to find a variable from a stl collection?

*/

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main(){
    vector<int> myVec{1,2,3,4};

    //if not found then hits end()
    auto found = find(myVec.begin(),myVec.end(),4);
    cout<<(found==myVec.end())<<endl;

    return 0;
}