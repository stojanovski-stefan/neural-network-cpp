/*
    Copyright 2025 Stefan Stojanovski
*/

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using std::vector, std::exp, std::copy;

/**
 * Compresses any integer to (0,1) where big negative numbers 
 * become closer to 0 and big positive number become closer to 1.
 * 
 * Activation Function: f(x) = 1 / (1 + e ^(-x))
 * 
 * @param x - integer to be compressed.
 * @return value of x passed through a sigmoid function (0,1).
 */
float sigmoid(int x) {
    return 1 / (1 + exp(-x));
}

/**
 * Calculates dot product of two vectors.
 * 
 * @param x - vector of integers.
 * @param y - vector of integers.
 * @return dotProduct of x and y as a integer.
 */
int dotProduct(vector<int> x, vector<int> y) {
    if (x.size() != y.size()) {
        return -1;
    }

    int xArr[x.size()];
    int yArr[y.size()];
    copy(x.begin(), x.end(), xArr);
    copy(y.begin(), y.end(), yArr);

    int product = 0;
    for (int i = 0; i < sizeof(xArr) / sizeof(xArr[0]); i++) {
        product = product + (xArr[i] * yArr[i]);
    }

    return product;
}

/**
 * Basic building block of a neural network. A neuron takes inputs,
 * does some math with them, and produces and output.
 * 
 * This is an implementation of a 2-input neuron.
 */
class Neuron {
 private:
    int bias;
    vector<int> weights;

 public:
    Neuron(vector<int> weights, int bias) {
        this->bias = bias;
        this->weights = weights;
    }

    /**
     * Produces the output of neuron by multipying each input
     * by a weight (dot product), adding the weighted inputs
     * together with a bias, and sending it through an activation
     * fucntion (sigmoid).
     * 
     * The process of passing inputs forward to get an output
     * is known as feedforwarding.
     * 
     * @param inputs - vector of integers.
     * @return feedforward value of inputs that have been passed through an activation function.
     */
    float feedForward(vector<int> inputs) {
        return sigmoid(dotProduct(this->weights, inputs) + this->bias);
    }
};

int main() {
    vector<int> weights = {0, 1};
    int bias = 4;
    vector<int> inputs = {2, 3};

    Neuron n = Neuron(weights, bias);
    float output = n.feedForward(inputs);
    std::cout << output << std::endl;
    return 0;
}
