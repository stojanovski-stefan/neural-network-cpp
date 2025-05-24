/*
    Copyright 2025 Stefan Stojanovski
*/

#include<vector>
#include "./neuron.h"

#ifndef NETWORK_H_
#define NETWORK_H_

class Network {
 private:
    std::vector<float> weights;
    float bias;
    Neuron h1;
    Neuron h2;
    Neuron o1;
 public:
    Network();
    explicit Network(float bias);
    float feedForward(std::vector<float> inputs);
};

#endif  // NETWORK_H_
