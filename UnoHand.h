#pragma once

#include "UnoCard.h"

class UnoHand
{
private:

    UnoCard * first;

public:
    UnoHand();
    void insertOne(int, const std::string &);
    bool removeOne(int, const std::string &);
    bool isEmpty();
    void print();
};
