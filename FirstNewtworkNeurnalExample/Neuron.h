#ifndef NEURON_H
#define NEURON_H

#include <cstdlib>
#include <cmath>

template<typename T>
class Neuron
{
private:
  const size_t m_tam;
  float *m_weights;
  float m_bias;

  void _AdjustWeights(const T* inputs, size_t tam, int error);

public:
  Neuron(size_t entriesSize);
  ~Neuron();

  inline size_t EntriesCount()   const { return m_tam;     }
  inline const  float* Weights() const { return m_weights; }
  inline float  Bias()           const { return m_bias;    }

  int train(const T *inputs, size_t tam, const int result);
  int think(const T *inputs,size_t tam);
};

template<typename T>
Neuron<T>::Neuron(size_t entriesSize):
  m_tam(entriesSize)
{
  m_bias = std::sin(std::rand()%360);
  m_weights = new float[m_tam];
  for(int i=0; i<m_tam; ++i){
    m_weights[i] =  std::sin(std::rand()%360);
  }
}

template<typename T>
Neuron<T>::~Neuron(){
  delete []m_weights;
}
template<typename T>
void Neuron<T>::_AdjustWeights(const T *inputs, size_t tam, int error){
  for(int i=0; i<tam; ++i)
    m_weights[i] += error*inputs[i];
}

template<typename T>
int Neuron<T>::train(const T *inputs, size_t tam,const int result){
  if(tam != m_tam)
    throw "error, inputs should be equals";

  int error = result - think(inputs, tam);
  _AdjustWeights(inputs, tam, error);
  m_bias += error;
  return error;
}

template<typename T>
int Neuron<T>::think(const T *inputs, size_t tam){
  if(tam != m_tam)
    throw "error, inputs should be equals";

  float sum = m_bias;
  for(int i=0; i<tam; ++i)
    sum += m_weights[i]*inputs[i];
  return sum > 0 ? 1 : 0;
}

#endif // NEURON_H
