#include<stdio.h>
#include<math.h>

#define PI 3.1415926

int main()
{
	double b,c;
	scanf("%lf %lf",&b,&c);
	double a=atan(b/c);
	printf("%lf",a*180/PI);
	return 0;
}
