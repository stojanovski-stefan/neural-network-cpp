/*
    Copyright 2025 Stefan Stojanovski
*/

#include<neuron.h>
#include<vector>

#ifndef NETWORK_H_
#define NETWORK_H_

class Network {
 private:
    std::vector<int> weights;
    int bias;
    Neuron h1;
    Neuron h2;
    Neuron o1;
 public:
    Network();
    float feedForward(std::vector<float> inputs);
};

#endif  // NETWORK_H_
