#include <vector>
#include <string>
#include <iostream>
#include <sstream>


//preProcessTockens > stores the sentence in tockens of words 

class wordEmbedding{
        std::vector<std::string> preProcessTockens;
    public:

        std::vector<std::string> tokenize(std::string input); //~ converts sentences into words 
};