# -*- coding: utf-8 -*-
from matplotlib import pyplot as plt
import numpy as np

seconds = np.array([
    54.537497121,
    33.606769538,
    18.503835911,
    10.816416261,
    5.701376772
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
plt.title('DSDP OMP speedup')
plt.xlabel('threads')
plt.ylabel('seconds')
plt.show()

plt.savefig('DSDP_OMP_speedup.png')
