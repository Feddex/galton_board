#ifndef BASE_HPP
#define BASE_HPP
#include "data_pack.hpp"

// BASE
struct base
{
    data_pack versor1;
    data_pack versor2;
    base(data_pack v1, data_pack v2);
};

// given a vector and a versor, this function returns the component of the vector along the versor
double component(data_pack const &a, data_pack const &versor);

// given a vector an a choosen base, this returns the components of the vector with respect to the base
data_pack base_component(data_pack const &a, base const &base);

// given a vector expressed with respect to an orthonormal base {b1, b2}, this function returns the components of the vector with respect to the canonic base
data_pack canonic_component(data_pack const &vector_Bbase, base const &base);
#endif