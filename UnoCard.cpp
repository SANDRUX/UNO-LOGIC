#include "UnoCard.h"

UnoCard::UnoCard()
{

}

UnoCard::UnoCard(int value, const std::string & color)
{
    this->m_value = value;
    this->m_color = color;
}

void UnoCard::set_color(const std::string & color)
{
    this->m_color = color;
}

std::string & UnoCard::get_color()
{
    return this->m_color;
}

void UnoCard::set_value(const int value)
{
    this->m_value = value;
}

int UnoCard::get_value()
{
    return this->m_value;
}

void UnoCard::set_nextCard(UnoCard * next)
{
    this->nextCard = next;
}

UnoCard * UnoCard::get_nextCard()
{
    return this->nextCard;
}
