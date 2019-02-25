#!/usr/bin/env python
# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import numpy as np


class DrawTool(object):
    def __init__(self):
        pass

    @classmethod
    def draw_pic(cls):
        x = np.linspace(0, 2 * np.pi, 500)
        plt.plot(x, np.sin(x), x, np.sin(2 * x))
        plt.show()


    @classmethod
    def draw_histogram(cls):
        u"""
            绘制直方图
        :return:
        """
        x = np.random.rand(100)
        plt.hist(x, 50)
        plt.show()


if __name__ == '__main__':
    # DrawTool.draw_pic()
    DrawTool.draw_histogram()
