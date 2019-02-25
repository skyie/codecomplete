#!/usr/bin/env python
# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import numpy as np
from xlrd import open_workbook


class XslTool(object):
    def __init__(self):
        pass

    @classmethod
    def read(cls, filepath):
        u"""
            关于ASCII,unicode,UTF-8编码关系
            https://www.liaoxuefeng.com/wiki/001374738125095c955c1e6d8bb493182103fac9270762a000/001386819196283586a37629844456ca7e5a7faa9b94ee8000
        """
        if not filepath:
            return
        x_data = []
        y_data = []
        xls_sheet = open_workbook(filepath)
        for sheet in xls_sheet.sheets():
            print("sheet: %s", sheet)
            for row in range(sheet.nrows):
                print("row: %s", row)
                values = []
                for col in range(sheet.ncols):
                    value = sheet.cell(row, col).value
                    if isinstance(value, unicode):
                        # unicode转成UTF-8来打印中文
                        value = u' '.join(value).encode('utf-8').strip()
                    # 使用print("%s", value) 打印十六进制，无法打印中文?
                    print value
                    values.append(value)
                x_data.append(values[0])
                y_data.append(values[1])

if __name__ == '__main__':
    XslTool.read("./name.xlsx")
