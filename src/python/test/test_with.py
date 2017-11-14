#coding = utf8 

"""
with example
"""
class FileHandle(object):
    def __init__(self, filename):
        self.filename = filename
        
    def __enter__(self):
        self.file = open(self.filename, "r")
        print("in enter")
        return self.file
    def __exit__(self, type, value, trace):
        if self.file:
            self.file.close()
        print("in exit\ntype:%s \nvalue:%s\n"  % (type, value))
    
if __name__ == '__main__':
    with FileHandle("main.py") as f: #f是FileHandle的返回值
        for line in f.readlines():
            print(line)