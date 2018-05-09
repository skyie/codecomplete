#!/usr/bin/python

class TestObj(object):
    def __init__(self, name):
        self.name = name

    def add_prefix(self, prefix):
        return prefix + self.name

def add_func(a, b):
    return a + b
