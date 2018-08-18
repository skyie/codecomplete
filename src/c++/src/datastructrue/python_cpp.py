import sys
sys.path.append("./")


# refer to https://blog.csdn.net/u012234115/article/details/50210835
from called_cpp import _add_func





print "python call C/C++ function:"
print add_func(7,12)

