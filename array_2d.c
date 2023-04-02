#include <stdio.h>
struct my_array{
    int a[3][3];
};

void create(struct my_array * m);
void display(struct my_array m);
void addition(struct my_array *sum, struct my_array *m1, struct my_array *m2);
void multiply(struct my_array *mul, struct my_array *m1, struct my_array *m2);
void transpose(struct my_array *m1);
void row_m(struct my_array m);
void col_m(struct my_array m);

int main()
{
    struct my_array m1, m2, sum, mul;
    create(&m1);
    create(&m2);
    row_m(m1);
    col_m(m1);
    addition(&sum, &m1, &m2);
    display(sum);
    multiply(&mul, &m1, &m2);
    display(mul);
    transpose(&m1);

    return 0;
}

void create(struct my_array * m)
{
    printf("Enter elements of 3x3 square matrix.\n");
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf(" %d",&m->a[i][j]);
        }
    }
}

void display(struct my_array m)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",m.a[i][j]);
        }
        printf("\n");
    }
}

void addition(struct my_array *sum, struct my_array *m1, struct my_array*m2)

{
  printf("Addition of the given matrix\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            sum->a[i][j] = m1->a[i][j] + m2->a[i][j] ; 
        }
    }
}

void multiply(struct my_array *mul, struct my_array*m1, struct my_array *m2)

{
  printf("Multiplication of the given matrix\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int b = 0;
            for(int k=0;k<3;k++)
            {
                b = b + (m1->a[i][k]) * (m2->a[k][j]);
            }
            mul->a[i][j] = b;
        }
    }
}

void row_m(struct my_array m)

{
  printf("row major representation\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",m.a[i][j]);
        }
    }
    printf("\n");
}

void col_m(struct my_array m)

{
  printf("column major representation \n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",m.a[j][i]);
        }
    }
    printf("\n");
}
void transpose(struct my_array *m1){
  printf("Transpose of the given matrix\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d  ",m1->a[j][i]);
        }
        printf("\n");
    }
}