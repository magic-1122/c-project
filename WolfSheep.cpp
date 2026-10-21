#include <iostream>
#include <cmath>
#include "WolfSheep.h"


Wolf::Wolf() :Creature()
{
    hp = 120;
    maxAge = 12;
}

Wolf::Wolf(int x_, int y_, bool male_, int age_, int hp_, int maxA_)
    :Creature(x_, y_, male_, age_, hp_, maxA_)
{

}

Wolf::~Wolf()
{

}

bool Wolf::hunt(Creature* prey)
{
    if (prey == nullptr || prey->isDead())
        return false;

    double dist = sqrt(pow(this->getX() - prey->getX(), 2) + pow(this->getY() - prey->getY(), 2));
    if (dist < 8)
    {
        prey->setHp(0);
        this->setHp(this->getHp() + 40);
        std::cout << "【事件】狼在(" << getX() << "," << getY() << ") 捕食成功！\n";
        return true;
    }
    return false;
}

void Wolf::showInfo() const
{
    std::cout << "[狼] ";
    Creature::showInfo();
    std::cout << std::endl;
}

Sheep::Sheep() :Creature()
{
    hp = 80;
    maxAge = 8;
}

Sheep::Sheep(int x_, int y_, bool male_, int age_, int hp_, int maxA_)
    :Creature(x_, y_, male_, age_, hp_, maxA_)
{

}

Sheep::~Sheep()
{

}

void Sheep::runAway()
{
    int dx = (rand() % 8) - 4;
    int dy = (rand() % 8) - 4;
    x += dx;
    y += dy;
    if (x < 0)x = 0;
    if (y < 0)y = 0;
    if (x > 50)x = 50;
    if (y > 50)y = 50;
    std::cout << "【事件】羊逃跑！\n";
}

void Sheep::showInfo() const
{
    std::cout << "[羊] ";
    Creature::showInfo();
    std::cout << std::endl;
}
