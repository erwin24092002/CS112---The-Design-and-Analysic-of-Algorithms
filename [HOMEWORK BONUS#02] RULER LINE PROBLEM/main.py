from ruler import Ruler 
import numpy as np

l = int(input('Enter the length of the ruler: '))
h = int(input('Enter the width of the ruler: '))

ruler = Ruler(l, h)
sol = ruler.set_rulerline()
print('Number of Ruler line: ', len(sol))
print("Solution \n", np.array(sol))
ruler.display()
