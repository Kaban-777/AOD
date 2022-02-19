def fast_mul_gen(a):
    print("a =", a)
    for i in range(2):
        a = (a << 1)
        print("a = a + a =", a)
    a = (a << 1) + a
    print("a = a + a + a =", a)
    return a


def main():
    print("Введите число 'a' для вычисления операции умножения на 12:")
    a = int(input("a = "),)

    print("Проверка:", a, "* 12 =", a * 12)
    print("Результат функции:", fast_mul_gen(a))


if __name__ == "__main__":
    main()