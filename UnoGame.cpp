#include "UnoCard.h"
#include "UnoHand.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

std::string colors[4] = {"B", "G", "R", "Y"};

int main()
{
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
                return 0;
            }
        }

        std::cout << "UP: " << upColor << upValue << std::endl;

        for (int i = 0; i < playerNum; i++)
        {
            if (i == turn)
            {
                std::cout << client[i] << ": * ";
            }

            else
            {
                std::cout << client[i] << ": ";
            }

            obj[i].print();
            std::cout << std::endl;

        }

        char input;

        std::cout << "Action (D or P): ";
        std::cin >> input;

        if (input == 'P')
        {
            std::string color;
            int value;

            if (obj[turn].find(upValue, upColor))
            {
                std::cout << "Enter color: ";
                std::cin >> color;
                std::cout << "Enter value: ";
                std::cin >> value;

                if (color == upColor || value == upValue)
                {
                    obj[turn].removeOne(value, color);
                    upValue = value;
                    upColor = color;
                }

                else
                {
                    std::cout << "Invalid card! Try again!" << std::endl;
                    continue;
                }
            }

            else
            {
                color = colors[rand() % 4];
                value = rand() % 10;
                obj[turn].insertOne(rand() % 10, colors[rand() % 4]);

                if (obj[turn].find(upValue, upColor))
                {
                    obj[turn].removeOne(value, color);
                }

                else
                {
                    std::cout << "You dont have a required card!" << std::endl;
                }
            }
        }

        else if (input == 'D')
        {
            obj[turn].insertOne(rand() % 10, colors[rand() % 4]);
        }

        else
        {
            std::cout << "Invalid Choice!" << std::endl;
            continue;
        }

        turn = (turn + 1) % playerNum;
    }

    return 0;
}
