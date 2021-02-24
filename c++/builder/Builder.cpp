#include "Builder.h"

#include <string>
#include <sstream>

Element::Element() {

}

Element::Element(const std::string& name) : name(name) {

}

Element::~Element() {
    children.clear();
}

std::string Element::str(int indentation) const {
    std::ostringstream oss;
    std::string i(indent_size * indentation, ' ');
    oss << i << name << ": " << std::endl;
    for (auto& c : children) {
        oss << c.str(indentation + 1);
    }

    return oss.str();
}

Builder::Builder() {

}

Builder::Builder(const std::string& root_name) {
    root.name = root_name;
}

Builder::~Builder() {

}

void Builder::addChild(const std::string& name) {
    Element e{name};
    root.children.push_back(e);
}

std::string Builder::str() const {
    return root.str();
}