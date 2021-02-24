#ifndef BUILDER_HEADER
#define BUILDER_HEADER

#include <string>
#include <vector>

struct Element {
    std::string name;
    std::vector<Element> children;
    const size_t indent_size = 2;

    Element();
    Element(const std::string& name);
    ~Element();
    std::string str(int indentation = 0) const;
};

class Builder {
public:
    Builder();
    Builder(const std::string& root_name);
    ~Builder();

    void addChild(const std::string& name);

    std::string str() const;

private:
    Element root;
};

#endif