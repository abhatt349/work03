#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"


int main() {

  screen s;
  color c;
  struct matrix *edges;
  struct matrix *id;
  struct matrix *m;

  edges = new_matrix(4, 1);
  id = new_matrix(4, 4);
  m = new_matrix(4, 1);

  printf("edge addition\n");
  add_edge(edges, 100, 100, 0, 110, 300, 0);
  add_edge(edges, 110, 300, 0, 120, 500, 0);
  print_matrix(edges);

  printf("\npoint addition\n");
  add_point(m, 1, 2, 0);
  add_point(m, 2, 0, 0);
  add_point(m, 3, 3, 0);
  add_point(m, 6, 3, 0);
  print_matrix(m);

  printf("\nmatrix mult\n");
  printf("\nleft matrix (edges):\n");
  print_matrix(edges);
  printf("\nright matrix (m):\n");
  print_matrix(m);
  printf("\nresult after multiplication\n");
  matrix_mult(edges, m);
  print_matrix(m);

  printf("\nidentity matrix:\n");
  ident(id);
  print_matrix(id);

  printf("\nmult by identity matrix\n");
  printf("before:\n");
  print_matrix(edges);
  printf("after:\n");
  matrix_mult(id, edges);
  print_matrix(edges);

  free(edges);
  edges = new_matrix(4, 1);

  srand(time(NULL));
  c.red = 255;
  c.green = 0;
  c.blue = 0;

  int i;
  for (i = 0; i < 50; i++) {
    add_point(edges, rand() % 500, rand() % 500, 0);
  }
  //triangle (extra test cases)
  //add_edge(edges, 300, 200, 0, 500, 200, 0);
  //add_edge(edges, 500, 200, 0, 350, 400, 0);
  //add_edge(edges, 350, 400, 0, 300, 200, 0);

  printf("\nedge matrix:\n");
  print_matrix(edges);

  draw_lines(edges, s, c);

  save_ppm(s, "matrix.ppm");
  free_matrix(edges);
}
