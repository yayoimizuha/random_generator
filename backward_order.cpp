#include <iostream>
#include <random>
#include <fstream>

#define NUMBER (1000*1000)
using namespace std;

int main() {
#pragma omp parallel for default(none)
    for (int i = 0; i < 20; ++i) {
        random_device seed_gen;
        mt19937 engine(seed_gen());

        uniform_int_distribution<int> intDistribution(1, 30);
        uniform_int_distribution<int> _switch(1, 1000);
        ofstream file("backward_order_" + to_string(i) + ".txt");
        for (int j = 0; j < NUMBER; ++j) {
            if (_switch(engine) == 1) {
                file << intDistribution(engine) << endl;
            } else {
                file << NUMBER - j << endl;
            }
        }
    }
}
