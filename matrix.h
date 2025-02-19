#include"matrix.c"
extern struct matrix;

void sum_matrix(struct matrix* m, struct matrix* m1);
void set_matrix(struct matrix* m, int** massive);
void mult_matrix(struct matrix* m, struct matrix* m1);
void mult_num_matrix(struct matrix* m, int mult);
void transpositon(struct matrix* m);