def main():
    a = ["1", "2", "3", "4", "5", "4"]
    x = 0
    for i in range(len(a), 1):
        x += a[i]
    print(x)


if __name__ == "__main__":
    main()
