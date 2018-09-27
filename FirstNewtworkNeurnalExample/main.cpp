#include <QCoreApplication>
#include <cstdlib>
#include <iostream>
#include<QDebug>
#include "Neuron.h"


const int examplePar        [] = {1,0,1,0,1,0,1,0,1,0};
const int exampleGreaterFive[] = {0,0,0,0,0,0,1,1,1,1};
const int examplePrims      [] = {0,0,1,1,0,1,0,1,0,0};

int main(int argc, char *argv[])
{
  srand(time(NULL));
  QCoreApplication a(argc, argv);

  //Inputs
  const int P[][7] =
  {
    {1,1,1,1,1,1,0}, //0
    {0,1,1,0,0,0,0}, //1
    {1,1,0,1,1,0,1}, //2
    {1,1,1,1,0,0,1}, //3
    {0,1,1,0,0,1,1}, //4
    {1,0,1,1,0,1,1}, //5
    {1,0,1,1,1,1,1}, //6
    {1,1,1,0,0,0,0}, //7
    {1,1,1,1,1,1,1}, //8
    {1,1,1,1,0,1,1}  //9
  };

  Neuron<int> neuron(7);

  const int *t = examplePrims; //select goal
  float error[10]; // vector for view finals errors
  int completedTraining = 0;
  int i=0;
  for(; i<50;++i){
    completedTraining = 0;
     for(int j=0; j<10; ++j){
      error[j] = neuron.train(P[j], 7, t[j]);
      if(!error[j])
        completedTraining++;
    }
    if(completedTraining == 10)
      break;
  }

  std::cout << "neuron final weights :";
  for(int i=0; i<7; ++i){
    std::cout<< neuron.Weights()[i] << ", ";
  }
  std::cout<< "\n";
  std::cout << "neuron final bias :" << neuron.Bias() << "\n";

  std::cout << "errors vector :";
  for(int i=0; i<10; ++i){
    std::cout<< error[i] << ", ";
  }
  std::cout<< "\n";
  std::cout << "training ended at :"<< i << " times\n";

  return a.exec();
}
