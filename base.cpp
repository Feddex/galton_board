#include "data_pack.hpp"
#include "base.hpp"

base::base(data_pack v1, data_pack v2) : versor1{v1}, versor2{v2}
{
    // assert(v1.x * v2.x + v1.y * v2.y == 0);
    // assert(v1.norm() == 1);
    // assert(v2.norm() == 1);
}

double component(data_pack const &a, data_pack const &versor)
{
    return a.x * versor.x + a.y * versor.y;
}

data_pack base_component(data_pack const &a, base const &base)
{
    double component1 = component(a, base.versor1);
    double component2 = component(a, base.versor2);
    return {component1, component2};
}

data_pack canonic_component(data_pack const &vector_Bbase, base const &base)
{
    double component1_Canonic = vector_Bbase.x * base.versor1.x + vector_Bbase.y * base.versor2.x;
    double component2_canonic = vector_Bbase.x * base.versor1.y + vector_Bbase.y * base.versor2.y;
    return {component1_Canonic, component2_canonic};
};