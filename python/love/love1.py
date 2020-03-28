#!/usr/bin/python
# -*- coding: UTF-8 -*-
'''
print('\n'.join([''.join([('I LOVE U'[(x - y) % 8] if ((x * 0.05)**2 + (y * 0.1)**2 - 1)**3 -
      (x * 0.05)**2 * (y * 0.1)**3 <= 0 else ' ') for x in range(-30, 30)]) for y in range(15, -15, -1)]))
'''
'''
import time
def heart_text_animation(words="I LOVE U"):
  
  for c in words.split():
    line = []
    for y in range(15, -15, -1):
        line_c = []
        letters = ''
        for x in range(-30, 30):
            expression = ((x*0.05)**2+(y*0.1)**2-1)**3-(x*0.05)**2*(y*0.1)**3
            if expression <= 0:
                letters += c[(x-y) % len(c)]
            else:
                letters += ' '
        line_c.append(letters)
        line += line_c
    print('\n'.join(line))
    time.sleep(1)

if __name__ == "__main__":
    heart_text_animation(words="I LOVE U")
'''
import matplotlib.pyplot as plt
import numpy as np

t = np.arange(0,2*np.pi, 0.1)
x = 16*np.sin(t)**3
y = 13*np.cos(t)-5*np.cos(2*t)-2*np.cos(3*t)-np.cos(4*t)

plt.figure(figsize=(8,6), dpi=80, facecolor='white')
plt.plot(x,y,color='red')
plt.axis('off')
plt.fill(x,y,'hotpink')
plt.text(0, -0.4, 'ME & YOU', fontsize=36, fontweight='bold',
           color='black', horizontalalignment='center')
plt.show()