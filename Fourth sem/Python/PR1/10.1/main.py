def fast_mul(a, b):
    x = int(b/2)
    c = x * (a << 1)
    if b%2 != 0:
        c += a
    return c


def main():
    print("Введите числа a и b для вычисления операции умножения:")
    a = int(input("a = "),)
    b = int(input("b = "),)

    print("Проверка:" , a, "*", b, "=", a * b)
    print("Результат функции:", fast_mul(a, b))


if __name__ == "__main__":
    main()