#ifndef SINGLETON_HEADER
#define SINGLETON_HEADER

class Singleton {
public:
    static Singleton& Instance();
private:
    Singleton();
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

#endif