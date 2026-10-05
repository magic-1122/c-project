#include <iostream>
#include <vector> 
using namespace std;

class Animal
{
protected:
    int age;
    bool gender;
    int hp;
    double x, y;
    bool alive;
public:
    Animal(int a, bool g, int h, double px, double py)
        : age(a), gender(g), hp(h), x(px), y(py), alive(true) {}
    virtual void showInfo() const = 0;
    bool isAlive() const
    {
        return alive;
    }
};

class Sheep : public Animal
{
public:
 
    Sheep(int a, bool g, int h, double px, double py)
        : Animal(a, g, h, px, py) {}
    void beAttacked(int damage)
    {
        hp -= damage;
        if (hp <= 0)
        {
            alive = false;
            hp = 0;
        }
    }
    void showInfo() const override
    {
        cout << "【羊】年龄:" << age << "，血量:" << hp;
        cout << "，位置(" << x << "," << y << ")，";
        if (alive)
            cout << "存活" << endl;
        else
            cout << "已死亡" << endl;
    }
};

class Wolf : public Animal
{
public:
    Wolf(int a, bool g, int h, double px, double py)
        : Animal(a, g, h, px, py) {}
    void eat(Sheep sheep)
    {
        if (!alive)
        {
            cout << "狼已经死亡，无法捕食！\n";
            return;
        }
        if (!sheep.isAlive())
        {
            cout << "这只羊已经死了，不能吃\n";
            return;
        }
        sheep.beAttacked(100);
        if (!sheep.isAlive())
        {
            hp += 30;
            cout << "狼成功捕获羊，恢复30点血量！\n";
        }
        else
        {
            cout << "羊受伤逃跑，没有被吃掉\n";
        }
    }
    void showInfo() const  override
    {
        cout << "【狼】年龄:" << age << "，血量:" << hp;
        cout << "，位置(" << x << "," << y << ")，";
        if (alive)
            cout << "存活" << endl;
        else
            cout << "已死亡" << endl;
    }
};

class AnimalManager
{
private:
    vector<Animal*> animalList;
public:
    void addAnimal(Animal* pAnimal)
    {
        animalList.push_back(pAnimal);
    }
    void showAllAnimal()
    {
        for (auto animal : animalList)
        {
            animal->showInfo();
        }
    }
};

int main()
{
    AnimalManager manager;
    Wolf w(3, true, 60, 10, 10);
    Sheep s(2, false, 80, 11, 10);
    manager.addAnimal(&w);
    manager.addAnimal(&s);

    cout << "捕食前状态为" << endl;
    w.showInfo();
    s.showInfo();
    cout << "\n狼发起捕食" << endl;
    w.eat(s);
    cout << "\n捕食后状态为" << endl;
    w.showInfo();
    s.showInfo();
    return 0;
}

