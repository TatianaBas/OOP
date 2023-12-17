#include "elf.h"
#include "visitor.h"
#include <algorithm>

void Elf::save(std::ofstream& os){
    os << ElfType << "\n";
    NPC::save(os);
}

void Elf::print(){
    std::cout << *this;
}

void Elf::get_name(std::ofstream& os){
    os << this->name << ": x = " << this->x << "; y = " << this->y << "\n";
}

void Elf::accept(std::shared_ptr<NPC> attacker, Visitor& visitor) {
    int res = 0;
    if(dynamic_cast<Squirrel*>(attacker.get()))
        res = visitor.visit(dynamic_cast<Squirrel*>(attacker.get()));
    
    if(res == 2) success = true;
}

void Elf::attach(std::shared_ptr<FightObserver> observer){
    NPC::observers.push_back(observer);
}

void Elf::detach(std::shared_ptr<FightObserver> observer){
    NPC::observers.erase(std::find(NPC::observers.begin(), NPC::observers.end(), observer));
}

std::ostream& operator<<(std::ostream& os, Elf& elf){
    os << *static_cast<NPC*>(&elf);
    return os;
}