from transformers import AutoModelForCausalLM, AutoTokenizer

model_name = "openai-community/gpt2"

# Load model and tokenizer
model = AutoModelForCausalLM.from_pretrained(model_name)
tokenizer = AutoTokenizer.from_pretrained(model_name)

# Save the model locally for offline use
model.save_pretrained("./gpt2-offline")
tokenizer.save_pretrained("./gpt2-offline")

print("Model downloaded and saved offline!")
