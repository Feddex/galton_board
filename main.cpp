#include "data_pack.hpp"
#include "base.hpp"
#include "engine.hpp"
#include "particle.hpp"
#include "peg.hpp"
#include "configuration.hpp"
#include "analyse.hpp"
#include <memory>
#include <random>
#include <fstream>

int main()
{
    // first thing to do is choosing the configuration calling the respective function
    std::shared_ptr<configuration> conf = std::make_shared<configuration>(std::vector<peg>{0}, data_pack{0, 0}, 0);
    conf->configuration2();
    // second thing is to instatiate an analyse object and assign it the configuration
    std::shared_ptr<land_analyser> analyser = std::make_shared<land_analyser>(conf);
    // then we call the lan_analyser method vector_columns_extremes_setter to set the vector_of_column_extremes
    analyser->vector_column_extremes_setter();

    for (int i{0}; i < 1000; ++i)
    {
        // HERE THERE WILL BE THE OUTER CICLE WHERE WE GENERATE MULTIPLE PARTICLE
        std::random_device rd;
        std::uniform_real_distribution dist(3., 5.);

        // the particles are set here
        std::shared_ptr<particle> part_pt = std::make_shared<particle>(1, 0.2, data_pack{dist(rd), 5}, data_pack{0, 0});
        // this will be used as a counter of the number of cycles executed after a single shock
        std::shared_ptr<int> cycles = std::make_shared<int>(0);

        engine eng{conf, part_pt, 0.01, cycles};
        // std::cout<<part_pt->get_position().x<<'\n';

        while (part_pt->get_position().y > 0)
        {
            *cycles += 1;
            // call evolve function to start and proceed the simulation
            eng.evolve();
            // call the columns_prticle_landing_counter() to check if the particle has landed, if so in which columns and then increas the counter
            analyser->columns_prticle_landing_counter(part_pt);
            // std::cout << "time " << i << " position: ";
            // print(part_pt->get_position());
            // std::cout << '\n';
        }

        analyser->print_vector_landing_counter();
    }

    analyser->print_in_file_txt();
}