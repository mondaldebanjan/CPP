#include<iostream>
using namespace std;

int GetValue1(){
    //int a =10;  <--- This is wrong storage is in Stack, reference will destroy after function execution
    static int  a = 10;
    return a;
}

int& GetValue(){
    //int a =10;  <--- This is wrong storage is in Stack, reference will destroy after function execution
    static int  a = 10;
    return a;
}

int main(){
    int a = GetValue();
    //GetValue1()=9;  <<---- This is wrong as GetValue is returning just a value whih is not a lvalue expr
    int c = GetValue()=9;  // Can use GetVal function as lval as it is having reference as return value
    cout <<c<<endl;
}