#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

class Creature
{
protected:
    int x;
    int y;
    bool isMale;
    int age;
    int hp;
    int maxAge;
public:
    Creature();
    Creature(int x_, int y_, bool male_, int age_, int hp_, int maxA_);
    virtual ~Creature();

    int getX() const;
    int getY() const;
    bool getGender() const;
    int getAge() const;
    int getHp() const;

    void setPos(int nx, int ny);
    void setHp(int h);
    void addAge();

    void move();

    virtual void showInfo() const;
    bool isDead() const;
};

