#pragma once

#include "outlaw.h"
#include "squirrel.h"
#include "elf.h"

class Visitor{
public:
    virtual int visit(Outlaw* element) = 0;
    virtual int visit(Squirrel* element) = 0;
    virtual int visit(Elf* element) = 0;
};

class OnceVisitor: public Visitor{
public:
    int visit(Outlaw* element) override{
        return 1;
    }

    int visit(Squirrel* element) override{
        return 2;
    }

    int visit(Elf* element) override{
        return 3;
    }
};