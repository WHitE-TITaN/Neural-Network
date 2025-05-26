#include "llama.h"
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
    llama_backend_init();  // required

    // Load model
    llama_model_params model_params = llama_model_default_params();
    llama_model* model = llama_model_load_from_file("C:/Users/dk488/Documents/GitHub/Neural-Network/headers/tinyllama.gguf", model_params);
    if (!model) {
        std::cerr << "❌ Failed to load model\n";
        return 1;
    }

    // Create context
    llama_context_params ctx_params = llama_context_default_params();
    ctx_params.n_ctx = 2048;
    llama_context* ctx = llama_init_from_model(model, ctx_params);

    // Prepare prompt
    std::string prompt = "Once upon a time";
    std::vector<llama_token> prompt_tokens(prompt.size() + 16);

    const llama_vocab* vocab = llama_model_get_vocab(model);

    int n_tokens = llama_tokenize(
        vocab,
        prompt.c_str(),
        (int32_t)prompt.length(),
        prompt_tokens.data(),
        prompt_tokens.size(),
        true,  // add_special (BOS)
        false  // parse_special
    );

    prompt_tokens.resize(n_tokens);

    // Run prompt through llama
    llama_batch batch = llama_batch_get_one(prompt_tokens.data(), n_tokens);
    llama_decode(ctx, batch);

    // Set up sampling
    llama_sampler_chain_params sparams = llama_sampler_chain_default_params();
    llama_sampler* sampler = llama_sampler_chain_init(sparams);
    llama_sampler_chain_add(sampler, llama_sampler_init_temp(0.8f));
    llama_sampler_chain_add(sampler, llama_sampler_init_top_p(0.95f, 1));
    llama_sampler_chain_add(sampler, llama_sampler_init_top_k(40));
    llama_sampler_chain_add(sampler, llama_sampler_init_dist(LLAMA_DEFAULT_SEED));

    std::cout << prompt;

    llama_token token;
    for (int i = 0; i < 100; ++i) {
        token = llama_sampler_sample(sampler, ctx, -1);

        // Break on EOS
        if (llama_vocab_is_eog(vocab, token)) break;

        // Decode token to string



        char piece[128];
        int n = llama_token_to_piece(vocab, token, piece, sizeof(piece), 0, true);

        if (n > 0) {
            piece[n] = '\0'; // ensure null-termination
            std::cout << piece << std::flush;
        } else {
            std::cerr << "[WARN] Failed to decode token: " << token << "\n";
        }




        // Feed token back to model
        llama_batch new_batch = llama_batch_get_one(&token, 1);
        llama_decode(ctx, new_batch);
    }

    std::cout << "\n";

    // Cleanup
    llama_sampler_free(sampler);
    llama_free(ctx);
    llama_model_free(model);
    llama_backend_free();
    return 0;
}



//    LLAMA_API const struct llama_vocab * llama_model_get_vocab(const struct llama_model * model);
//    LLAMA_API llama_token llama_model_decoder_start_token(const struct llama_model * model);
    



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