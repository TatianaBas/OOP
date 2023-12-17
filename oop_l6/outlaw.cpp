#include "outlaw.h"
#include "visitor.h"
#include <algorithm>

void Outlaw::save(std::ofstream& os){
    os << OutlawType << "\n";
    NPC::save(os);
}

void Outlaw::print(){
    std::cout << *this;
}

void Outlaw::get_name(std::ofstream& os){
    os << this->name << ": x = " << this->x << "; y = " << this->y << "\n";
}

void Outlaw::accept(std::shared_ptr<NPC> attacker,Visitor& visitor) {
    int res1 = 0;
    if(dynamic_cast<Elf*>(attacker.get()))
        res1 = visitor.visit(dynamic_cast<Elf*>(attacker.get()));
    
    if(res1 == 3) success = true;

}

void Outlaw::attach(std::shared_ptr<FightObserver> observer){
    NPC::observers.push_back(observer);
}

void Outlaw::detach(std::shared_ptr<FightObserver> observer){
    NPC::observers.erase(std::find(NPC::observers.begin(), NPC::observers.end(), observer));
}

std::ostream& operator<<(std::ostream& os, Outlaw& outlaw){
    os << *static_cast<NPC*>(&outlaw);
    return os;
}
