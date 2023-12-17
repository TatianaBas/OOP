#include "squirrel.h"
#include "visitor.h"
#include <algorithm>

void Squirrel::save(std::ofstream& os){
    os << SquirrelType << "\n";
    NPC::save(os);
}

void Squirrel::print(){
    std::cout << *this;
}

void Squirrel::get_name(std::ofstream& os){
    os << this->name << ": x = " << this->x << "; y = " << this->y << "\n";
}

void Squirrel::accept(std::shared_ptr<NPC> attacker,Visitor& visitor){
    int res2 = 0;
    if(dynamic_cast<Outlaw*>(attacker.get()))
        res2 = visitor.visit(dynamic_cast<Outlaw*>(attacker.get()));
    
    if(res2 == 1) success = true;
}

void Squirrel::attach(std::shared_ptr<FightObserver> observer){
    NPC::observers.push_back(observer);
}

void Squirrel::detach(std::shared_ptr<FightObserver> observer){
    NPC::observers.erase(std::find(NPC::observers.begin(), NPC::observers.end(), observer));
}

std::ostream& operator<<(std::ostream& os, Squirrel& squirrel){
    os << *static_cast<NPC*>(&squirrel);
    return os;
}