#!coding = utf8

class A(object):
    def __init__(self, name):
        self.name = name
    def __eq__(self, other):
        if self.name == other.name:
            return True
        else:
            return False


if __name__ == '__main__':
    a = A('tom')
    b = A('tom')
    print("equal(%s)" % a == b)
    print("not equal(%s)" % a != b)