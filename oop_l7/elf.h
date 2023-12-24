#pragma once
#include "npc.h"

struct Elf: public NPC{
public:
    Elf(int x, int y): NPC(ElfType, x, y){}
    Elf(std::istream &is): NPC(ElfType, is){}

    void print() override;
    bool accept(std::shared_ptr<NPC> visitor) override;
    void save(std::ostream &os) override;
    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<Outlaw> other) override;
    bool fight(std::shared_ptr<Elf> other) override;

    friend std::ostream &operator<<(std::ostream &os, Elf &elf);
};