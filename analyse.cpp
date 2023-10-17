#include "data_pack.hpp"
#include "base.hpp"
#include "engine.hpp"
#include "particle.hpp"
#include "peg.hpp"
#include "configuration.hpp"
#include "analyse.hpp"
#include <cassert>
#include <memory>
#include <algorithm>
#include <fstream>

land_analyser::land_analyser(std::shared_ptr<configuration> confi) : conf{confi}, vector_of_column_extremes{std::vector<data_pack>(conf->get_number_of_columns(), {0, 0})}, particle_landing_in_a_column_counter{std::vector<int>(conf->get_number_of_columns(), 0)}
{
    assert(vector_of_column_extremes.size() == particle_landing_in_a_column_counter.size());
    // std::cout << "size: " << vector_of_column_extremes.size() << '\n';
}

void land_analyser::print_vector_landing_counter()
{
    for (int i{0}; i < particle_landing_in_a_column_counter.size(); ++i)
    {
        std::cout << particle_landing_in_a_column_counter[i] << " ";
    }
    std::cout << '\n';
}

void land_analyser::print_in_file_txt() const
{
    std::ofstream outputFile("result.txt");

    outputFile << conf->get_number_of_columns()<<'\n';
    outputFile<< conf->get_extremes().x<<'\n';
    outputFile<< conf->get_extremes().y<<'\n';
    for (int i{0}; i < particle_landing_in_a_column_counter.size(); ++i)
    {
        outputFile << particle_landing_in_a_column_counter[i] << "\n";
    }
};

double land_analyser::columns_amplitude()
{
    data_pack extremes = conf->get_extremes();
    double game_width = extremes.y - extremes.x;
    double column_number = conf->get_number_of_columns();
    double column_amplitude = game_width / column_number;
    return column_amplitude;
}

void land_analyser::vector_column_extremes_setter()
{

    double col_amp = columns_amplitude();
    for (int i{0}; i < conf->get_number_of_columns(); ++i)
    {
        data_pack col_extremes = {i * col_amp, (i + 1) * col_amp};
        vector_of_column_extremes[i] = col_extremes;
    }
    assert(vector_of_column_extremes.size() == conf->get_number_of_columns());
    // assert(vector_of_column_extremes.size() == number_particle_landing_in_a_columns.size());
}

bool land_analyser::particle_height_checker(particle const &a)
{
    return a.get_position().y <= 0;
}

int land_analyser::particle_xpos_in_columns(particle const &a)
{

    for (int i{0}; i < vector_of_column_extremes.size(); ++i)
    {
        if ((vector_of_column_extremes[i]).point_inter_pack_range(a.get_position().x))
        {
            return i;
        }
    }

    if (a.get_position().x > conf->get_extremes().y)
    {
        return (vector_of_column_extremes.size() - 1);
    }
    if (a.get_position().x < conf->get_extremes().x)
    {
        return 0;
    }

    print(a.get_position());
    throw std::runtime_error{"particle_xpos_in_columns does not work \n"};
}

void land_analyser::columns_prticle_landing_counter(std::shared_ptr<particle> const &a)
{
    if (particle_height_checker(*a))
    {
        auto i = particle_xpos_in_columns(*a);
        ++particle_landing_in_a_column_counter[i];
    }
}
