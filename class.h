#pragma once

class Shop
{
private:
    unsigned int *prices;
    char **names_of_products;
    unsigned int products;

public:
    Shop(const unsigned int products);
    Shop(const Shop &other);
    ~Shop();
    void set_value_of_product(unsigned int value, const unsigned int index);
    unsigned int get_value_of_product(const unsigned int index);
    Shop &operator=(const Shop &other);
    Shop operator+( Shop &other);
    Shop &operator+=( Shop &other);
    void print_value();
    bool is_enough_money(unsigned int money);

private:
    void destroy();
    void copy(const Shop &other);
};