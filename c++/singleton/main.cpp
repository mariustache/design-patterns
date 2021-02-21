#include <iostream>

#include "Singleton.h"
#include "BaseSingleton.h"

int main() {
    Singleton& classicSingleton = Singleton::Instance();
    Singleton& classicSingleton2 = Singleton::Instance();
    // Singleton copy_constructor = Singleton::Instance();  Error: Copy constructor is called.
    // Singleton default_constructor; Error: Private default constructor is called.

    std::cout << "Classic Singleton: Singleton::Instance() returns the same object" << std::endl;
    std::cout << "Address of first instance: " << &classicSingleton << std::endl;
    std::cout << "Address of second instance: " << &classicSingleton2 << std::endl;

    DerivedSingleton& derivedSingleton = BaseSingleton<DerivedSingleton>::Instance();
    DerivedSingleton& derivedSingleton2 = DerivedSingleton::Instance();
    // Default constructor of DerivedSingleton must be public. Otherwise, the instance in static method Instance cannot be created.
    // An alternative is to declare BaseSingleton as a friend of class DerivedSingleton.
    // DerivedSingleton default_constructor; Error: if base class not declared as friend.

    std::cout << "Derived Singleton: inherits BaseSingleton class" << std::endl;
    std::cout << "Address of first instance: " << &derivedSingleton << std::endl;
    std::cout << "Address of second instance: " << &derivedSingleton2 << std::endl;

    SecondDerivedSingleton& secondDerivedSingleton = SecondDerivedSingleton::Instance();
    SecondDerivedSingleton& secondDerivedSingleton2 = SecondDerivedSingleton::Instance();
    std::cout << "Another Derived Singleton: inherits BaseSingleton class" << std::endl;
    std::cout << "Address of first instance: " << &secondDerivedSingleton << std::endl;
    std::cout << "Address of second instance: " << &secondDerivedSingleton2 << std::endl;
    
    return 0;
}