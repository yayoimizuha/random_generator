#include <iostream>
#include <random>
#include <fstream>

using namespace std;
#define NUMBER (1000*1000)

int main() {
#pragma omp parallel for default(none)
    for (int i = 0; i < 20; ++i) {
        random_device seed_gen;
        mt19937 engine(seed_gen());

        uniform_int_distribution<int> intDistribution(1, 30);
        ofstream file("many_overlaps_" + to_string(i) + ".txt");
        for (int j = 0; j < NUMBER; ++j) {
            file << intDistribution(engine) << endl;
        }
    }
}
