#include <iostream>
#include "helpers.h"

constexpr int MAX = 100;

unsigned int strlen(const char *string)
{
    unsigned len = 0;
    while (string[len])
    {
        len++;
    }
    return len;
}

void strcpy(char *target, const char *source)
{
    unsigned len = 0;
    while (source[len])
    {
        target[len] = source[len];
        len++;
    }

    target[len] = '\0';
}
char to_upper(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return char(int(c) - 32);
    }
    return c;
}

bool strcmpare(const char *string1, const char *string2)
{
    if (strlen(string1) != strlen(string2))
    {
        return false;
    }

    for (size_t i = 0; i < strlen(string1); i++)
    {
        if (string1[i] != string2[i])
        {
            return false;
        }
    }

    return true;
}

char *read_name()
{
    char temp[MAX];
    std::cin >> temp;

    char *name = new (std::nothrow) char[strlen(temp)];
    if (!name)
    {
        return nullptr;
    }

    strcpy(name, temp);
    name[0] = to_upper(name[0]);
    return name;
}
