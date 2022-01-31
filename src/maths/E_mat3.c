#include <stdio.h>
#include <math.h>

#include "E_common.h"
#include "maths/E_mat3.h"

void
EMat3Copy(EMat3 dest, EMat3 m)
{
	dest[0] = m[0];
	dest[1] = m[1];
	dest[2] = m[2];
	dest[3] = m[3];
	dest[4] = m[4];
	dest[5] = m[5];
	dest[6] = m[6];
	dest[7] = m[7];
	dest[8] = m[8];
}

void
EMat3Zero(EMat3 m)
{
	EMat3 temp = E_MAT3_ZERO;
	EMat3Copy(m, temp);
}

void
EMat3One(EMat3 m)
{
	EMat3 temp = E_MAT3_ONE;
	EMat3Copy(m, temp);
}

void
EMat3Identity(EMat3 m)
{
	EMat3 temp = E_MAT3_IDENTITY;
	EMat3Copy(m, temp);
}

void
EMat3Mul(EMat3 a, EMat3 b)
{
	EMat3 temp;
	EMat3Copy(temp, a);

	a[0] = (b[0] * temp[0]) + (b[1] * temp[3]) + (b[2] * temp[6]);
	a[1] = (b[0] * temp[1]) + (b[1] * temp[4]) + (b[2] * temp[7]);
	a[2] = (b[0] * temp[2]) + (b[1] * temp[5]) + (b[2] * temp[8]);
	a[3] = (b[3] * temp[0]) + (b[4] * temp[3]) + (b[5] * temp[6]);
	a[4] = (b[3] * temp[1]) + (b[4] * temp[4]) + (b[5] * temp[7]);
	a[5] = (b[3] * temp[2]) + (b[4] * temp[5]) + (b[5] * temp[8]);
	a[6] = (b[6] * temp[0]) + (b[7] * temp[3]) + (b[8] * temp[6]);
	a[7] = (b[6] * temp[1]) + (b[7] * temp[4]) + (b[8] * temp[7]);
	a[8] = (b[6] * temp[2]) + (b[7] * temp[5]) + (b[8] * temp[8]);
}

void
EMat3MulTo(EMat3 dest, EMat3 a, EMat3 b)
{
	dest[0] = (a[0] * b[0]) + (a[1] * b[3]) + (a[2] * b[6]);
	dest[1] = (a[0] * b[1]) + (a[1] * b[4]) + (a[2] * b[7]);
	dest[2] = (a[0] * b[2]) + (a[1] * b[5]) + (a[2] * b[8]);
	dest[3] = (a[3] * b[0]) + (a[4] * b[3]) + (a[5] * b[6]);
	dest[4] = (a[3] * b[1]) + (a[4] * b[4]) + (a[5] * b[7]);
	dest[5] = (a[3] * b[2]) + (a[4] * b[5]) + (a[5] * b[8]);
	dest[6] = (a[6] * b[0]) + (a[7] * b[3]) + (a[8] * b[6]);
	dest[7] = (a[6] * b[1]) + (a[7] * b[4]) + (a[8] * b[7]);
	dest[8] = (a[6] * b[2]) + (a[7] * b[5]) + (a[8] * b[8]);
}

void
EMat3Transpose(EMat3 m)
{
	float a = m[1], b = m[2], c = m[3], d = m[5], e = m[6], f = m[7];

	m[1] = c;
	m[2] = e;
	m[3] = a;
	m[5] = f;
	m[6] = b;
	m[7] = d;
}

void
EMat3TransposeTo(EMat3 dest, EMat3 m)
{
	dest[0] = m[0];
	dest[1] = m[3];
	dest[2] = m[6];
	dest[3] = m[1];
	dest[4] = m[4];
	dest[5] = m[7];
	dest[6] = m[2];
	dest[7] = m[5];
	dest[8] = m[8];
}

void
EMat3Scale(EMat3 m, float s)
{
	m[0] *= s;
	m[1] *= s;
	m[2] *= s;
	m[3] *= s;
	m[4] *= s;
	m[5] *= s;
	m[6] *= s;
	m[7] *= s;
	m[8] *= s;
}

void
EMat3ScaleTo(EMat3 dest, EMat3 m, float s)
{
	dest[0] = m[0] * s;
	dest[1] = m[1] * s;
	dest[2] = m[2] * s;
	dest[3] = m[3] * s;
	dest[4] = m[4] * s;
	dest[5] = m[5] * s;
	dest[6] = m[6] * s;
	dest[7] = m[7] * s;
	dest[8] = m[8] * s;
}

float
EMat3Det(EMat3 m)
{
	float a = m[0], b = m[1], c = m[2],
	      d = m[3], e = m[4], f = m[5],
		  g = m[6], h = m[7], i = m[8];

	return (a * (e * i - f * h)) - (b * (d * i - f * g)) + (c * (d * h - e * g));
}

void
EMat3Inverse(EMat3 m)
{
	float a = m[0], b = m[3], c = m[6],
	      d = m[1], e = m[4], f = m[7],
		  g = m[2], h = m[5], i = m[8];
	float det = EMat3Det(m);

	m[0] = (e * i - f * h) / det;
	m[1] = (f * g - d * i) / det;
	m[2] = (d * h - e * g) / det;
	m[3] = (c * h - b * i) / det;
	m[4] = (a * i - c * g) / det;
	m[5] = (b * g - a * h) / det;
	m[6] = (b * f - c * e) / det;
	m[7] = (c * d - a * f) / det;
	m[8] = (a * e - b * d) / det;
}

void
EMat3InverseTo(EMat3 dest, EMat3 m)
{
	EMat3Copy(dest, m);
	EMat3Inverse(dest);
}

int
EMat3IsRoughlyEqual(EMat3 a, EMat3 b)
{
	int i;
	for (i = 0; i < 9; i++) {
		if (fabs(a[i] - b[i]) > E_EQUALITY_EPSILON)
			return 0;
	}

	return 1;
}
