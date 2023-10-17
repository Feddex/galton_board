#ifndef ANALYSE_HPP
#define ANALYSE_HPP

#include "data_pack.hpp"
#include "base.hpp"
#include "engine.hpp"
#include "particle.hpp"
#include "peg.hpp"
#include "configuration.hpp"
#include <cassert>
#include <memory>

// l'analizzatore deve dipendere dalla configurazione perchè dipende da quanto sono distanti le pareti laterali tra loro
class land_analyser
{
    std::shared_ptr<configuration> conf;
    std::vector<data_pack> vector_of_column_extremes;
    std::vector<int> particle_landing_in_a_column_counter;

public:
    land_analyser(std::shared_ptr<configuration> confi);

    //this displays the amount of particle ended in a comlumns 
    void print_vector_landing_counter();

    void print_in_file_txt() const;

    // it retuns column's width
    //be sure that the column's width is larger than particles' diameter
    double columns_amplitude();

    // this function over-writes the default column-extremes in the vector of column extremes
    // this needs to be called immediatley after the instatiation of a analyse object, to set the extremes of the columns
    void vector_column_extremes_setter();

    // this functions chekcs wether the particle has landed (it checks if the centre of the ball has null height)
    // this will be called in a sequent function to establish wether the particle as landed
    bool particle_height_checker(particle const &a);

    // this function checks if the particle x_position is within the range of extremes of a column; it return an integre index for the position of the columns in the vector_columns_extremes
    // which will be used to inceras the counter vector of particle landed in that column which is the
    int particle_xpos_in_columns(particle const &a);

    // this functions increases the counter of particle landed in a column by adding +1 to the element of the vector particle_landing_in_a_column_counter
    // which correspond to element of the vector_of_column_extremes that rapresent the columns
    // this function will be called in every cicle of the inner cicle of the simulation to establish if the particle has landed, which column has landed in
    // and to increas the corresponding counter if necessary
    void columns_prticle_landing_counter(std::shared_ptr<particle> const &a);
};

#endif