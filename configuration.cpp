#include "data_pack.hpp"
#include "base.hpp"
// #include "engine.hpp"
#include "particle.hpp"
#include "configuration.hpp"
#include "peg.hpp"
#include <memory>
#include <vector>

configuration::configuration(std::vector<peg> ciao, data_pack boh, int io) : conf{ciao}, extremes{boh}, number_of_columns{io}
{
    assert(io >= 0);
}

std::vector<peg> configuration::get_peg_vector() const { return conf; }
data_pack configuration::get_extremes() const { return extremes; }
double configuration::get_number_of_columns() const { return number_of_columns; }

void configuration::configuration1()
{
    conf.clear();
    peg peg1{{4, 8}, 0.05};
    peg peg2{{3, 6}, 0.05};
    peg peg3{{5, 6}, 0.05};
    peg peg4{{1, 2}, 0.05};
    peg peg5{{3, 2}, 0.05};
    peg peg6{{5, 2}, 0.05};
    peg peg7{{7, 2}, 0.05};
    peg peg8{{2, 4}, 0.05};
    peg peg9{{4, 4}, 0.05};
    peg peg10{{6, 4}, 0.05};
    // peg peg11{{1, 1}, 1};
    // peg peg12{{7, 1}, 1};
    //  peg peg13{{8, 4}, 1};
    //  peg peg14{{8, 3}, 1};
    //  peg peg15{{8, 2}, 1};
    //  peg peg16{{8, 1}, 1};
    //  peg peg17{{8, 0}, 1};
    //  peg peg18{{7, 0}, 1};
    //  peg peg19{{6, 0}, 1};
    //  peg peg20{{5, 0}, 1};
    //  peg peg21{{4, 0}, 1};
    //  peg peg22{{3, 0}, 1};
    //  peg peg23{{2, 0}, 1};
    //  peg peg24{{1, 0}, 1};

    conf.push_back(peg1);
    conf.push_back(peg2);
    conf.push_back(peg3);
    conf.push_back(peg4);
    conf.push_back(peg5);
    conf.push_back(peg6);
    conf.push_back(peg7);
    conf.push_back(peg8);
    conf.push_back(peg9);
    conf.push_back(peg10);
    // conf.push_back(peg11);
    // conf.push_back(peg12);
    //  conf.push_back(peg13);
    //  conf.push_back(peg14);
    //  conf.push_back(peg15);
    //  conf.push_back(peg16);
    //  conf.push_back(peg17);
    //  conf.push_back(peg18);
    //  conf.push_back(peg19);
    //  conf.push_back(peg20);
    //  conf.push_back(peg21);
    //  conf.push_back(peg22);
    //  conf.push_back(peg23);
    //  conf.push_back(peg24);

    extremes = {0, 8}; // be sure to set the extremes in such a way to be comaptible with pegs' position
    number_of_columns = 8;
}

void configuration::configuration2()
{
    conf.clear();
    peg peg1{{1, 1}, 0.2};
    peg peg2{{2, 1}, 0.2};
    peg peg3{{3, 1}, 0.2};
    peg peg4{{4, 1}, 0.2};
    peg peg5{{5, 1}, 0.2};
    peg peg6{{6, 1}, 0.2};
    peg peg7{{7, 1}, 0.2};

    peg peg8{{1.5, 2}, 0.2};
    peg peg9{{2.5, 2}, 0.2};
    peg peg10{{3.5, 2}, 0.2};
    peg peg11{{4.5, 2}, 0.2};
    peg peg12{{5.5, 2}, 0.2};
    peg peg13{{6.5, 2}, 0.2};
    peg peg14{{7.5, 2}, 0.2};

    peg peg15{{1, 3}, 0.2};
    peg peg16{{2, 3}, 0.2};
    peg peg17{{3, 3}, 0.2};
    peg peg18{{4, 3}, 0.2};
    peg peg19{{5, 3}, 0.2};
    peg peg20{{6, 3}, 0.2};
    peg peg21{{7, 3}, 0.2};

    peg peg22{{1.5, 4}, 0.2};
    peg peg23{{2.5, 4}, 0.2};
    peg peg24{{3.5, 4}, 0.2};
    peg peg25{{4.5, 4}, 0.2};
    peg peg26{{5.5, 4}, 0.2};
    peg peg27{{6.5, 4}, 0.2};
    peg peg28{{7.5, 4}, 0.2};

    //  peg peg22{{3, 3}, 1};
    //  peg peg23{{2, 0}, 1};
    //  peg peg24{{1, 0}, 1};

    conf.push_back(peg1);
    conf.push_back(peg2);
    conf.push_back(peg3);
    conf.push_back(peg4);
    conf.push_back(peg5);
    conf.push_back(peg6);
    conf.push_back(peg7);
    conf.push_back(peg8);
    conf.push_back(peg9);
    conf.push_back(peg10);
    conf.push_back(peg11);
    conf.push_back(peg12);
    conf.push_back(peg13);
    conf.push_back(peg14);
    conf.push_back(peg15);
    conf.push_back(peg16);
    conf.push_back(peg17);
    conf.push_back(peg18);
    conf.push_back(peg19);
    conf.push_back(peg20);
    conf.push_back(peg21);
    conf.push_back(peg22);
    conf.push_back(peg23);
    conf.push_back(peg24);
    conf.push_back(peg25);
    conf.push_back(peg26);
    conf.push_back(peg27);
    conf.push_back(peg28);

    extremes = {0, 8}; // be sure to set the extremes in such a way to be comaptible with pegs' position
    number_of_columns = 8;
}