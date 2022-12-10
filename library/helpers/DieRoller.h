#ifndef FIGHTSIM_DIEROLLER_H
#define FIGHTSIM_DIEROLLER_H

#include <random>

class DieRoller {
public:
    std::mt19937 rng;

    DieRoller();                        //constructor that seeds the rng with a std::random_device
    void SeedRNG(unsigned int seedVal); //seeds the rng with the seedVal
    int Roll1DN(int N);                    // returns the result of an N-sided die roll (between 1 and N);
    int Roll6D3();

    int Roll3D6();                        // rolls 3 six-sided dice and sums them 3
    int Roll4D6DropLowest();            // rolls 4 six-sided dice and sums the top 3, dropping the lowest roll
};

#endif FIGHTSIM_DIEROLLER_H