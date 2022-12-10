#include "DieRoller.h"

DieRoller::DieRoller() {
    int seedVal;
    std::random_device rd;                    // "a good unpredictable sequence starter" (c.)
    seedVal = rd();
    rng.seed(seedVal);
}

void DieRoller::SeedRNG(unsigned int seedVal) {
    rng.seed(seedVal);                     // just replaces the generated seed with a provided one
}

int DieRoller::Roll1DN(int N) {
    std::uniform_int_distribution<int> DNRoll(1, N);
    return DNRoll(rng);
}

int DieRoller::Roll6D3() {                    // rolls 6 three-sided dices and sums them
    std::uniform_int_distribution<int> D6Roll(1, 3);
    return D6Roll(rng) + D6Roll(rng) + D6Roll(rng) + D6Roll(rng) + D6Roll(rng) + D6Roll(rng);
}

int DieRoller::Roll3D6() {                    // rolls 3 six-sided dice and sums them 3
    std::uniform_int_distribution<int> D6Roll(1, 6);
    return D6Roll(rng) + D6Roll(rng) + D6Roll(rng);
}

int DieRoller::Roll4D6DropLowest() {
    std::uniform_int_distribution<int> D6Roll(1, 6);
    int roll[4];
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        roll[i] = D6Roll(rng);
        if (i > 0)
            if (roll[i] > roll[i - 1])
                sum += roll[i];
            else
                sum += roll[i - 1];
    }
    return sum;
}