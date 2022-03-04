import math


def function(y, x):
    a = (57 * math.pow(math.acos(y), 3) - (71 * math.pow(x, 5)))
    b = (11 * math.pow(x, 5) - (67 * math.pow(y, 3)))
    c = math.pow(math.sqrt(87 * math.pow(y, 3) + (11 * y) + math.pow(x, 2)), 5)
    d = math.pow(math.fabs(4 * math.pow(x, 3) - (83 * math.pow(y, 2))), 3) / 91
    e = (a / b) - (c / d)
    return e


def main():
    y1 = 0.88
    x1 = - 0.31
    y2 = 0.42
    x2 = 0.63

    print('%.2e' % function(y1, x1))
    print('%.2e' % function(y2, x2))


if __name__ == "__main__":
    main()
