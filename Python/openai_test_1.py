import openai

# umair's key: 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

openai.api_key = "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"
# response = openai.Completion.create(
#     engine="ada", text="A cat sitting on a beach", num_images=1
# )
# image_url = response["images"][0]["output_url"]


response = openai.Image.create(prompt="a white siamese cat", n=1, size="1024x1024")
image_url = response["data"][0]["url"]
