def main(a: list):
    res = [[], [], [], []]
    i = 0
    while i < len(a):
        for j in reversed(range(len(a[i]))):
            if (a[i].count(a[i][j]) > 1 or a[i][j] is None):
                del a[i][j]
        if len(a[i]) == 0:
            del a[i]
        else:
            cell = a[i][1].split(';')
            a[i][0] = a[i][0].replace('(', '').replace(')', '')
            res[0].append(a[i][0][:10] + a[i][0][11:])
            if cell[1] == '1':
                res[1].append('Да')
            else:
                res[1].append('Нет')
            res[2].append(cell[0][:6] + cell[0][8:])
            res[3].append(a[i][2][5:])
            i += 1
    return res


print(main([['(570) 621-17-63', '16.05.2004;0', '(570) 621-17-63', 'Д.Ч. Дукли'],
            ['(740) 252-47-80', '22.07.2004;1', '(740) 252-47-80', 'Г.К. Зишов'],
            [None, None, None, None, None],
            [None, None, None, None, None],
            ['(952) 250-52-35', '01.02.2002;0', '(952) 250-52-35', 'С.Н. Лоциди'],
            ['(335) 317-08-01', '04.08.2001;1', '(335) 317-08-01', 'А.Ф. Шешянц']]))
