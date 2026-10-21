#include <iostream>
#include "WolfSheep.h"

const int MAX_WOLF = 20;
const int MAX_SHEEP = 30;

int main()
{
    srand((unsigned int)time(nullptr));

    Wolf* wolfArr[MAX_WOLF] = { nullptr };
    Sheep* sheepArr[MAX_SHEEP] = { nullptr };

    int wolfCnt, sheepCnt, runTime;
    std::cout << "==== 青青草原生态模拟系统【实验三：继承派生】 ====\n";
    std::cout << "请输入初始化狼的数量：";
    std::cin >> wolfCnt;
    if (wolfCnt > MAX_WOLF) wolfCnt = MAX_WOLF;

    std::cout << "请输入初始化羊的数量：";
    std::cin >> sheepCnt;
    if (sheepCnt > MAX_SHEEP) sheepCnt = MAX_SHEEP;

    for (int i = 0; i < wolfCnt; i++)
    {
        wolfArr[i] = new Wolf();
    }
    for (int i = 0; i < sheepCnt; i++)
    {
        sheepArr[i] = new Sheep();
    }

    std::cout << "\n-----初始生物状态-----\n";
    for (int i = 0; i < wolfCnt; i++)
    {
        wolfArr[i]->showInfo();
    }
    for (int i = 0; i < sheepCnt; i++)
    {
        sheepArr[i]->showInfo();
    }

    std::cout << "\n输入模拟运行时间(时间片轮次): ";
    std::cin >> runTime;

    for (int t = 0; t < runTime; t++)
    {
        std::cout << "\n--------第 " << t + 1 << " 轮模拟--------\n";

        for (int w = 0; w < wolfCnt; w++)
        {
            if (wolfArr[w] == nullptr || wolfArr[w]->isDead()) continue;
            wolfArr[w]->move();

            for (int s = 0; s < sheepCnt; s++)
            {
                if (sheepArr[s] == nullptr || sheepArr[s]->isDead()) continue;
                bool ok = wolfArr[w]->hunt(sheepArr[s]);
                if (!ok)
                {
                    sheepArr[s]->runAway();
                }
            }
            wolfArr[w]->addAge();
        }

        for (int s = 0; s < sheepCnt; s++)
        {
            if (sheepArr[s] == nullptr || sheepArr[s]->isDead()) continue;
            sheepArr[s]->move();
            sheepArr[s]->addAge();
        }
    }

    std::cout << "\n====模拟结束，存活生物列表====\n";
    int liveWolf = 0;
    for (int i = 0; i < wolfCnt; i++)
    {
        if (wolfArr[i] != nullptr && !wolfArr[i]->isDead())
        {
            wolfArr[i]->showInfo();
            liveWolf++;
        }
    }
    int liveSheep = 0;
    for (int i = 0; i < sheepCnt; i++)
    {
        if (sheepArr[i] != nullptr && !sheepArr[i]->isDead())
        {
            sheepArr[i]->showInfo();
            liveSheep++;
        }
    }
    std::cout << "\n存活狼：" << liveWolf << "只，存活羊：" << liveSheep << "只\n";

    for (int i = 0; i < wolfCnt; i++)
    {
        delete wolfArr[i];
    }
    for (int i = 0; i < sheepCnt; i++)
    {
        delete sheepArr[i];
    }

    std::cout << "\n模拟结束\n";
    return 0;
}
