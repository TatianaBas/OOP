#include <gtest/gtest.h>
#include <memory>
#include "npc.h"

#include "visitor.h"
#include "observer.h"

TEST(test1, constructor){
    int x = 55;
    int y = 10;
    std::string name{"outlaw_1"};
    std::shared_ptr<NPC> outlaw = std::make_shared<Outlaw>(x,y,name);

    EXPECT_EQ(55, outlaw->x);
    EXPECT_EQ(10, outlaw->y);
    EXPECT_EQ("outlaw_1", outlaw->name);
}

TEST(test2, constructor){
    int x = 30;
    int y = 120;
    std::string name{"squirrel_1"};
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(x,y,name);

    EXPECT_EQ(30, squirrel->x);
    EXPECT_EQ(120, squirrel->y);
    EXPECT_EQ("squirrel_1", squirrel->name);
}

TEST(test3, constructor){
    int x = 5;
    int y = 1;
    std::string name{"elf_1"};
    std::shared_ptr<NPC> elf = std::make_shared<Elf>(x,y,name);

    EXPECT_EQ(5, elf->x);
    EXPECT_EQ(1, elf->y);
    EXPECT_EQ("elf_1", elf->name);
}

TEST(test4, fight){

    OnceVisitor visitor;

    int x1 = 100;
    int y1 = 100;
    std::string name1{"outlaw_1"};
    std::shared_ptr<NPC> attacker = std::make_shared<Outlaw>(x1, y1, name1);

    int x2 = 101;
    int y2 = 101;
    std::string name2{"elf_1"};
    std::shared_ptr<NPC> defender = std::make_shared<Elf>(x2, y2, name2);

    int success = true;
    defender->accept(attacker, visitor);

    EXPECT_TRUE(success);
}

TEST(test5, fight){

    OnceVisitor visitor;

    int x1 = 100;
    int y1 = 100;
    std::string name1{"outlaw_1"};
    std::shared_ptr<NPC> attacker = std::make_shared<Outlaw>(x1, y1, name1);

    int x2 = 200;
    int y2 = 250;
    std::string name2{"elf_1"};
    std::shared_ptr<NPC> defender = std::make_shared<Elf>(x2, y2, name2);

    int success = false;
    defender->accept(attacker, visitor);
    
    EXPECT_FALSE(success);
}

TEST(test6, fight){

    OnceVisitor visitor;

    int x1 = 100;
    int y1 = 100;
    std::string name1{"outlaw_1"};
    std::shared_ptr<NPC> attacker = std::make_shared<Outlaw>(x1, y1, name1);

    int x2 = 110;
    int y2 = 100;
    std::string name2{"squirrel_1"};
    std::shared_ptr<NPC> defender = std::make_shared<Squirrel>(x2, y2, name2);

    int success = false;
    defender->accept(attacker, visitor);
    
    EXPECT_FALSE(success);
}

TEST(test7, fight){

    OnceVisitor visitor;

    int x1 = 100;
    int y1 = 100;
    std::string name1{"elf_1"};
    std::shared_ptr<NPC> attacker = std::make_shared<Elf>(x1, y1, name1);

    int x2 = 110;
    int y2 = 100;
    std::string name2{"squirrel_1"};
    std::shared_ptr<NPC> defender = std::make_shared<Squirrel>(x2, y2, name2);

    int success = false;
    defender->accept(attacker, visitor);
    
    EXPECT_FALSE(success);
}