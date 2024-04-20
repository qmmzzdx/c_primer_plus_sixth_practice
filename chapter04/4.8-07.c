#include <stdio.h>
#include <float.h>

int main(void)
{
    float f_value = 1.0 / 3.0;
    double d_value = 1.0 / 3.0;

    printf("1.0 / 3.0 display 6 decimal places:\n");
    printf("f_value = %.6f\nd_value = %.6lf\n", f_value, d_value);

    printf("\n1.0 / 3.0 display 12 decimal places:\n");
    printf("f_value = %.12f\nd_value = %.12lf\n", f_value, d_value);

    printf("\n1.0 / 3.0 display 16 decimal places:\n");
    printf("f_value = %.16f\nd_value = %.16lf\n", f_value, d_value);

    printf("\nfloat and double maximum precious digits:\n");
    printf("FLT_DIG = %d, DBL_DIG = %d\n", FLT_DIG, DBL_DIG);
    //4.8-7书上问答: 不一致, 因为float精确度是6位, 而double是15位, 所以在超过精确度位数后会有差异 

    return 0;
}
