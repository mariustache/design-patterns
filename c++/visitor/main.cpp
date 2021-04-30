#include <iostream>
#include <memory>

class Foo;
class Bar;

class Visitor {
public:
    virtual ~Visitor() {}
    virtual void visit(Foo* element) = 0;
    virtual void visit(Bar* element) = 0;
};

class Base {
public:
    virtual ~Base() {}
    virtual void accept(Visitor* visitor) = 0;
};

class Foo : public Base {
public:
    void accept(Visitor* visitor) {
        visitor->visit(this);
    }

    void can_be_done_in_foo() {
        std::cout << "Done in foo." << std::endl;
    }
};

class Bar : public Base {
public:
    void accept(Visitor* visitor) {
        visitor->visit(this);
    }

    void can_be_done_in_bar() {
        std::cout << "Done in bar." << std::endl;
    }
};

class PrinterVisitor : public Visitor {
public:
    void visit(Foo* element) {
        std::cout << "PrinterVisitor: Visited Foo." << std::endl;
        element->can_be_done_in_foo();
    }

    void visit(Bar* element) {
        std::cout << "PrinterVisitor: Visited Bar." << std::endl;
        element->can_be_done_in_bar();
    }
};

int main() {
    Foo foo;
    Bar bar;
    PrinterVisitor visitor;
    foo.accept(&visitor);
    bar.accept(&visitor);

    return 0;
}