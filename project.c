#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.h"
//swtich case function
int main ()
{
    int a,b,count=1;
    start :
    printf("\t\t\t*****************************Welcome to The World of Matrix*****************************\n");
    printf("\t\t\t\tPlese Enter the Number of function that You wnat to do\n");
    printf("\t\t\t\t\t1.Add Matrix \n");
    printf("\t\t\t\t\t2.sub Matrix \n");
    printf("\t\t\t\t\t3.Multiplication of Matrix\n");
    printf("\t\t\t\t\t4.Determinant of Matrix\n");
    printf("\t\t\t\t\t5.transpose of Matrix\n");
    printf("\t\t\t\t\t6.Inverse of Matrix\n");
    printf("\t\t\t\t\t0.exit\n");

    scanf("%d",&a);
    switch (a)
    {
        case 1:
            printf("Plese Enter the Number of function that You wnat to do\n\n");
            printf("1.Add Matrix (without file)\n");
            printf("2.Add Matrix (with file)\n");
            printf("3.Add Matrix (One with file and one without (show))\n");
            printf("4.Add Matrix (One with file and one without (Save in file))\n");
            printf("0.Back to menu\n");
            scanf("%d",&b);
            switch (b)
            {
            case 1:
                add_1();
                break;
            case 2:
                add_2();
                break;
            case 3:
                add_3();
            break;
            case 4:
                add_4();
            break;
            default:
                goto start;
                break;
            }
            break;
        case 2:
            printf("Plese Enter the Number of function that You wnat to do\n");
            printf("1.Sub Matrix (without file)\n");
            printf("2.Sub Matrix (with file)\n");
            printf("3.Sub Matrix (One with file and one without (show))\n");
            printf("4.Sub Matrix (One with file and one without (Save in file))\n");
            printf("0.Back to menu\n");
            scanf("%d",&b);
            switch (b)
            {
            case 1:
                sub_1();
                break;
            case 2:
                sub_2();
                break;
            case 3:
                sub_3();
            break;
            case 4:
                sub_4();
            break;
            default:
                goto start;
                break;
            }
            break;
        case 3:
            printf("Plese Enter the Number of function that You wnat to do\n");
            printf("1.Multiplication of Matrix (without file)\n");
            printf("2.Multiplication of Matrix (with file)\n");
            printf("3.Multiplication of Matrix (One with file and one without (show))\n");
            printf("4.Multiplication of Matrix (One with file and one without (Save in file))\n");
            printf("0.Back to menu\n");
            scanf("%d",&b);
            switch (b)
            {
            case 1:
                mul_1();
                break;
            case 2:
                mul_2();
                break;
            case 3:
                mul_3();
            break;
            case 4:
                mul_4();
            break;
            default:
                goto start;
                break;
            }
            break;
        case 4:
            printf("Plese Enter the Number of function that You wnat to do\n");
            printf("1.Determinant of Matrix (without file)\n");
            printf("2.Determinant of Matrix (with file)\n");
            printf("0.Back to menu\n");
            scanf("%d",&b);
            switch (b)
            {
            case 1:
                det_1();
                break;
            case 2:
                det_2();
                break;
            default:
                goto start;
                break;
            }
            break;
        case 5:
            printf("Plese Enter the Number of function that You wnat to do\n");
            printf("1.transpose of Matrix (without file)\n");
            printf("2.transpose of Matrix (with file)\n");
            printf("0.Back to menu\n");
            scanf("%d",&b);
            switch (b)
            {
            case 1:
                Teraspose_1();
                break;
            case 2:
                Teraspose_2();
                break;
            default:
                goto start;
                break;
            }
            break;
        case 6:
            printf("Plese Enter the Number of function that You wnat to do\n");
            printf("1.Inverse of Matrix (without file)\n");
            printf("2.Inverse of Matrix (with file)\n");
            printf("0.Back to menu\n");
            scanf("%d",&b);
            switch (b)
            {
            case 1:
                inverse_1();
                break;
            case 2:
                inverse_2();
                break;
            default:
                goto start;
                break;
            }
            break;
        default:
            exit(0);
            break;
    }
    printf("\nDo You Wish to Stop\n");
    printf("1.continue\n");
    printf("0.Exit\n");
    scanf("%d",&b);
    switch (b)
    {
    case 1:
        goto start;
        break;
    default:
        exit(0);
        break;
    }
    return 0; 
}