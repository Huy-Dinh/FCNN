#ifndef NEURON_H
#define NEURON_H

#include "vector"
#include "cstdlib"
#include "math.h"

typedef struct
{
    double weightValue;
    double weightDifference;
} weight_t;

template <class T>
class Neuron
{
public:
    Neuron(unsigned int index)
    {
        m_Index = index;
    }
    void setInput(std::vector<T> inputVector)
    {
        m_InputVector = inputVector;
        for (unsigned int i = 0; i < m_InputVector.size(); ++i)
        {
            weight_t thisWeight;
            thisWeight.weightValue = getRandomWeight();
            m_Weights.push_back(thisWeight);
        }
    }

    void feedForward()
    {

    }

    T getOutput() const
    {
        return m_Output;
    }

    void calculateOutput()
    {
        m_Output = activationFunction();
    }

    void setOutput(T output)
    {
        m_Output = output;
    }

private:
    static double getRandomWeight()
    {
        double randNum = ((double)rand()/(double)RAND_MAX);
        return randNum;
    }

    T activationFunction()
    {
        T nominator = exp(m_InputVector(m_Index));
        T denominator = T();
        for (unsigned int i = 0; i < m_InputVector.size(); ++i)
        {
            denominator += exp(m_InputVector(i));
        }
        return nominator/denominator;
    }

    T activationFunctionDerivative()
    {
        T nominator = exp(m_InputVector(m_Index));
        T denominator = 0;
        for (unsigned int i = 0; i < m_InputVector.size(); ++i)
        {
            denominator += m_InputVector[i];
        }
        return (nominator * (denominator - nominator)) / denominator;
    }

    unsigned int m_Index;
    T m_Output;
    std::vector<T> m_InputVector;
    std::vector<weight_t> m_Weights;

};

#endif // NEURON_H
