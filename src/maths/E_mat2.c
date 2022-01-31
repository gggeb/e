#include <stdio.h>
#include <math.h>

#include "E_common.h"
#include "maths/E_mat2.h"

void
EMat2Copy(EMat2 dest, EMat2 m)
{
	dest[0] = m[0];
	dest[1] = m[1];
	dest[2] = m[2];
	dest[3] = m[3];
}

void
EMat2Zero(EMat2 m)
{
	EMat2 temp = E_MAT2_ZERO;
	EMat2Copy(m, temp);
}

void
EMat2One(EMat2 m)
{
	EMat2 temp = E_MAT2_ONE;
	EMat2Copy(m, temp);
}

void
EMat2Identity(EMat2 m)
{
	EMat2 temp = E_MAT2_IDENTITY;
	EMat2Copy(m, temp);
}

void
EMat2Mul(EMat2 a, EMat2 b)
{
	EMat2 temp;
	EMat2Copy(temp, a);

	a[0] = (b[0] * temp[0]) + (b[1] * temp[2]);
	a[1] = (b[0] * temp[1]) + (b[1] * temp[3]);
	a[2] = (b[2] * temp[0]) + (b[3] * temp[2]);
	a[3] = (b[2] * temp[1]) + (b[3] * temp[3]);
}

void
EMat2MulTo(EMat2 dest, EMat2 a, EMat2 b)
{
	dest[0] = (a[0] * b[0]) + (a[1] * b[2]);
	dest[1] = (a[0] * b[1]) + (a[1] * b[3]);
	dest[2] = (a[2] * b[0]) + (a[3] * b[2]);
	dest[3] = (a[2] * b[1]) + (a[3] * b[3]);
}

void
EMat2Transpose(EMat2 m)
{
	float a = m[2], b = m[1];

	m[1] = a;
	m[2] = b;
}

void
EMat2TransposeTo(EMat2 dest, EMat2 m)
{
	dest[0] = m[0];
	dest[1] = m[2];
	dest[2] = m[1];
	dest[3] = m[3];
}

void
EMat2Scale(EMat2 m, float s)
{
	m[0] *= s;
	m[1] *= s;
	m[2] *= s;
	m[3] *= s;
}

void
EMat2ScaleTo(EMat2 dest, EMat2 m, float s)
{
	dest[0] = m[0] * s;
	dest[1] = m[1] * s;
	dest[2] = m[2] * s;
	dest[3] = m[3] * s;
}

float
EMat2Det(EMat2 m)
{
	return (m[0] * m[3]) - (m[1] * m[2]);
}

void
EMat2Inverse(EMat2 m)
{
	EMat2 temp;
	EMat2Copy(temp, m);

	m[0] = temp[3];
	m[1] = -temp[1];
	m[2] = -temp[2];
	m[3] = temp[0];

	EMat2Scale(m, 1.0f/EMat2Det(m));
}

void
EMat2InverseTo(EMat2 dest, EMat2 m)
{
	dest[0] = m[3];
	dest[1] = -m[1];
	dest[2] = -m[2];
	dest[3] = m[0];

	EMat2Scale(dest, 1.0f/EMat2Det(m));
}

int
EMat2IsRoughlyEqual(EMat2 a, EMat2 b)
{
	int i;
	for (i = 0; i < 4; i++) {
		if (fabs(a[i] - b[i]) > E_EQUALITY_EPSILON)
			return 0;
	}

	return 1;
}
