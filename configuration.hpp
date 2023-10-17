#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include "data_pack.hpp"
#include "base.hpp"
//#include "engine.hpp"
#include "particle.hpp"
#include "peg.hpp"
#include <memory>
#include <vector>

class configuration
{
    std::vector<peg> conf;
    data_pack extremes;
    int number_of_columns;

public:
    configuration(std::vector<peg> ciao, data_pack boh, int io);
   
    std::vector<peg> get_peg_vector() const;
    data_pack get_extremes() const;
    double get_number_of_columns()const;
    
    void configuration1();
    void configuration2();
    
};

#endif