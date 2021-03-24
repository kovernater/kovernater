#include <iostream>
#include "class.h"
#include "helpers.h"

Shop::Shop(const unsigned int products)
{
    prices = new (std::nothrow) unsigned int[products];
    if (!prices)
    {
        return;
    }
    for (size_t i = 0; i < products; i++)
    {
        prices[i] = 0;
    }

    names_of_products = new (std::nothrow) char *[products];
    if (!prices)
    {
        return;
    }
    for (size_t i = 0; i < products; i++)
    {
        names_of_products[i] = read_name();
    }
}

Shop::Shop(const Shop &other)
{
    copy(other);
}

Shop::~Shop()
{
    destroy();
}

Shop &Shop::operator=(const Shop &other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

void Shop::set_value_of_product(unsigned int value, const unsigned int index)
{
    if (index < this->products && index >= 0)
    {
        prices[index] = value;
    }
}

unsigned int Shop::get_value_of_product(const unsigned int index)
{
    if (index < this->products && index >= 0 && prices[index])
    {
        return prices[index];
    }

    return 0;
}

Shop Shop::operator+(Shop &other)
{
    Shop result = *this;
    result += other;

    return result;
}

Shop &Shop::operator+=(Shop &other)
{
    for (size_t i = 0; i < std::max(this->products, other.products); i++)
    {
        if (strcmpare(this->names_of_products[i], other.names_of_products[i]))
        {
            set_value_of_product(this->get_value_of_product(i) + other.get_value_of_product(i), i);
        }
    }
    return *this;
}

void Shop::print_value()
{
    for (size_t i = 0; i < products; i++)
    {
        std::cout << names_of_products[i] << " : " << prices[i] << "\n";
    }
}

bool Shop::is_enough_money(unsigned int money)
{
    unsigned int sum = 0;
    for (size_t i = 0; i < products; i++)
    {
        sum += prices[i];
    }

    if (money < sum)
    {
        return false;
    }
    return true;
}

void Shop::destroy()
{
    for (size_t i = 0; i < products; i++)
    {
        delete[] names_of_products[i];
    }
    delete[] names_of_products;
}

void Shop::copy(const Shop &other)
{
    this->products = other.products;

    this->names_of_products = new (std::nothrow) char *[this->products];
    if (!names_of_products)
    {
        return;
    }
    this->prices = new (std::nothrow) unsigned int[this->products];
    if (!prices)
    {
        return;
    }

    for (size_t i = 0; i < this->products; i++)
    {
        this->names_of_products[i] = other.names_of_products[i];
        this->prices[i] = other.prices[i];
    }
}