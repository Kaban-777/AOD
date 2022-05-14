from math import ceil


def main(y, x):
    sum = 0
    for n in range(1, len(y) + 1):
        sum += ((35 + x[n + 1 - ceil(n / 4)] ** 2 + 79 * y[ceil(n / 4)] ** 3) ** 4) / 93
    return 22 * sum


if __name__ == '__main__':
    y1 = [0.76, -0.57, 0.74, 0.39, -0.9, 0.49]
    x1 = [0.71, 0.25, -0.57, 0.05, -0.03, 0.67]
    y2 = [0.34, -0.53, -0.32, -0.7, -0.44, -0.54]
    x2 = [0.34, -0.53, -0.32, -0.7, -0.44, -0.54]
    print('%.2e' % main(y1, x1))
    # print('%.2e' % main(y2, x2))
