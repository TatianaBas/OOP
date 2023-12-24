#include "elf.h"
#include "squirrel.h"
#include "outlaw.h"

bool Elf::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Elf>(this,[](Elf*){}));
}

void Elf::print(){
    std::cout << *this;
}

void Elf::save(std::ostream &os){
    os << ElfType << "\n";
    NPC::save(os);
}

bool Elf::fight(std::shared_ptr<Squirrel> other){
    notify(other, true);
    return false;
}

bool Elf::fight(std::shared_ptr<Outlaw> other){
    notify(other, false);
    return true;
}

bool Elf::fight(std::shared_ptr<Elf> other){
    notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Elf &elf){
    os << "Elf: " << *static_cast<NPC *>(&elf) << "\n";
    return os;
}