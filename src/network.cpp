/*
 * Copyright 2025 Stefan Stojanovski
 */

#include <iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include "../include/neuron.h"
#include "../include/network.h"

using std::vector;


Network::Network() {
    this->weights = {0.0, 1.0};
    this->bias = 0.0;
    this->h1 = Neuron(this->weights, this->bias);
    this->h2 = Neuron(this->weights, this->bias);
    this->o1 = Neuron(this->weights, this->bias);
}

Network::Network(float bias) {
    this->weights = {0.0, 1.0};
    this->bias = bias;
    this->h1 = Neuron(this->weights, this->bias);
    this->h2 = Neuron(this->weights, this->bias);
    this->o1 = Neuron(this->weights, this->bias);
}

float Network::feedForward(vector<float> inputs) {
    float outH1 = this->h1.feedForward(inputs);
    float outH2 = this->h2.feedForward(inputs);
    float outO1 = this->o1.feedForward({outH1, outH2});
    return outO1;
}

int main() {
    vector<float> inputs = {2.0, 3.0};
    Network net = Network();
    std::cout << net.feedForward(inputs) << std::endl;
    return 0;
}
