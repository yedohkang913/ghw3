#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;
  clear_screen(s);
  struct matrix *edges;

  edges = new_matrix(4, 4);
	
	printf("Here is an empty matrix:\n");
	print_matrix(edges);
	printf("Here is an identity matrix:\n");
	ident(edges);
	print_matrix(edges);
	
  struct matrix * tester = new_matrix(2, 2);
  tester -> m[0][0] = 1;
  tester -> m[0][1] = 2;
  tester -> m[1][0] = 3;
  tester -> m[1][1] = 4;
  printf("Here's my 1st test matrix:\n");
  print_matrix(tester);
	
  struct matrix * tester1 = new_matrix(2, 2);
  tester1 -> m[0][0] = 2;
  tester1 -> m[0][1] = 0;
  tester1 -> m[1][0] = 1;
  tester1 -> m[1][1] = 2;
  printf("Here's my 2nd test matrix:\n");
  print_matrix(tester1);
	
	printf("Result of multiplying the two above matrices:\n");
	matrix_mult(tester, tester1);
	print_matrix(tester1);
	
	printf("Result of multipling identity matrix with result:\n");
	ident(tester);
	matrix_mult(tester, tester1);
	print_matrix(tester1);
	free_matrix(tester);
	free_matrix(tester1);
	
	struct matrix *ed;
	ed = new_matrix(4,1);

  c.red = 200;
  c.green = 13;
  c.blue = 122;
  add_edge(ed, 50, 50, 0, 100, 111, 0);
  add_edge(ed, 300, 155, 0, 420, 375, 0);
  add_edge(ed, 220, 175, 0, 300, 100, 0);
  add_edge(ed, 100, 225, 0, 250, 100, 0);
  add_edge(ed, 150, 100, 0, 250, 300, 0);

  draw_lines(ed, s, c);
  free(ed);
	
	ed = new_matrix(4,1);

  c.red = 220;
  c.green = 113;
  c.blue = 12;
  add_edge(ed, 50, 100, 0, 220, 221, 0);
  add_edge(ed, 400, 255, 0, 230, 325, 0);
  add_edge(ed, 120, 175, 0, 300, 20, 0);
  add_edge(ed, 200, 235, 0, 290, 220, 0);
  add_edge(ed, 155, 110, 0, 290, 400, 0);

  draw_lines(ed, s, c);
  free(ed);
  display(s);
	
  save_extension(s, "result.png");
  free_matrix( edges );
	free_matrix(ed);

}
