#include <gtest/gtest.h>
#include <memory>
#include "npc.h"
#include "squirrel.h"
#include "outlaw.h"
#include "elf.h"

TEST(test_01, Elf_constructor){
    int x = 60;
    int y = 100;

    std::shared_ptr<NPC> a;
    a = std::make_shared<Elf>(x, y);

    EXPECT_EQ((a->position()).first,60);
    EXPECT_EQ((a->position()).second,100);
}

TEST(test_03, Elf_constructor){
    int x = 50;
    int y = 50;

    std::shared_ptr<NPC> a;
    a = std::make_shared<Elf>(x, y);
    EXPECT_EQ(ElfType,a->get_type());
}

TEST(test_04, Elf_constructor){
    int x = 100;
    int y = 100;

    std::shared_ptr<NPC> a;
    a = std::make_shared<Elf>(x, y);
    EXPECT_TRUE(a->is_alive());
}

TEST(test_07, Squirrel_constructor){
    int x = 100;
    int y = 100;

    std::shared_ptr<NPC> a;
    a = std::make_shared<Squirrel>(x, y);

    EXPECT_EQ((a->position()).first,100);
    EXPECT_EQ((a->position()).second,100);
}

TEST(test_09, Squirrel_constructor){
    int x = 100;
    int y = 100;

    std::shared_ptr<NPC> a;
    a = std::make_shared<Squirrel>(x, y);
    EXPECT_EQ(SquirrelType,a->get_type());
}

TEST(test_10, Squirrel_constructor){
    int x = 60;
    int y = 90;

    std::shared_ptr<NPC> a;
    a = std::make_shared<Squirrel>(x, y);
    EXPECT_TRUE(a->is_alive());
}

TEST(test_13, Outlaw_constructor){
    int x = 100;
    int y = 90;

    std::shared_ptr<NPC> a;
    a = std::make_shared<Outlaw>(x, y);

    EXPECT_EQ((a->position()).first,100);
    EXPECT_EQ((a->position()).second,90);
}

TEST(test_15, Outlaw_constructor){
    int x = 100;
    int y = 100;

    std::shared_ptr<NPC> a;
    a = std::make_shared<Outlaw>(x, y);
    EXPECT_EQ(OutlawType,a->get_type());
}

TEST(test_16, Outlaw_constructor){
    int x = 100;
    int y = 100;

    std::shared_ptr<NPC> a;
    a = std::make_shared<Outlaw>(x, y);
    EXPECT_TRUE(a->is_alive());
}