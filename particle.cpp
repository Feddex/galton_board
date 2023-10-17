#include "data_pack.hpp"
#include "base.hpp"
#include "particle.hpp"
#include "peg.hpp"

particle::particle(double mass, double radius, data_pack position, data_pack velocity) : _mass{mass}, _radius{radius}, _position{position}, _velocity{velocity}
{
    assert(mass > 0);
    assert(radius > 0);
}

double particle::get_mass() const { return _mass; }
double particle::get_radius() const { return _radius; }
data_pack particle::get_position() const { return {_position.x, _position.y}; }
data_pack particle::get_velocity() const { return {_velocity.x, _velocity.y}; }
data_pack particle::get_acceleration() const { return _acceleration; }

void particle::set_position(const data_pack &a) { _position = a; }
void particle::set_velocity(const data_pack &a) { _velocity = a; }
void particle::set_acceleration(const data_pack &force) { _acceleration = force / _mass; }

data_pack velocity_shock_changer(data_pack &init_velocity_vector, data_pack const &sup_versor)
{
    // this gets me the versor perpenicular to the surface normal versor sup_versor
    data_pack Bbase_versor2 = orthonormalizer(sup_versor);

    // sup_versor is chosen to be the second versor of the local base Bbase
    base Bbase{Bbase_versor2, sup_versor};

    // this are the initial velocity component with respect to the local othornormal base Bbase
    data_pack Bbase_init_velocity_vector_component = base_component(init_velocity_vector, Bbase);

    // the inverion of velocity's y components is performed. This is the case of a complete elastic shock, if you want to simulate a partial elastic one just multiply the component of this vector by the percentage of energy you want to be conserved
    data_pack Bbase_final_velocity_vector_component{1*Bbase_init_velocity_vector_component.x, -0.5*Bbase_init_velocity_vector_component.y};

    // change of base from Bbase to Canonic Base: this is the final velocity vector after the shock
    data_pack Canonic_final_velocity_vector_component = canonic_component(Bbase_final_velocity_vector_component, Bbase);
    return Canonic_final_velocity_vector_component;
}

// you have to pass the particle as first argument and then the peg as second
data_pack vector_particle_distance(particle const &a, peg const &b)
{
    return {a.get_position() - b.get_position()};
}

// you have to pass the particle first and then the peg as second
data_pack versor_particle_distance(particle const &a, peg const &b)
{
    data_pack vector_distance = vector_particle_distance(a, b);
    return vector_distance.get_versor();
}

void physics_enigne(particle a, particle b)
{
    data_pack dist_vector{a.get_position() - b.get_position()};
    if (std::abs(dist_vector.norm()) <= a.get_radius() + b.get_radius())
    {
        get_dist_versor(a.get_position(), b.get_position());
    }
}
