#include<Python.h>
/*
    提供函数接口让python调用
    g++ -fPIC -shared called_cpp.cpp -o called_cpp.so -I /usr/include/python2.7/ -lpython2.7
*/


extern "C"
int add_func(int a,int b) 
{
    return a+b;
}

extern "C"
{
static PyObject *_add_func(PyObject *self, PyObject *args)
{
    int _a,_b;
    int res;

    if (!PyArg_ParseTuple(args, "ii", &_a, &_b))
        return NULL;
    res = add_func(_a, _b);
    return PyLong_FromLong(res);
}
}
extern "C"
{
static PyMethodDef CppModuleMethods[] = 
{
    {
        "add_func",
        _add_func,
        METH_VARARGS,
        ""
    },
    {NULL, NULL, 0, NULL}
};
}
extern "C"
PyMODINIT_FUNC initcpp_module(void) 
{
    (void) Py_InitModule("called_cpp", CppModuleMethods);
}



