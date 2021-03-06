#pragma once

#include <string>

class UnoCard
{
private:

    std::string m_color;
    int m_value;
    UnoCard * nextCard;

public:

    UnoCard();
    UnoCard(int, const std::string &);
    void set_color(const std::string &);
    std::string & get_color();
    void set_value(const int);
    int get_value();
    void set_nextCard(UnoCard *);
    UnoCard * get_nextCard();
};
