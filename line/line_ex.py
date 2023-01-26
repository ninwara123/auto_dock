# import pandas as pd
 
# # read by default 1st sheet of an excel file
# df = pd.read_excel('random.xls')

# # print(df)
# print(df["x"])
# x_list = df['x'].tolist()
# y_list = df['y'].tolist()
# # print(x_list)


import numpy as np 
import math
from fractions import Fraction
from scipy.odr import *
class featuresDetection:
    def __init__(self):
        self.EPSILON = 10
        self.DELTA = 501
        self.SNUM = 6
        self.PMIN = 20 
        self.GMAX = 20 
        self.SEED_SIGMENTS = []
        self.LINE_SIGMENTS = []
        self.LASERPOINTS = []
        self.LINE_PARAMS = None
        self.NP = len(self.LASERPOINTS)-1
        self.LMIN = 20
        self.LR = 0
        self.PR = 0

    def dist_point2point(self, point1, point2):
        Px = (point1[0] - point2[0])** 2

        Py = (point1[1] - point2[1])** 2
        return math.sqrt(Px + Py)
        # distance point to line written in the genearl form
    def dist_point21ine(self, params, point):
        A, B, C = params
        distance = abs(A*point[0]+B*point[1]+C)/math.sqrt(A**2 + B **2)
        return distance
        
    # def line_2points(self)

