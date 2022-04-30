from math import log10


def main(n, a, b):
    s1 = 0.0
    s2 = 0.0
    s3 = 0.0
    s4 = 0.0
    m = 1.0
    for i in range(1, a + 1):
        for c in range(1, n + 1):
            s1 += (log10(i) ** 3) + 98 + c
        s4 += s1
    for i in range(1, n + 1):
        for j in range(1, b + 1):
            for c in range(1, a + 1):
                s2 += (((13 * (i ** 2)) - 90 * (j ** 3)) ** 4 -
                       (16 * (95 * j + 23 + (c ** 3)) ** 3))
            m *= s2
            s2 = 0
        s3 += m
        m = 1
    return s4 - s3


if __name__ == '__main__':
    n1 = 2
    a1 = 5
    b1 = 2
    n2 = 7
    a2 = 4
    b2 = 5
    print('%.2e' % main(n1, a1, b1))
    print('%.2e' % main(n2, a2, b2))
