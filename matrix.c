#include<stdio.h>
#include<stdlib.h>
struct matrix{
    int** mat;
    int width;
    int height;
};
void set_matrix(struct matrix* m, int** massive){
    m->mat= calloc(m->height,sizeof(int*));
    int rows = malloc(sizeof(int)*m->height);
    for(int i=0; i<m->height; i++){
        m->mat[i] = calloc(rows,sizeof(int));
        for(int j=0; j<m->width; j++){
            int res = *massive;
            m->mat[i][j] = res;
            massive++;
            //printf("%i\n",m->mat[i][j]);
        }
    }
}
void sum_matrix(struct matrix* m, struct matrix* m1){
    for(int i=0; i<m->height; i++){
        for(int j=0; j<m->width; j++){
            printf("%i\n",m->mat[i][j]);
            int res = m1->mat[i][j];
            m->mat[i][j] = m->mat[i][j]+res;
        }
    }
}
void mult_num_matrix(struct matrix* m, int mult){
    for(int i=0; i<m->height; i++){
        for(int j=0; j<m->width; j++){
            m->mat[i][j] *= mult;
            printf("%i\n",m->mat[i][j]);
        }
    }
}
void mult_matrix(struct matrix* m, struct matrix* m1){
    if(m1->width!=m->height){ //CHECK WIDTH OF m1 AND HEIGHT OF m
        return;
    }
    int rows = malloc(sizeof(int)*m1->height);
    int** res = calloc(m->width,sizeof(int*));
    for(int i=0; i<m1->height; i++){
        res[i] = calloc(rows,sizeof(int));
        for(int j=0; j<m1->width; j++){
            //for(int i1=0; i1<m->height; i1++){
                for(int j1=0; j1<m->width; j1++){
                    int a = m->mat[j][j1];
                    int b = m1->mat[i][j];
                    res[i][j1] += a*b;
                    //printf("%i,",res[i][j1]);
                }
            //}
        }
        //printf("\n\n");
    }
    free(m->mat);
    m->mat = res;
    m->height = m1->height;
    for(int i=0; i<m->height; i++){
        for(int j=0; j<m->width; j++){
            printf("%i",m->mat[i][j]);
        }
        printf("\n\n");
    }
    /*for(int i=0; i<m->height; i++){
        for(int j=0; j<m->width; j++){
            int** res = calloc(m1->width,sizeof(int*));
            for(int j1=0; j1<m1->width; j1++){
                int mat1 = m1->mat[i][j1];
                int mat2 = m->mat[j1][j];
                res[j1] = mat1 * mat2;
                //printf("%i * %i. %i  %i \n",m1->mat[i][j1],m->mat[j1][j], j1, j);
                //printf("%i\n",res[j1]);
            }
            for(int i1=0; i1<m1->width; i1++){
                int mat = res[i1];
                m->mat[i][j] += mat;
            }
            printf("%i,",m->mat[i][j]);
            free(res);
        }
        printf("\n\n");
    }*/
}