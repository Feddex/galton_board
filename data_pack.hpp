#ifndef DATA_PACK_HPP
#define DATA_PACK_HPP

#include <iostream>
#include <cmath>
#include <cassert>

class data_pack
{
public:
    double x;
    double y;

    data_pack(double x, double y);
    data_pack(data_pack const &a);

    bool operator==(data_pack const &a) const;

    data_pack &operator=(data_pack const &a);

    double norm();

    data_pack get_versor();
    //what?
    bool point_inter_pack_range(double a) const;
};

void print(data_pack const &a);

data_pack operator*(data_pack const &a, double const &b);
data_pack operator/(data_pack const &a, double const &b);
data_pack operator+(data_pack const &a, data_pack const &b);
data_pack operator-(data_pack const &a, data_pack const &b);
data_pack get_dist_versor(data_pack const &a, data_pack const &b);

// this function returns a versor normal (of components b1 and b2) to the one passed as argument. This is implemented in such a way to return the versor (1,0) and not (-1,0) if (0,1) is passed
data_pack orthonormalizer(data_pack const &a);
#endif