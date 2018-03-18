#include <iostream>
#include <string>
#include <random>
#include "NeuralNetwork.h"

using std::make_pair;

const unsigned long long LEVEL_1 = 10;
const unsigned long long LEVEL_2 = 4;
const unsigned long long LEVEL_3 = 1;
const ld LEARNING[LEVEL_1]={};
ld (*const NULL_FUNCTION)(const ld) = NULL;
ld (*const NULL_DERIVATIVE_FUNCTION)(const ld) = NULL;


int main() {
    NeuralNetwork network({
          {LEVEL_1, NULL_FUNCTION, NULL_DERIVATIVE_FUNCTION},
          {LEVEL_2, sygmoidFunction, derivativeSygmoidFunction},
          {LEVEL_3, linearFunction, derivativeLinearFunction}
                          }, 0.01, 0.1);

    vector<ld> vect;
    ld last = 0.1;
    for (int i = 0; i < 15; i++) {
        vect.push_back(function(last));
        last += 0.1;
    }

    try {
        network.learning(vect);
    } catch (int e) {
        if (e == 1) {
            std::cout << "Incorrent size of learning selection!" << std::endl;
        } else {
            std::cout << e << std::endl;
        }
    }

    //network.show();

    return 0;
}