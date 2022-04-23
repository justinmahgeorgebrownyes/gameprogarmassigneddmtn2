#pragma once
#include "Furniture.h"
class Door :
    public Furniture
{

private:
    bool m_locked;

public:
    void use();
    void enter();
    void unlock();
    void lock();

};

