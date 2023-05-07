#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 20

struct Matrix 
{
    int m,n; 
    float array[MAX_SIZE][MAX_SIZE];
};

//---------------------------------------------------
void PrintMatrixFile2(float array[20][20],int n)
{
    FILE *stream=fopen("project","a");
    fprintf(stream,"\n");
    fprintf(stream,"The number of rows and columns is  : %d\n", n);
    int i,j;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
            fprintf(stream,"%f ",array[i][j]);
        fprintf(stream,"\n");
    }
    fclose(stream);

}
void printMatrix1(float array[20][20],int n)
{
    printf("The number of rows and columns is  : %d\n", n);
    int i,j;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
            printf("%f ",array[i][j]);
        printf("\n");
    }
    printf("\n");
}
void printMatrix(struct Matrix a)
{
    int i,j;
    for ( i = 0; i < a.n; i++)
    {
        for ( j = 0; j < a.m; j++)
        {
            printf("%f  ",a.array[i][j]);
        }
        printf("\n");
    } 
    printf("\n");
}

//for reading to two file 
void readMatrixFile2(struct Matrix *a,struct Matrix *b)
{
    int i,j;
    printf("Please Enter the number of rows and columns of the first matrix\n");
    printf("Please Enter rows:");
    scanf("%d",&a->n);
    printf("Please Enter columns:");
    scanf("%d",&a->m);
    FILE *stream=fopen("projrct","r");
    for ( i = 0; i < a->n; i++)
    {
        for ( j = 0; j < a->m; j++)
        {
            fscanf(stream,"%f ",&a->array[i][j]);
        }
    }
    printf("Your Matrix is : \n");
    printMatrix(*a);
    printf("Please Enter the number of rows and columns of the Second matrix\n");
    printf("Please Enter rows:");
    scanf("%d",&b->n);
    printf("Please Enter columns:");
    scanf("%d",&b->m);

    for ( i = 0; i < b->n; i++)
    {
        for ( j = 0; j < b->m; j++)
        {
            fscanf(stream,"%f ",&b->array[i][j]);
        }
    }
    
    printf("Your Matrix is : \n");
        printMatrix(*b);
    fclose(stream);
}
void readMatrixFile(struct Matrix *a)
{
    int i,j;
    printf("Please Enter the number of rows and columns\n");
    printf("Please Enter rows:");
    scanf("%d",&a->n);
    printf("Please Enter columns:");
    scanf("%d",&a->m);
    FILE *stream=fopen("erfan.txt","r");
    for ( i = 0; i < a->n; i++)
    {
        for ( j = 0; j < a->m; j++)
        {
            fscanf(stream,"%f ",&a->array[i][j]);
        }
    }
    fclose(stream);
}
void PrintMatrixFile(struct Matrix a)
{
    int i,j;
    FILE *stream=fopen("project","a");
    fprintf(stream,"\n");
    for ( i = 0; i < a.n; i++)
    {
        for ( j = 0; j < a.m; j++)
        {
            fprintf(stream,"%f ",a.array[i][j]);
        }
        fprintf(stream,"\n");
    }
    fclose(stream);
}
void readMatrix1(struct Matrix *a)
{
    int i,j;
    printf("Please Enter the number of rows and columns \n");
    printf("Please Enter rows:");
    scanf("%d",&a->n);
    printf("Please Enter columns:");
    scanf("%d",&a->m);
    printf("Please Enter the matrix:\n");
    for(i=0;i<a->n;i++)
        for(j=0;j<a->m;j++)
        {
            printf("Please Enter %d's row and %d's column values: ",i+1,j+1);
            scanf("%f",&a->array[i][j]);
        }
}

struct Matrix readMatrix()
{
    struct Matrix a;
    int i,j;
    printf("Please Enter the number of rows and columns\n");
    printf("Please Enter rows:");
    scanf("%d",&a.n);
    printf("Please Enter columns:");
    scanf("%d",&a.m);
    printf("Please Enter the matrix:\n");
    for ( i = 0; i < a.n; i++)
        for ( j = 0; j < a.m; j++)
        {
            printf("Please Enter %d's row and %d's column values : ",i+1,j+1);
            scanf("%f",&a.array[i][j]);
        }
    return a;
}

