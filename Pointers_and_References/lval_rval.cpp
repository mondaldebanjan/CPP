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

void SetValue(int& x){}
void SetValue1(const int& x){}

int main(){
    int a = GetValue();
    //GetValue1()=9;  <<---- This is wrong as GetValue is returning just a value whih is not a lvalue expr
    int c = GetValue()=9;  // Can use GetVal function as lval as it is having reference as return value
    cout <<c<<endl;

    int x = 10;
    SetValue(x);
    //SetValue(10); <<--- This is wrong as argument has rvalue expr but sending a lvalue
    SetValue1(x); // This works as below 
    /*
    int& y = 10; << Cannot write this but can write below
    const int& y = 10; Why? because compiler breaks down the statement as below
    int temp = 10; 
    const int& y = temp;
    */
}