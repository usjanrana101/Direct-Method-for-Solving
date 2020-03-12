#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Mar 12 15:57:46 2020

@author: jaga
"""

import numpy as np
A=np.array([[1,0.67,0.33],[0.45,1,0.55],[0.67,0.33,1]])
b=np.array([2,2,2])
print ("Solution of the Linear System Ax=b : \n [x1,x2,x3] = ",np.linalg.solve(A,b))