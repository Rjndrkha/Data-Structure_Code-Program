from gtts import gTTS
import os

text_to_speak = "Hello everyone! how's the josh of Hacktober going ! This is just a beginner code for converting text to speech"
language = 'en'

myobj = gTTS(text=text_to_speak, lang=language, slow=False)

myobj.save("play.mp3")

os.system("play.mp3")
