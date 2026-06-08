#include <iostream>
using namespace std;

class Base { 
public:
    virtual ~Base() {}
    virtual void foo() {} 
};

class Derived : public Base { 
public:
    void bar() {cout << "Derived::bar() called\n"; } 
};

int main() {
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    return 0;
}
