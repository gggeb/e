#include <stdio.h>

#include "maths/E_utils.h"

float
EDeg2Rad(float deg)
{
	return deg * (E_PIf / 180.0f);
}

float
ERad2Deg(float rad)
{
	return rad * (180.0f / E_PIf);
}

void
EMat2Print(EMat2 m)
{
	printf("[ %f\t%f\n  %f\t%f ]\n", m[0], m[1], m[2], m[3]);
}

void
EMat3Print(EMat3 m)
{
	printf("[ %f\t%f\t%f\n  %f\t%f\t%f\n  %f\t%f\t%f ]\n",
		m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8]);
}

void
EMat4Print(EMat4 m)
{
	printf("[ %f\t%f\t%f\t%f\n  %f\t%f\t%f\t%f\n  %f\t%f\t%f\t%f\n  %f\t%f\t%f\t%f ]\n",
		m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8], m[9], m[10], m[11], m[12], m[13], m[14], m[15]);
}
