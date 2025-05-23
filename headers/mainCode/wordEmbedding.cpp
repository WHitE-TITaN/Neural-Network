#include "../wordEmbedding.h"

std::vector<std::string> wordEmbedding::tokenize(std::string input){
    std::istringstream tocken(input);
        std::string word;

        while(tocken >> word){
            preProcessTockens.push_back(word);
        }
            
    return preProcessTockens;
}