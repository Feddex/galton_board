#include "data_pack.hpp"
#include "base.hpp"
#include "peg.hpp"
#include "particle.hpp"
#include "configuration.hpp"
#include "engine.hpp"
#include <vector>

engine::engine(std::shared_ptr<configuration> conf, std::shared_ptr<particle> part, double time_step, std::shared_ptr<int> cycles) : conf{conf}, part{part}, time_step{time_step}, cycles{cycles}
{
    assert(time_step > 0);
}

void engine::peg_proximity_checker_and_velocty_changer()
{

    for (int i{0}; i < conf->get_peg_vector().size(); ++i)
    {
        double particle_peg_distance = vector_particle_distance(*part, conf->get_peg_vector()[i]).norm();
        double sum_partcle_peg_radius = part->get_radius() + conf->get_peg_vector()[i].get_radius();
        if (particle_peg_distance <= sum_partcle_peg_radius)
        {
            // if there is a shock the counter must be nulled
            (*cycles) = 0;
            // this is the versor distance that points from the peg to the particle, this will be the second vector of the local orthonorml base Bbase
            data_pack particle_peg_versor = versor_particle_distance(*part, conf->get_peg_vector()[i]);
            data_pack initial_particle_velocity = part->get_velocity();
            data_pack final_particel_velocity = velocity_shock_changer(initial_particle_velocity, particle_peg_versor);
            (*part).set_velocity(final_particel_velocity);
        }
    }
}

void engine::wall_proximity_checker_and_velocity_changer()
{
    data_pack wall_position = conf->get_extremes();
    double particle_left_boundary_position = part->get_position().x - part->get_radius();
    double particle_right_boundary_position = part->get_position().x + part->get_radius();

    if (particle_left_boundary_position <= wall_position.x || particle_right_boundary_position >= wall_position.y)
    {
        part->set_velocity({-part->get_velocity().x, part->get_velocity().y});
    }
}

void engine::evolve()
{
    if (*cycles > 2)
    {
        peg_proximity_checker_and_velocty_changer();
    }
    wall_proximity_checker_and_velocity_changer();

    (*part).set_position((*part).get_position() + (*part).get_velocity() * time_step);
    (*part).set_velocity((*part).get_velocity() + (*part).get_acceleration() * time_step);
}
