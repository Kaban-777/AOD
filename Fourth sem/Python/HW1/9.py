class A:
    state = 'A'

    def slur(self):
        if self.state == 'A':
            self.state = 'B'
            return 0
        elif self.state == 'B':
            self.state = 'C'
            return 1
        elif self.state == 'D':
            self.state = 'E'
            return 4
        elif self.state == 'F':
            self.state = 'G'
            return 7
        else:
            raise KeyError

    def type(self):
        if self.state == 'C':
            return 3
        elif self.state == 'E':
            self.state = 'F'
            return 5
        elif self.state == 'F':
            self.state = 'C'
            return 8
        else:
            raise KeyError

    def play(self):
        if self.state == 'C':
            self.state = 'D'
            return 2
        elif self.state == 'E':
            return 6
        elif self.state == 'F':
            self.state = 'A'
            return 9
        else:
            raise KeyError


def main():
    return A()


o = main()
