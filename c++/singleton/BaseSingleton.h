#ifndef DERIVED_SINGLETON_HEADER
#define DERIVED_SINGLETON_HEADER

template <typename T>
class BaseSingleton {
public:
    static T& Instance();

protected:
    BaseSingleton() {}

private:
    BaseSingleton(const BaseSingleton&) = delete;
    BaseSingleton& operator=(const BaseSingleton&) = delete;
};

template <typename T>
T& BaseSingleton<T>::Instance() {
    static T instance;
    return instance;
}

class DerivedSingleton : public BaseSingleton<DerivedSingleton> {
    
    friend class BaseSingleton;

private:
    DerivedSingleton() {}
};

class SecondDerivedSingleton : public BaseSingleton<SecondDerivedSingleton> {

    friend class BaseSingleton;

private:
    SecondDerivedSingleton() {}
};

#endif