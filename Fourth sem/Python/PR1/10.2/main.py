def fast_mul(a, b):
    if b != 0:
        x = int(a / 2)
        c = x * (a << 1)
        if a % 2 != 0:
            c += a
        if a % 2 != 0:
            for i in range(0, b - 2):
                y = x * (c << 1)
                c = c + y
        else:
            for i in range(0, b - 2):
                c = x * (c << 1)
    else:
        c = 1
    return c


def main():
    print("Введите числа a и b для вычисления операции возведения в стекпень:")
    a = int(input("a = "),)
    b = int(input("b = "),)

    print("Проверка:", a, "^", b, "=", a ** b)
    print("Результат функции:", fast_mul(a, b))


if __name__ == "__main__":
    main()
