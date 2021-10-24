#import pyperclip
def main():
  print('What is your message?')
  myMessage = input('')
  myKey = 3
  
  ciphertext = encryptMessage(myKey, myMessage)
  
  
  # Print the encrypted string in ciphertext to the screen, with a | (called'pipe' character) after it in case there are spaces at the end of the encrypted message.
  print(ciphertext + '|')
  #pyperclip.copy(ciphertext)
  
def encryptMessage(key, message):
    ciphertext = [''] * key
    
    for col in range(key):
        pointer = col
    
        while pointer < len(message):
          ciphertext[col] += message[pointer]
          pointer += key
    return ''.join(ciphertext)
if __name__ == '__main__':
    main()