void PrintStruct(struct Matrix a)
{
    printf("rows: %d ,columns: %d\n",a.n,a.m);
    int i,j;
    for ( i = 0; i < a.n; i++)
    {
        for ( j = 0; j < a.m; j++)
        {
            printf("%4f ",a.array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int addMatrix(struct Matrix *a,struct Matrix *b,struct Matrix *c)
{
    int i,j;
    if (a->n==b->n)
    {
        c->n=a->n;
        if (a->m==b->m)
        {
            c->m=a->m;
            for ( i = 0; i < c->n; i++)
                for ( j = 0; j < c->m; j++)
                    c->array[i][j]=a->array[i][j]+b->array[i][j];

            return 1;
        }
        else 
            return 0;
    }
    else
        return 0;
}
int subMatrix(struct Matrix *a,struct Matrix *b,struct Matrix *c)
{
    int i,j;
    if (a->n==b->n)
    {
        c->n=a->n;
        if (a->m==b->m)
        {
            c->m=a->m;
            for ( i = 0; i < c->n; i++)
                for ( j = 0; j < c->m; j++)
                    c->array[i][j]=a->array[i][j]-b->array[i][j];
            return 1;
        }
        else 
            return 0;
    }
    else
        return 0;
}

int mulMatrix(struct Matrix *a,struct Matrix *b,struct Matrix *c)
{
    int i,j,k,m,n;
    if (a->m==b->n)
    {
        c->n=a->n;
        c->m=b->m;
        for ( i = 0; i < c->n; i++)
        {
            for ( j = 0; j < c->m ; j++)
            {
                c->array[i][j]=0;
                for (k = 0; k < c->n+1; k++)
                {
                   c->array[i][j]=c->array[i][j]+a->array[i][k]*b->array[k][j];
                }
            }
        }   
        return 1;
    }
    else
        return 0;
}

void build(float b[MAX_SIZE][MAX_SIZE], float a[MAX_SIZE][MAX_SIZE], int l, int n)
{
    int j, i;
    int h = 0, k = 0;
    for (i = 1; i < n; i++)
        for (j = 0; j < n; j++)
        {
            //removing the unneeded cloumns 
            if (j == l)
                continue;
            //bulding a new matrix
            b[h][k]=a[i][j];
            k++;
            if (k==n-1)
            {
                h++;
                k=0;
            }
        }
}
float det(float a[MAX_SIZE][MAX_SIZE], int n)
{

    int i;
    float sum = 0;
    float b[MAX_SIZE][MAX_SIZE];
    
    if (n==1)
    {
        sum+=a[0][0];
        return sum;
    }
    if (n == 2)
    {
        sum = a[0][0]*a[1][1]-a[0][1]*a[1][0];
        return sum;
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            //building a new matrix for calculating the determinant
            build(b,a,i,n);
            sum += a[0][i]*pow(-1,i)*det(b,(n-1));
        }
    }
    return sum;
}

float determinant(struct Matrix *a,int *count)
{
    if (a->m==a->n)
    {
        *count=1;
        return det(a->array,a->m);
    }
}

struct Matrix transpose(struct Matrix a)
{
    int i,j;
    struct Matrix b;
    for ( i = 0; i < a.n; i++)
    {
        for ( j = 0; j < a.m; j++)
            b.array[j][i]=a.array[i][j];
    }
    b.n=a.m;
    b.m=a.n;
    return b;
}

void Inverse(float num[20][20], float fac[20][20],float  inverse[20][20],int n)
{
    //finding the transpose
    int i, j;
    float  b[20][20], d;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            b[i][j] = fac[j][i];
        }
    }
    //finding the inverse of matrix
    d = det(num, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            inverse[i][j] = b[i][j] / d;
        }
    }
}

