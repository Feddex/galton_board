#ifndef PEG_HPP
#define PEG_HPP

#include "data_pack.hpp"
#include <vector>

class peg
{
    data_pack _position;
    double _radius;

public:
    peg();
    peg(data_pack position, double radius);
    data_pack get_position() const;
    double get_radius() const;
};

#endif