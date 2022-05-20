import re


def main(a):
    result = {}
    a = a.split('data')
    for i in range(len(a)):
        a[i] = a[i].replace('\n', ' ')
        key = re.search(r'.*<', a[i])
        if key:
            value = re.search(r'\|.*;', a[i])[0][1:-1].strip('; ]')
            result[key[0][:-1].strip()] = int(value)
    return result

print(main(".do [ data zaisar <| 5455; ]; [ data onve <| 9675; ]; [ data bicexe_144<| -5371; ]; [data ersoes<|-3503;];.end"))
