#include <QCoreApplication>
#include "neuron.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Neuron<double> MyNeuron(0);
    //std::vector<double> inputVector;
    //inputVector.push_back(7);
    //inputVector.push_back(8);
    //MyNeuron.calculateOutput();
    std::cout << MyNeuron.getOutput();
    return a.exec();
}
