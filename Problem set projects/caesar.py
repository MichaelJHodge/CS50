import sys
from cs50 import get_string, get_int


def main():
    if len(sys.argv) != 2:
        print("Please use correct # of arguments!")
        sys.exit(1)

    k = int(sys.argv[1])
    plaintext = get_string("plaintext: ")

    print("ciphertext: ", end="")

    for ch in plaintext:
        if not ch.isalpha():
            print(ch, end="")
            continue

        ascii_offset = 65 if ch.isupper() else 97

        p = ord(ch) - ascii_offset
        c = (p + k) % 26

        print(chr(c + ascii_offset), end="")

    print()
    return 0


if __name__ == "__main__":
    main()