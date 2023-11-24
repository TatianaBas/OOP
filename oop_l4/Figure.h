#pragma once
#include <iostream>

class Figure{
   public:
    Figure() = default;
    virtual ~Figure() = default;

    virtual explicit operator double() const = 0;
};
