from display import *
from matrix import *


def draw_lines( matrix, screen, color ):
    pass

def add_edge( matrix, x0, y0, z0, x1, y1, z1 ):
    pass

def add_point( matrix, x, y, z=0 ):
    pass



def draw_line (x0, y0, x1, y1, screen, color):
    
    x = x0
    y = y0
    
    A = y1 - y
    B = -1 * (x1 - x)
    
    # if change in x is = 0 (vertical line, undefined)
    if (B == 0):
        while (y <= y1):
            plot(screen, color, x, y)
            y += 1
    # if change in y is = 0 (horizontal line)
    elif (A == 0):
        while (x <= x1):
            plot(screen, color, x, y)
            x += 1 
    else:
        slope = A / (-1 * B)
        
        # Octant I
        if (slope >= 0 and slope <= 1):
            d = 2 * A + B
            while (x <= x1):
                plot(screen, color, x, y)
                if (d > 0):
                    y += 1
                    d += 2 * B
                x += 1
                d += 2 * A
            
        # Octant II
        elif (slope > 1):
            d = A + 2 * B
            while (y <= y1):
               plot(screen, color, x, y)
               if (d < 0):
                   x += 1
                   d += 2 * A
               y += 1
               d += 2 * B  

        # Octant VIII
        elif (slope >= -1 and slope < 0):
            d = 2 * A - B
            while (x <= x1):
               plot(screen, color, x, y)
               if (d < 0):
                   y -= 1
                   d -= 2 * B
               x += 1
               d += 2 * A
               
        # Octant VII       
        elif (slope < -1):
            d = A - 2 * B
            while (y >= y1):
                plot(screen, color, x, y)
                if (d > 0):
                    x += 1
                    d += 2 * A
                y -= 1
                d -= 2 * B    
#end draw_line
