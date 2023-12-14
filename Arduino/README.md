# Arduino and TinyML

This directory contains some of the Arduino projects covered in chapter 1 through 9 in the TinyML book.

## Book:

https://learning.oreilly.com/library/view/tinyml/9781492052036/


In these projects We will be using **Machine Learning to predict the values ** and use them to build applications for machine learning on microcontrollers of feeding an algorithm data and letting it learn to predict the outputs.

# Hardware

Our examples in this workshop will be using Docker and the command line first and then the [Arduino Nano 33 BLE Sense](https://store-usa.arduino.cc/products/arduino-nano-33-ble-sense).

# Tensorflow Lite

We will be running the examples using TensorFlow Lite for Microcontrollers.

https://www.tensorflow.org/lite/microcontrollers

# Wrapping up

In this project, we work on better understanding

* How the concepts of [Machine Learning](https://en.wikipedia.org/wiki/Machine_learning) are different from traditional programming
* Review the source code, examples and tests in the [TensorFlow Lite project for Microcontrollers](https://github.com/tensorflow/tflite-micro)
* Exercised the tests in Linux Docker instance
* Used Google Colab to train our own model to predict outputs based on values following the equation *y=sin(x)*
* After the model was created we loaded the source code and supporting model onto a Arduino Nano 33 BLE Sense microcoroller that showed the ability to run the neural network at the edge
