def main(field):
    A = (field & 0b00000000000000000000011111111111)
    B = (field & 0b00000111111111111111100000000000) << 5
    C = (field & 0b00011000000000000000000000000000) >> 16
    D = (field & 0b11100000000000000000000000000000) >> 16
    return A | B | C | D


if __name__ == '__main__':
    print('0x%02X' % main(0x0cb1d329))
    print('0x%02X' % main(0x5e3ff8ba))