void cofactor(float num[20][20],float inverse[20][20],int f)
{
    //calculating the kahad
    float b[20][20], fac[20][20];
    int p, q, m, n, i, j;
    for (q = 0; q < f; q++)
    {
        for (p = 0; p < f; p++)
        {
            m = 0;
            n = 0;
            for (i = 0; i < f; i++)
            {
                for (j = 0; j < f; j++)
                {
                    if (i != q && j != p)
                    {
                        b[m][n] = num[i][j];
                        if (n < (f - 2))
                            n++;
                        else
                        {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            fac[q][p] = pow(-1, q + p) * det(b, f - 1);
        }
    }
    Inverse(num, fac,inverse,f);
}

void add_1()
{
    int m;
    struct Matrix a,b,c;
    printf("Please Enter The first Matrix\n");
    a=readMatrix();
    printf("Your Matrix is : \n");
    printMatrix(a);
    printf("Please Enter The Second Matrix\n");
    b=readMatrix();
    printf("Your Matrix is : \n");
    printMatrix(b);
    m=addMatrix(&a,&b,&c);
    if (m==1)
    {
        printf("Add Matrix is :\n");
        PrintStruct(c);
    }
    else
    {
        printf("Add Matrix is :\n");
        printf("Uncountable\n");
    }
}

void add_2()
{
    int m;
    struct Matrix a,b,c;
    readMatrixFile2(&a,&b);
    m=addMatrix(&a,&b,&c);
    printf("Your Matrix has been saved\n");
    if (m==1)
    {
        FILE *stream=fopen("project","a");
        PrintMatrixFile(c);
        fputs("Add Matrix is :\n",stream);
        fprintf(stream,"\n");
        fclose(stream);
    }
    else
    {
        FILE *stream=fopen("project","a");
        fprintf(stream,"Add Matrix is :\n");
        fprintf(stream,"Uncountable\n");
        fclose(stream);
    }
}

void add_3()
{
    int m;
    struct Matrix a,b,c;
    printf("Please Enter The first Matrix\n");
    a=readMatrix();
    printf("Your Matrix is : \n");
    printMatrix(a);
    readMatrixFile(&b);
    printf("Your Matrix is : \n");
    printMatrix(b);
    m=addMatrix(&a,&b,&c);
    if (m==1)
    {
        printf("Add Matrix is :\n");
        PrintStruct(c);
    }
    else
    {
        printf("Add Matrix is :\n");
        printf("Uncountable\n");
    }
}

void add_4()
{
    int m;
    struct Matrix a,b,c;
    printf("Please Enter The first Matrix\n");
    a=readMatrix();
    printf("Your Matrix is : \n");
    printMatrix(a);
    readMatrixFile(&b);
    printf("Your Matrix is : \n");
    printMatrix(b);
    m=addMatrix(&a,&b,&c);
    printf("Your Matrix has been saved\n");
    if (m==1)
    {
        FILE *stream=fopen("project","a");
        PrintMatrixFile(c);
        fputs("Add Matrix is :\n",stream);
        fprintf(stream,"\n");
        fclose(stream);
    }
    else
    {
        FILE *stream=fopen("project","a");
        fprintf(stream,"Add Matrix is :\n");
        fprintf(stream,"Uncountable\n");
        fclose(stream);
    }
}

void sub_1()
{
    int m;
    struct Matrix a,b,c;
    printf("Please Enter The first Matrix\n");
    a=readMatrix();
    printf("Your Matrix is : \n");
    printMatrix(a);
    printf("Please Enter The Second Matrix\n");
    b=readMatrix();
    printf("Your Matrix is : \n");
    printMatrix(b);
    m=subMatrix(&a,&b,&c);
    if (m==1)
    {
        printf("Sub Matrix is :\n");
        PrintStruct(c);
    }
    else
    {
        printf("Sub Matrix is :\n");
        printf("Uncountable\n");
    }
}

void sub_2()
{
    int m;
    struct Matrix a,b,c;
    readMatrixFile2(&a,&b);
    m=subMatrix(&a,&b,&c);
    printf("Your Matrix has been saved\n");
    if (m==1)
    {
        FILE *stream=fopen("project","a");
        PrintMatrixFile(c);
        fprintf(stream,"Sub Matrix is :\n");
        fclose(stream);
    }
    else
    {
        FILE *stream=fopen("project","a");
        fprintf(stream,"Sub Matrix is : \n");
        fprintf(stream,"Uncountable\n");
        fclose(stream);
    }
}

void sub_3()
{
    int m;
    struct Matrix a,b,c;
    printf("Please Enter The first Matrix\n");
    a=readMatrix();
    printf("Your Matrix is : \n");
    printMatrix(a);
    readMatrixFile(&b);
    printf("Your Matrix is : \n");
    printMatrix(b);
    m=subMatrix(&a,&b,&c);
    if (m==1)
    {
        printf("Sub Matrix is :\n");
        PrintStruct(c);
    }
    else
    {
        printf("Sub Matrix is :\n");
        printf("Uncountable\n");
    }
}

void sub_4()
{
    int m;
    struct Matrix a,b,c;
    printf("Please Enter The first Matrix\n");
    a=readMatrix();
    printf("Your Matrix is : \n");
    printMatrix(a);
    readMatrixFile(&b);
    printf("Your Matrix is : \n");
    printMatrix(b);
    m=subMatrix(&a,&b,&c);
    printf("Your Matrix has been saved\n");
    if (m==1)
    {
        FILE *stream=fopen("project","a");
        PrintMatrixFile(c);
        fprintf(stream,"Sub Matrix is :\n");
        fclose(stream);
    }
    else
    {
        FILE *stream=fopen("project","a");
        fprintf(stream,"Sub Matrix is : \n");
        fprintf(stream,"Uncountable\n");
        fclose(stream);
    }
}

void mul_1()
{
    int m;
    struct Matrix a,b,c;
    printf("Please Enter The first Matrix\n");
    a=readMatrix();
    printf("Your Matrix is : \n");
    printMatrix(a);
    printf("Please Enter The Second Matrix\n");
    b=readMatrix();
    printf("Your Matrix is : \n");
    printMatrix(b);
    m=mulMatrix(&a,&b,&c);
    if (m==1)
    {
        printf("Multiplication Matrix is :\n");
        PrintStruct(c);
    }
    else
    {
        printf("Multiplication Matrix is :\n");
        printf("Uncountable\n");
    }
}
void mul_2()
{
    int m;
    struct Matrix a,b,c;
    readMatrixFile2(&a,&b);
    m=mulMatrix(&a,&b,&c);
    if (m==1)
    {
        FILE *stream=fopen("project","a");
        printf("Your Matrix has been saved\n");
        fprintf(stream,"Multiplication Matrix is :\n");
        PrintMatrixFile(c);
        fclose(stream);
    }
    else
    {
        printf("Your Multiplication Matrix has been saved\n");
        FILE *stream=fopen("project","a");
        fprintf(stream,"Multiplication Matrix is :\n");
        fprintf(stream,"Uncountable\n");
        fclose(stream);
    }
}

void mul_3()
{
    int m;
    struct Matrix a,b,c;
    printf("Please Enter The first Matrix\n");
    a=readMatrix();
    printf("Your Matrix is : \n");
    printMatrix(a);
    readMatrixFile(&b);
    printf("Your Matrix is : \n");
    printMatrix(b);
    m=mulMatrix(&a,&b,&c);
    if (m==1)
    {
        printf("Multiplication Matrix is :\n");
        PrintStruct(c);
    }
    else
    {
        printf("Multiplication Matrix is :\n");
        printf("Uncountable\n");
    }
}

void mul_4()
{
    int m;
    struct Matrix a,b,c;
    printf("Please Enter The first Matrix\n");
    a=readMatrix();
    printf("Your Matrix is : \n");
    printMatrix(a);
    readMatrixFile(&b);
    printf("Your Matrix is : \n");
    printMatrix(b);
    m=mulMatrix(&a,&b,&c);
    if (m==1)
    {
        FILE *stream=fopen("project","a");
        printf("Your Matrix has been saved\n");
        fprintf(stream,"Multiplication Matrix is :\n");
        PrintMatrixFile(c);
        fclose(stream);
    }
    else
    {
        printf("Your Multiplication Matrix has been saved\n");
        FILE *stream=fopen("project","a");
        fprintf(stream,"Multiplication Matrix is :\n");
        fprintf(stream,"Uncountable\n");
        fclose(stream);
    }
}

void det_1()
{
    printf("Please Enter One Matrix\n");
    int count=0;
    struct Matrix a,b;
    a=readMatrix();
    printf("Your Matrix is : \n");
    printMatrix(a);
    float d=determinant(&a,&count);
    if (count==1)
    {
        printf("Determinant is :\n");
        printf("%f",d);
    }
    else
    {
        printf("Determinant is :\n");
        printf("Uncountable\n");
    }
}
void det_2()
{
    int m;
    int count=0;
    struct Matrix a,b,c;
    readMatrixFile(&a);
    printf("Your Matrix is : \n");
    printMatrix(a);
    float d=determinant(&a,&count);
    if (count==1)
    {
        FILE *stream=fopen("project","a");
        fprintf(stream,"Determinant is :\n");
        fprintf(stream,"%f",d);
        fclose(stream);
    }
    else
    {
        printf("Dterminant has been saved\n");
        FILE *stream=fopen("project","a");
        fprintf(stream,"Determinant is :\n");
        fprintf(stream,"Uncountable\n");
        fclose(stream);
    }
}
void Teraspose_1()
{
    printf("Please Enter One Matrix\n");
    struct Matrix a,b;
    a=readMatrix();
    printf("Your Matrix is : \n");
    printMatrix(a);
    b=transpose(a);
    printf("Teraspose of Matrix is :\n");
    PrintStruct(b);
}

void Teraspose_2()
{
    int m;
    int count=0;
    struct Matrix a,b,c;
    readMatrixFile(&a);
    printf("Your Matrix is : \n");
    printMatrix(a);
    b=transpose(a);
    printf("Teraspose of Matrix has been saved \n");
    FILE *stream=fopen("project","a");
    fprintf(stream,"Teraspose of Matrix is :\n");
    PrintMatrixFile(b);  fclose(stream);
}
void inverse_1()
{
    struct Matrix a;
    float inverse[20][20];
    readMatrix1(&a);
    printf("Your matrix is :\n");
    printMatrix(a);
    float d;
    if (a.n==a.m)
    {
        d=det(a.array,a.m);
        if (d==0)
            printf("\nInverse Is Uncountable\n");
        else
        {
            cofactor(a.array,inverse,a.m);
            printMatrix1(inverse,a.n);
        }    
    }
    else
        puts("\nInverse Matrix is Uncountable\n");
}

void inverse_2()
{
    struct Matrix a;
    float inverse[20][20];
    readMatrixFile(&a);
    float d;
    FILE *stream=fopen("project","a");
    printf("Your matrix is :\n");
    printMatrix(a);
    printf("Inverse Matrix has been saved \n");
    if (a.n==a.m)
    {
        d=det(a.array,a.m);
        if (d==0)
        {
            fprintf(stream,"inverse matrix is : \n");
            fprintf(stream,"Uncountable\n");
        }
        else
        {
            fprintf(stream,"inverse matrix is : \n");
            cofactor(a.array,inverse,a.m);
            PrintMatrixFile2(inverse,a.n);
        }
    }
    else
    {
        fprintf(stream,"inverse matrix is : \n");
        fputs("Uncountable\n",stream);
    }
    fclose(stream);
}