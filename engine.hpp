#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "configuration.hpp"
#include "data_pack.hpp"
#include "base.hpp"
#include "peg.hpp"
#include "particle.hpp"

#include <vector>
#include <memory>

class engine
{
    std::shared_ptr<configuration> conf;
    std::shared_ptr<particle> part;
    double time_step;
    std::shared_ptr<int> cycles;

public:
    engine(std::shared_ptr<configuration> conf, std::shared_ptr<particle> part, double time_step, std::shared_ptr<int> cycles);

    // this functions checks wether the particle is within the peg perimeter and applies velocity changer function due to the shock
    void peg_proximity_checker_and_velocty_changer();

    // this function checks if the particle's distance from the wall is larger than particle's radius.
    // If the particle's distance form the wall is smaller than its radius then the shock occurs and the particle's velocity is changed consequently
    void wall_proximity_checker_and_velocity_changer();

    // this function udates position and velocity and applies the necessary velocty changes
    void evolve();
};
#endif