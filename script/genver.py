# genver.py - version file generator

import argparse
import datetime

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("program")
    parser.add_argument("version")
    args = parser.parse_args()
    with open("./.buildno") as fp:
        buildno = int(fp.read())
    buildno += 1
    with open("./.buildno", "w") as fp:
        fp.write(f"{buildno}")
    output = f"{args.program}\n\n"
    output += f"Version Number: {args.version}\n"
    output += f"Build Number: {buildno}\n"
    output += f"Build Date: {datetime.datetime.now()}\n"
    with open("./asset/version.txt", "w") as fp:
        fp.write(output)
    return 0

if __name__ == "__main__":
    main()
