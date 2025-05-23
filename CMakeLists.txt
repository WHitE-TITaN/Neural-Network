cmake_minimum_required(VERSION 3.10)

#PROJECT NAME
project(NeuralNetwork)

#C++ standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

#Add Executables
add_executable(NeuralNetwork
    src/main.cpp
    headers/mainCode/wordEmbedding.cpp
)


include_directories(headers)