#include "llama.h"
#include <iostream>
#include <vector>

class assistant{
    //store model
    llama_model_params model_params;
    llama_model* model;

    //store model context
    llama_context_params ctx_params;
    llama_context* ctx ;

    assistant(){
        llama_backend_init();
        
        //loading model in
        llama_model_params model_params = llama_model_default_params();
        llama_model* model = llama_model_load_from_file("C:/Users/dk488/Documents/GitHub/Neural-Network/headers/tinyllama.gguf", model_params);
        if (!model) {
            std::cerr << "❌ Failed to load model\n";
            return;
        }

        //creating context..
        llama_context_params ctx_params = llama_context_default_params();
        ctx_params.n_ctx = 2048;
        llama_context* ctx = llama_init_from_model(model, ctx_params);


    }

};

