#include "squirrel.h"
#include "outlaw.h"
#include "elf.h"

bool Squirrel::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Squirrel>(this,[](Squirrel*){}));
}

void Squirrel::print(){
    std::cout << *this;
}

void Squirrel::save(std::ostream &os){
    os << SquirrelType << "\n";
    NPC::save(os);
}

bool Squirrel::fight(std::shared_ptr<Squirrel> other){
    notify(other, false);
    return false;
}

bool Squirrel::fight(std::shared_ptr<Outlaw> other){
    notify(other, true);
    return false;
}

bool Squirrel::fight(std::shared_ptr<Elf> other){
    notify(other, false);
    return true;
}

std::ostream &operator<<(std::ostream &os, Squirrel &squirrel){
    os << "Squirrel: " << *static_cast<NPC *>(&squirrel) << "\n";
    return os;
}