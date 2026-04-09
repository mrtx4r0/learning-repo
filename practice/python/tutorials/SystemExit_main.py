#! /usr/bin/env python3
import sys
def main():
    print("hello, world from main()")
    return 0

if __name__ == "__main__":
    raise SystemExit(main()) # raise SystemExit()でOSに終了コードを返せる
