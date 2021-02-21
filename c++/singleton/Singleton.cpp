#include "Singleton.h"

Singleton& Singleton::Instance() {
    static Singleton instance;
    return instance;
}

Singleton::Singleton() {

}
