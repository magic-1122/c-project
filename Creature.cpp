#include "Creature.h"

Creature::Creature()
{
    x = rand() % 50;
    y = rand() % 50;
    isMale = rand() % 2;
    age = 0;
    hp = 100;
    maxAge = 15;
}

Creature::Creature(int x_, int y_, bool male_, int age_, int hp_, int maxA_)
    :x(x_), y(y_), isMale(male_), age(age_), hp(hp_), maxAge(maxA_)
{

}

Creature::~Creature()
{

}

int Creature::getX() const { return x; }
int Creature::getY() const { return y; }
bool Creature::getGender() const { return isMale; }
int Creature::getAge() const { return age; }
int Creature::getHp() const { return hp; }

void Creature::setPos(int nx, int ny)
{
    x = nx;
    y = ny;
}

void Creature::setHp(int h)
{
    hp = h;
    if (hp < 0)hp = 0;
}

void Creature::addAge()
{
    age++;
}

void Creature::move()
{
    int dx = (rand() % 5) - 2;
    int dy = (rand() % 5) - 2;
    x += dx;
    y += dy;
    if (x < 0)x = 0;
    if (y < 0)y = 0;
    if (x > 50)x = 50;
    if (y > 50)y = 50;
}

void Creature::showInfo() const
{
    std::cout << "位置(" << x << "," << y << ") "
        << "性别:" << (isMale ? "雄" : "雌")
        << " 年龄:" << age
        << " 生命:" << hp;
}

bool Creature::isDead() const
{
    if (hp <= 0 || age >= maxAge)
        return true;
    return false;
}
