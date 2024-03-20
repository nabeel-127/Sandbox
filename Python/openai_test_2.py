import requests
import openai

url = "https://api.kapwing.com/images/ai/generate"

querystring = {"api_key": "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"}

payload = '{"prompt":"draw a blue bird"}'
headers = {"Content-Type": "application/json"}

response = requests.request(
    "POST", url, data=payload, headers=headers, params=querystring
)

print(response.json()["url"])
