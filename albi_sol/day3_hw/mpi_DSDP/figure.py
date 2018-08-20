# -*- coding: utf-8 -*-
from matplotlib import pyplot as plt
import numpy as np

seconds = np.array([
    80.025443,
    70.699182,
    68.866720,
    68.702679,
    68.716554
    ])
threads = np.array([
    1,
    2,
    4,
    8,
    16
    ])
seconds = seconds / seconds[0]
print(seconds)
plt.plot(threads, seconds, 'o')
plt.plot(threads, seconds)
plt.title('DSDP MPI 1 node relative speedup')
plt.xlabel('threads')
plt.ylabel('seconds')
plt.show()

plt.savefig('DSDP_MPI_speedup.png')
