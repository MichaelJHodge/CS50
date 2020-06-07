from cs50 import get_int, get_float


def main():
    while True:
        # Get input from the user
        dollars_owed = get_float("How much change is owed?: ")
        cents_owed = round(dollars_owed * 100)

        if cents_owed > 0:
            break

    q = cents_owed // 25
    d = (cents_owed % 25) // 10
    n = ((cents_owed % 25) % 10) // 5
    p = ((cents_owed % 25) % 10) % 5

    print(f"{q + d + n + p}")


if __name__ == "__main__":
    main()