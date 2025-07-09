#include <iostream>

void SetValue(const int& value){}

void PrintName(std::string& name){
    std::cout << name << std::endl;
}

int main(){
    int i = 10;
    const int& a = 10;
    SetValue(i);
    SetValue(10);


    // Example 2
    std::string firstName = "Sai Kiran ";
    // firstName is lvalue and sai Kiran is rvalue
    std::string lastName = "Belana";
    std::string fullName = firstName + lastName;
    // lvalue is fullName
    // rvalue is firstName + lastName

    PrintName(fullName);
    PrintName(firstName + lastName);
    // this won't work unless you define const in the
    // function as PrintName(const std::string& name)
}
