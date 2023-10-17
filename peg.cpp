#include <iostream>
#include "data_pack.hpp"
#include "peg.hpp"
#include <vector>

peg::peg(): _position({0,0}), _radius{0}{}


peg::peg(data_pack position, double radius) : _position{position}, _radius{radius}
{
    assert(radius >= 0);
}

data_pack peg::get_position() const { return _position; }
double peg::get_radius() const { return _radius; }

