from cs50 import get_string
from sys import argv
import sys

def main():

    # Correct # of command-lind arguments
    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        exit(1)

    file = open(argv[1])
    CensoredWords = set()
    for line in file:
        CensoredWords.add(line.strip().lower())

    # Prompt user to provide a message
    MessageString = get_string("What message would you like to censor?\n")
    OutputString = ""
    Words = MessageString.split()

    for word in Words:
        if word.lower() in CensoredWords:
            OutputString += "*" * len(word) + " "
        else:
            OutputString += word + " "
    print(OutputString.strip())


if __name__ == "__main__":
    main()
