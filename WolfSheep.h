#pragma once
#pragma once
#include "Creature.h"

class Wolf : public Creature
{
public:
    Wolf();
    Wolf(int x_, int y_, bool male_, int age_, int hp_, int maxA_);
    ~Wolf() override;

    bool hunt(Creature* prey);

    void showInfo() const override;
};

class Sheep : public Creature
{
public:
    Sheep();
    Sheep(int x_, int y_, bool male_, int age_, int hp_, int maxA_);
    ~Sheep() override;

    void runAway();
    void showInfo() const override;
};
