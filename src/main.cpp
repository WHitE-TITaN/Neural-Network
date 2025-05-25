#include "llama.h"
#include <iostream>
#include <string>

/*llama_load_model_from_file() 
    → llama_new_context_with_model()
        → llama_tokenize()
            → llama_eval()
                → llama_sample_token()
                    → llama_token_to_str()
→ loop for more tokens →
→ llama_free() & llama_free_model()
*/

#include "llama.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "Starting program..." << std::endl;

    llama_model_params params = llama_model_default_params();
    std::cout << "Model params initialized." << std::endl;

    const char* model_path = "C:/Users/dk488/Documents/GitHub/Neural-Network/headers/tinyllama.gguf";
    std::cout << "Trying to load model from: " << model_path << std::endl;

    // NOTE: Use the newer API
    llama_model* textModel = llama_model_load_from_file(model_path, params);

    if (!textModel) {
        std::cerr << "❌ Error: Failed to load model!" << std::endl;
        return 1;
    }

    std::cout << "✅ Model loaded successfully!" << std::endl;

    llama_free_model(textModel); // Just for cleanup
    std::cout << "Model freed. Exiting program." << std::endl;

    return 0;
}



/*#include "llama.h"
#include <iostream>
#include <vector>

int main() {
    // Initialize llama model parameters
    llama_model_params model_params = llama_model_default_params();

    // Load the model
    llama_model* model = llama_load_model_from_file("path/to/your/model.gguf", model_params);
    if (!model) {
        std::cerr << "Failed to load model\n";
        return 1;
    }

    // Initialize context parameters
    llama_context_params ctx_params = llama_context_default_params();

    // Create a new context from model
    llama_context* ctx = llama_new_context_with_model(model, ctx_params);
    if (!ctx) {
        std::cerr << "Failed to create context\n";
        llama_free_model(model);
        return 1;
    }

    // Input text
    const char* prompt = "Hello world!";
    std::cout << "Prompt: " << prompt << "\n";

    // Tokenize the prompt
    std::vector<llama_token> tokens(strlen(prompt) + 8); // extra room just in case
    int n_tokens = llama_tokenize(
        model,
        prompt,
        tokens.data(),
        tokens.size(),
        true,  // add_bos
        false  // parse_special
    );

    if (n_tokens < 0) {
        std::cerr << "Failed to tokenize prompt\n";
        llama_free(ctx);
        llama_free_model(model);
        return 1;
    }

    tokens.resize(n_tokens);

    std::cout << "Token IDs:\n";
    for (llama_token tok : tokens) {
        std::cout << tok << " ";
    }
    std::cout << "\n";

    // Cleanup
    llama_free(ctx);
    llama_free_model(model);
    llama_backend_free();

    return 0;
}
*/