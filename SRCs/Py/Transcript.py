import whisper

model = whisper.load_model("base")
result = model.transcribe("Prompt.mp3")
print(result["text"])
