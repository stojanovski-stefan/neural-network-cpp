/*
    Copyright 2025 Stefan Stojanovski
*/
#include<vector>

#ifndef NEURON_H_
#define NEURON_H_

/**
 * Basic building block of a neural network. A neuron takes inputs,
 * does some math with them, and produces and output.
 * 
 * This is an implementation of a 2-input neuron.
 */
class Neuron {
 private:
    int bias;
    std::vector<int> weights;

 public:
    Neuron();
    Neuron(std::vector<int> weights, int bias);

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
    float feedForward(std::vector<float> inputs);
};

#endif  // NEURON_H_
