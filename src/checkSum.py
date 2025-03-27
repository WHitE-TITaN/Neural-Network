from transformers import AutoModelForCausalLM, AutoTokenizer

# Load the saved model
model = AutoModelForCausalLM.from_pretrained("./gpt2-offline")
tokenizer = AutoTokenizer.from_pretrained("./gpt2-offline")

print("GPT-2 model loaded offline successfully!")
