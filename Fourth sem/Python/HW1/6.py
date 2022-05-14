def main(x):
    if x[1] == 1971:
        return 12
    elif x[1] == 1988:
        return x1988(x)
    else:
        return x1950(x)


def x4(x):
    if x[4] == 'NGINX':
        return 0
    elif x[4] == 'MUF':
        return 1
    else:
        return 2


def x1988(x):
    if x[3] == 'UNO':
        return 8
    elif x[3] == 'GRACE':
        return 11
    else:
        if x[0] == 'GLSL':
            return 9
        else:
            return 10


def x1950(x):
    if x[3] == 'GRACE':
        return 7
    elif x[3] == 'GAMS':
        if x[0] == 'GLSL':
            return 5
        else:
            return 6
    else:
        if x[2] == 'CSV':
            return 4
        elif x[2] == 'MQL5':
            return 3
        else:
            return x4(x)


if __name__ == '__main__':
    x1 = ['SQL', 1959, 'MQL5', 'UNO', 'NGINX']
    x2 = ['GLSL', 1971, 'ROUGE', 'UNO', 'NGINX']
    print(main(x1))
    # print(main(x2))
