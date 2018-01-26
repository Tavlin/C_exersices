#I have no idea
import numpy as np
import matplotlib.pyplot as plt

with open("test.txt") as f:
    data = f.read()
    
data = data.split('\n')

fig, ax1 = plt.subplots()
x = [row.split(' ')[0] for row in data]
y = [row.split(' ')[0] for row in data]
ax1.plot(x, y, 'b-')
ax1.set_xlabel('value')
# Make the y-axis label, ticks and tick labels match the line color.
ax1.set_ylabel('capacity', color='b')
ax1.tick_params('y', colors='b')

ax2 = ax1.twinx()
s2 = np.sqrt(3*6)
ax2.plot(x, s2, 'r.')
ax2.set_ylabel('something', color='r')
ax2.tick_params('y', colors='r')

fig.tight_layout()
plt.show()

