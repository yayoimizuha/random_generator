#include <iostream>
#include <random>
#include <fstream>

#define NUMBER (1000*1000)
#define SORTED_RATIO .4
using namespace std;

int main() {
#pragma omp parallel for default(none)
    for (int i = 0; i < 20; ++i) {
        random_device seed_gen;
        mt19937 engine(seed_gen());

        uniform_int_distribution<int> intDistribution(1, 30);
        uniform_int_distribution<int> _switch(1, 1000);
        ofstream file("forward_order_" + to_string(i) + ".txt");
        for (int j = 0; j < NUMBER; ++j) {
            if (j > NUMBER * SORTED_RATIO) {
                file << intDistribution(engine) << endl;
            } else {
                file << j << endl;
            }
        }
    }
}
