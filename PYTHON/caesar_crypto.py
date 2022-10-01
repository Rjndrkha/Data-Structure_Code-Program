class Caesar:
  
	def __init__(self,plainText,key):
		self.plainText = str.lower(plainText)
		self.key = key
    
	def encrypt(self):
		abjad = "abcdefghijklmnopqrstuvwxyz 0123456789"
		chiperText = ""
		for words in self.plainText:
			wordsIndex = (abjad.find(words)+self.key)%len(abjad)
			chiperText= chiperText+abjad[wordsIndex]
		return chiperText

	def decrypt(self):
		abjad = "abcdefghijklmnopqrstuvwxyz 0123456789"
		chiperText = ""
		for words in self.plainText:
			wordsIndex = (abjad.find(words)-self.key)%len(abjad)
			chiperText= chiperText+abjad[wordsIndex]
		return chiperText


def main():
    text = "Hello World"
    key = 5
    encryp_caesar = Caesar(text, key)

    encrypt_text = encryp_caesar.encrypt()
    
    decrypt_caesar = Caesar(encrypt_text, key)
    
    decrypt_text = decrypt_caesar.decrypt()

    print("encrypt text = ", encrypt_text)
    print("decrypt text = ", decrypt_text)


if __name__ == "__main__":
    main()