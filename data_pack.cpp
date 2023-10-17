#include <iostream>
#include <cmath>
#include <cassert>
#include "data_pack.hpp"

data_pack::data_pack(double x, double y) : x{x}, y{y} {}
data_pack::data_pack(data_pack const &a) : x{a.x}, y{a.y} {}

bool data_pack::operator==(data_pack const &a) const
{
    return ((*this).x == a.x && (*this).y == a.y);
}

data_pack &data_pack::operator=(data_pack const &a)
{
    if (*this == a)
    {
        return *this;
    }
    x = a.x;
    y = a.y;
    return *this;
}

double data_pack::norm()
{
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}

data_pack data_pack::get_versor()
{
    return {x / ((*this).norm()), y / ((*this).norm())};
}

bool data_pack::point_inter_pack_range(double a) const
{
    return x <= a && a < y;
}

void print(data_pack const &a)
{
    std::cout << a.x << " " << a.y << '\n';
}

data_pack operator*(data_pack const &a, double const &b)
{
    return {a.x * b, a.y * b};
}


data_pack operator/(data_pack const &a, double const &b)
{
    return {a.x / b, a.y / b};
}


data_pack operator+(data_pack const &a, data_pack const &b)
{
    return {a.x + b.x, a.y + b.y};
}


data_pack operator-(data_pack const &a, data_pack const &b)
{
    return {a.x - b.x, a.y - b.y};
}


data_pack get_dist_versor(data_pack const &a, data_pack const &b)
{
    return {(a - b).get_versor()};
}


data_pack orthonormalizer(data_pack const &a)
{
    
    data_pack i{1, 0};
    data_pack minus_i = i * -1; // TODO: *commutativity needs to be fixed 

    if (a == i)
    {
        return {0, -1};
    }
    if (a == minus_i)
    {
        return {0, 1};
    }

    //here the second component of the normal versor is computed 
    double b1 = std::sqrt(std::pow(a.y, 2) / (std::pow(a.x, 2) + std::pow(a.y, 2)));
    double b2 = -b1 * (a.x / a.y);
    return {b1, b2};
}
