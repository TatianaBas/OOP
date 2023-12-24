#pragma once
#include "npc.h"

struct Squirrel: public NPC{
public:
    Squirrel(int x, int y): NPC(SquirrelType, x, y){}
    Squirrel(std::istream &is): NPC(SquirrelType, is){}

    void print() override;
    bool accept(std::shared_ptr<NPC> visitor) override;
    void save(std::ostream &os) override;
    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<Outlaw> other) override;
    bool fight(std::shared_ptr<Elf> other) override;
    
    friend std::ostream &operator<<(std::ostream &os, Squirrel &squirrel);
};