#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

/*======== void add_point() ==========
Inputs:   struct matrix * points
int x
int y
int z 
Returns: 
adds point (x, y, z) to points and increment points.lastcol
if points is full, should call grow on points
====================*/
void add_point( struct matrix * points, double x, double y, double z) {
	if (points->lastcol == points->cols) {
		grow_matrix(points, points->cols+2);
	}
	points -> m[0][points -> lastcol] = x;
	points -> m[1][points -> lastcol] = y;
	points -> m[2][points -> lastcol] = z;
	points -> m[3][points -> lastcol] = 1;
	points -> lastcol++;
}

/*======== void add_edge() ==========
Inputs:   struct matrix * points
int x0, int y0, int z0, int x1, int y1, int z1
Returns: 
add the line connecting (x0, y0, z0) to (x1, y1, z1) to points
should use add_point
====================*/
void add_edge( struct matrix * points, double x0, double y0, double z0, double x1, double y1, double z1) {
	add_point(points, x0, y0, z0);
	add_point(points, x1, y1, z1);
}

/*======== void draw_lines() ==========
Inputs:   struct matrix * points
screen s
color c 
Returns: 
Go through points 2 at a time and call draw_line to add that line
to the screen
====================*/
void draw_lines( struct matrix * points, screen s, color c) {
	int i;
	for(i = 0; i < points->lastcol; i+=2){
		draw_line(points->m[0][i], points->m[1][i], points->m[0][i+1], points->m[1][i+1], s, c);
	}
}

void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

	int x = x0;
	int y = y0;
  
	int A = y1 - y;
	int B = -1 * (x1 - x);
  
	// if change in x is = 0 (vertical line, undefined)
	if (B == 0) {
		while (y <= y1){
			plot(s, c, x, y);
			y += 1;
		}
	}
	// if change in y is = 0 (horizontal line)
	else if (A == 0){
		while (x <= x1){
			plot(s, c, x, y);
			x += 1;
		}
	}
	else{
		int slope = A / (-1 * B);
      
		// Octant I
		if (slope >= 0 && slope <= 1){
			int d = 2 * A + B;
			while (x <= x1){
				plot(s, c, x, y);
				if (d > 0){
					y += 1;
					d += 2 * B;
				}
				x += 1;
				d += 2 * A;
			}
		}
							
          
		// Octant II
		else if (slope > 1) {
			int d = A + 2 * B;
			while (y <= y1){
				plot(s, c, x, y);
				if (d < 0){
					x += 1;
					d += 2 * A;
				}
				y += 1;
				d += 2 * B;
			}
		}

		// Octant VIII
		else if (slope >= -1 && slope < 0){
			int d = 2 * A - B;
			while (x <= x1){
				plot(s, c, x, y);
				if (d < 0){
					y -= 1;
					d -= 2 * B;
				}
				x += 1;
				d += 2 * A;
			}
		}
             
		// Octant VII       
		else if (slope < -1){
			int d = A - 2 * B;
			while (y >= y1){
				plot(s, c, x, y);
				if (d > 0){
					x += 1;
					d += 2 * A;
				}
				y -= 1;
				d -= 2 * B;
			}
		}
	}
}
