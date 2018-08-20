# -*- coding: utf-8 -*-
from matplotlib import pyplot as plt
import numpy as np

seconds = np.array([
    16.929381,
    8.616441,
    4.243246,
    2.232025,
    1.117120
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
plt.title('Pi MC OMP speedup')
plt.xlabel('threads')
plt.ylabel('seconds')
plt.show()

plt.savefig('pi_MC_OMP_speedup.png')
