#pragma once

#include "npc.h"
#include "outlaw.h"
#include "squirrel.h"
#include "elf.h"

int outlaws = 0;
int squirrels = 0;
int elves = 0;

std::shared_ptr<NPC> factory(NpcType type, int x, int y){
    std::shared_ptr<NPC> result;
    std::string name;
    switch (type){

    case OutlawType:
        ++outlaws;
        name = "Outlaw_" + std::to_string(outlaws);
        result = std::make_shared<Outlaw>(x, y, name);
        break;

    case SquirrelType:
        ++squirrels;
        name = "Squirrel_" + std::to_string(squirrels);
        result = std::make_shared<Squirrel>(x, y, name);
        break;

    case ElfType:
        ++elves;
        name = "Elf_" + std::to_string(elves);
        result = std::make_shared<Elf>(x, y, name);
        break;

    default:
        break;
    }
    return result;
}

// Для файла
std::shared_ptr<NPC> factory(std::ifstream &is){
    std::shared_ptr<NPC> result;
    std::string name;
    int type = 0;
    if (is >> type){
        switch (type){

        case OutlawType:
            ++outlaws;
            name = "Outlaw_" + std::to_string(outlaws);
            result = std::make_shared<Outlaw>(is, name);
            break;

        case SquirrelType:
            ++squirrels;
            name = "Squirrel_" + std::to_string(squirrels);
            result = std::make_shared<Squirrel>(is, name);
            break;

        case ElfType:
            ++elves;
            name = "Elf_" + std::to_string(elves);
            result = std::make_shared<Elf>(is, name);
            break;
        }
    }
    else
        std::cerr << "File error." << "\n";

    return result;
}