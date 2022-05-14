def main(n):
    if n == 0:
        return - 0.56
    elif n == 1:
        return 0.09
    elif n >= 2:
        return main(n - 1) ** 3 - ((main(n - 2) ** 2) / 65) - main(n - 1)


if __name__ == '__main__':
    n1 = 3
    n2 = 5
    print('%.2e' % main(n1))
    print('%.2e' % main(n2))
