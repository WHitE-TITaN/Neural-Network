#include "../headers/transformer.h"
#include "../headers/wordEmbedding.h"

int main() {
	transformer sol;
	string hello = sol.sayHello();

	for (auto character : hello) {
		cout << character;
	}

	std::string input;
	std::getline(cin, input);

	wordEmbedding tokenizer1;
	std::vector<std::string> output = tokenizer1.tokenize(input);
	
	for(auto& word : output){
		std::cout<<word;	
	}

	return 0;
}