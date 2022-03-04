def main():
    a = ["1", "2", "3", "4", "5"]
    x = 0
    for i in range(0, len(a), 2):
        x += int(a[i])
    print(x)


if __name__ == "__main__":
    main()
