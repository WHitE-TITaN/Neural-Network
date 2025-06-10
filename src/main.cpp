#include "llama.h"
#include "..\headers\webFeatch\webSearchingResult.h"
#include "..\headers\model.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstring>  

/*llama_load_model_from_file() 
    → llama_new_context_with_model()
        → llama_tokenize()
            → llama_eval()
                → llama_sample_token()
                    → llama_token_to_str()
→ loop for more tokens →
→ llama_free() & llama_free_model()
*/

int main() {
    //std::string outofSearch = runPythonScript("C:/Users/dk488/Documents/GitHub/Neural-Network/webSurfing/search.py");
    //std::cout<<outofSearch;

    std::cout<<"\n\nUser : ";
    assistant myAssistant;
    myAssistant.promptInput();
    myAssistant.generateOutput();    
    
    return 0;
}