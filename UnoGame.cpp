#include "UnoCard.h"
#include "UnoHand.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

int main()
{
//    UnoHand * obj = new UnoHand;

//    obj->insertOne(5, "red");
//    obj->insertOne(9, "blue");
////    obj->removeOne(5, "red");
//    obj->print();

    int playerNum;

    while (1)
    {
        std::cout << "Enter number of players: ";
        std::cin >> playerNum;
        std::cout << std::endl;

        if (!(playerNum >= 2 && playerNum <= 4))
        {
            continue;
        }

        break;
    }

    UnoHand *obj = new UnoHand[playerNum];
    std::string client[playerNum];

    std::string initial;
    int count = 0;

    while (count < playerNum)
    {
        std::cout << "Enter player Initial: ";
        std::cin >> initial;
        std::cout << std::endl;

        if (initial.size() != 2)
        {
            continue;
        }
        client[count] = initial;

        count++;
    }

    std::string colors[4] = {"blue", "green", "red", "yellow"};

    srand(time(NULL));

    for (int i = 0; i < playerNum; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            obj[i].insertOne(rand() % 10, colors[rand() % 4]);
        }
    }

    int turn = rand() % playerNum;

    std::string upColor = colors[rand() % 4];
    int upValue = rand() % 10;

    while (1)
    {
        for (int i = 0; i < playerNum; i++)
        {
            if (obj[i].isEmpty())
            {
                std::cout << client[i] << " is the winner!" << std::endl;
                break;
            }
        }

        std::cout << "UP " << upColor << upValue << std::endl;

        for (int i = 0; i < playerNum; i++)
        {
            if (i == turn)
            {
                std::cout << client[i] << " * " << " ";
            }

            else
            {
                std::cout << client[i] << " ";
            }

            for (int j = 0; j < playerNum; j++)
            {
                obj[j].print();
                std::cout << std::endl;
            }
        }

        char input;

        std::cout << "Enter D (Draw) or P(Play): ";
        std::cin >> input;

        if (input == 'P')
        {
            std::cout << "Enter color: ";
            std::cin >> upColor;
            std::cout << "Enter value: ";
            std::cin >> upValue;

            obj[turn].removeOne(upValue, upColor);
        }

        else if (input == 'D')
        {
            obj[turn].insertOne(rand() % 10, colors[rand() % 4]);
        }

        turn = (turn + 1) % playerNum;
    }

    return 0;
}
