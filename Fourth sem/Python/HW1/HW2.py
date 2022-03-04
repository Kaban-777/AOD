import math


def function(z):
    if z < - 12:
        x = (math.pow(math.sin(z), 5) - 52 * math.pow(43 * z - math.pow(z, 2) /
             47 - 39, 3) - z)
    elif - 12 <= z < 83:
        x = (math.pow(math.cos(math.pow(z, 3) + z / 62 + math.pow(z, 2)), 4) +
             28 * math.pow(math.pow(z, 2) - 1 - z, 6))
    elif 83 <= z < 170:
        x = math.pow(z + 77 + 14 * math.pow(z, 3), 3) / 84
    elif 170 <= z < 230:
        x = math.pow(1 + math.pow(z, 3) / 25 + math.pow(z, 2), 5)
    elif z >= 230:
        x = 78 * math.pow(13 * math.pow(z, 3) - 40 * math.pow(z, 2), 7) - 7 * z
    else:
        x = 0
    return x


def main():
    z1 = 112
    z2 = - 69
    print('%.2e' % function(z1))
    print('%.2e' % function(z2))


if __name__ == "__main__":
    main()
