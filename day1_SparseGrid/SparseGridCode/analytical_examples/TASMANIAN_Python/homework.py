# necessary import for every use of TASMANIAN
#
import matplotlib
matplotlib.use('Agg')
import TasmanianSG
import numpy as np

# imports specifically needed by the examples
import math
from random import uniform
from datetime import datetime

import matplotlib.pyplot as plt

print("TasmanianSG version: {0:s}".format(TasmanianSG.__version__))
print("TasmanianSG license: {0:s}".format(TasmanianSG.__license__))

grid  = TasmanianSG.TasmanianSparseGrid()
grid1 = TasmanianSG.TasmanianSparseGrid()
grid2 = TasmanianSG.TasmanianSparseGrid()

#############################################################################

# Oscillatory for OSM:
# interpolate: f(x, y) = cos(2 * pi * w1 + c1 * x + c2 * y)
# using piecewise linear basis functions.

# set containers
nvec = np.arange(10, 10000, 1000)
errvec = np.zeros(len(nvec))

# set parameters w and c
w = np.array([.5, .75])
c = np.array([.5, .75])

# set function

for i, n in enumerate(nvec):

    # 1000 2-dimensional sample points
    aPnts = np.empty([n, 2])
    for iI in range(n):
        for iJ in range(2):
            aPnts[iI][iJ] = uniform(-1.0, 1.0)

    # Result
    aTres = np.empty([n,])
    for iI in range(n):
        aTres[iI] = math.cos(2 * math.pi *  w[0] + aPnts[iI][0] * c[0] + aPnts[iI][1] * c[1])

    # Sparse Grid with dimension 2 and 1 output and refinement level 5
    iDim = 2
    iOut = 1
    iDepth = 5
    which_basis = 1 #1= linear basis functions -> Check the manual for other options

    print("\n-------------------------------------------------------------------------------------------------")
    print("Example 1 for OSM: interpolate f(x, y) = cos(2 * pi * w1 + c1 * x + c2 * y)")
    print("       using fixed sparse grid with depth {0:1d}".format(iDepth))
    print("       the error is estimated as the maximum from " + str(nvec[i]) + " random points\n")

    # construct sparse grid
    grid.makeLocalPolynomialGrid(iDim, iOut, iDepth, which_basis, "localp")
    aPoints = grid.getPoints()
    iNumP1 = aPoints.shape[0]
    aVals = np.empty([aPoints.shape[0], 1])
    for iI in range(aPoints.shape[0]):
        aVals[iI] = math.cos(2 * math.pi *  w[0] + aPoints[iI][0] * c[0] + aPoints[iI][1] * c[1])
    grid.loadNeededPoints(aVals)

    # compute the error
    aRes = grid.evaluateBatch(aPnts)
    errvec[i] = max(np.fabs(aRes[:,0] - aTres))
    print(" For localp    Number of points: {0:1d}   Max. Error: {1:1.16e}".format(iNumP1, errvec[i]))



plt.yscale('log')
plt.xscale('log')
plt.plot(nvec, errvec, 'bo')
plt.xlabel('Number points')
plt.ylabel('Max error')
plt.savefig('maxerror.png')

plt.plot(aPoints[:,0], aPoints[:,1], 'bo')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Sparse grid')
plt.savefig('sparsegrid.png')
