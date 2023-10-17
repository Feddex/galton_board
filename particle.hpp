#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "data_pack.hpp"
#include "base.hpp"
#include "peg.hpp"

class particle
{
    double _mass;
    double _radius;
    data_pack _position;
    data_pack _velocity;
    data_pack _acceleration{0, -9.81};

public:
    particle(double mass, double radius, data_pack position, data_pack velocity);

    double get_mass() const;
    double get_radius() const;
    data_pack get_position() const;
    data_pack get_velocity() const;
    data_pack get_acceleration() const;

    void set_position(const data_pack &a);
    void set_velocity(const data_pack &a);
    void set_acceleration(const data_pack &force);
};

// this fucntion computes the output velocity of the particle right after the shock occurred
data_pack velocity_shock_changer(data_pack &init_velocity_vector, data_pack const &sup_versor);
data_pack vector_particle_distance(particle const &a, peg const &b);
data_pack versor_particle_distance(particle const &a, peg const &b);

void physics_enigne(particle a, particle b);
#endif
