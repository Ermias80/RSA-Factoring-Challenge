#!/usr/bin/python3
import sys

def factorize(n):
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return i, n // i
    return n, 1

def main():
    if len(sys.argv) != 2:
        print("Usage: {} <file>".format(sys.argv[0]))
        sys.exit(1)

    input_file = sys.argv[1]

    with open(input_file, 'r') as f:
        numbers = f.read().strip().split('\n')

    for number in numbers:
        n = int(number)
        p, q = factorize(n)
        print("{}={}*{}".format(n, p, q))

if __name__ == "__main__":
    main()
