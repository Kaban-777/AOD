def first():  #12
    x = 5
    a = x * 12
    print('x * 12 = ', a)
    b = x + x
    b = b + b
    b = b + b + b
    print("sum = ", b, "\n")

def second():  #16
    x = 5
    a = x * 16
    print("x * 16 = ", a)
    b = x + x
    b += b
    b += b
    b += b
    print("sum = ", b, "\n")

def third(): #15
    x = 5
    a = x * 15
    print("x * 15 = ", a)
    b = x + x
    b = b + b
    b = b + b
    x = x - b
    b = b - x
    print("sum = ", b, "\n")

def fourth(): #29
    x = 5
    a = x * 29
    print("x * 29 = ", a)
    b = x + x
    b = b + b + x
    b = b + b
    b = b + b + b - x
    print("sum = ", b, "\n")


first(), second(), third(), fourth()