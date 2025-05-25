cmake_minimum_required(VERSION 3.10)

#PROJECT NAME
project(NeuralNetwork)

#C++ standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

#Add Executables
add_executable(NeuralNetwork
    src/main.cpp
)


include_directories(headers)
include_directories(LLaMA/llama.cpp/include)
include_directories(LLaMa/llama.cpp)

add_subdirectory(LLaMa/llama.cpp)

target_link_libraries(NeuralNetwork PRIVATE llama)
