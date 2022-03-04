def main():
    a = ["1234", "123456", "12345678", "12", "1"]
    x = "1"
    for i in range(len(a)):
        if len(a[i]) >= len(x):
            x = a[i]
    print(x)


if __name__ == "__main__":
    main()
