/*
    Copyright 2025 Stefan Stojanovski
*/

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stdexcept>
#include "../include/neuron.h"

using std::vector, std::exp, std::copy, std::invalid_argument;

/**
 * Compresses any integer to (0,1) where big negative numbers 
 * become closer to 0 and big positive number become closer to 1.
 * 
 * Activation Function: f(x) = 1 / (1 + e ^(-x))
 * 
 * @param x - integer to be compressed.
 * @return value of x passed through a sigmoid function (0,1).
 */
float sigmoid(float x) {
    return 1 / (1 + exp(-x));
}

/**
 * Calculates dot product of two vectors.
 * 
 * @param x - vector of floats.
 * @param y - vector of floats.
 * @return dotProduct of x and y as a float.
 */
float dotProduct(vector<float> x, vector<float> y) {
    if (x.size() != y.size()) {
        throw invalid_argument("dotProduct: Vectors must be the same length.");
    }

    float xArr[x.size()];
    float yArr[y.size()];
    copy(x.begin(), x.end(), xArr);
    copy(y.begin(), y.end(), yArr);

    float product = 0.0;
    for (int i = 0; i < sizeof(xArr) / sizeof(xArr[0]); i++) {
        product += (xArr[i] * yArr[i]);
    }

    return product;
}

Neuron::Neuron() {
    this->bias = 0;
    this->weights = {};
}

Neuron::Neuron(vector<float> weights, float bias) {
    this->bias = bias;
    this->weights = weights;
}

float Neuron::feedForward(vector<float> inputs) {
    return sigmoid(dotProduct(this->weights, inputs) + this->bias);
}
