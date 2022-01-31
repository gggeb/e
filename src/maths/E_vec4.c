#include <math.h>

#include "maths/E_vec4.h"

void
EVec4Init(EVec4 v, float x, float y, float z, float w)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
	v[3] = w;
}

void
EVec4Copy(EVec4 dest, EVec4 v)
{
	dest[0] = v[0];
	dest[1] = v[1];
	dest[2] = v[2];
	dest[3] = v[3];
}

void
EVec4Add(EVec4 a, EVec4 b)
{
	a[0] += b[0];
	a[1] += b[1];
	a[2] += b[2];
	a[3] += b[3];
}

void
EVec4AddTo(EVec4 dest, EVec4 a, EVec4 b)
{
	dest[0] = a[0] + b[0];
	dest[1] = a[1] + b[1];
	dest[2] = a[2] + b[2];
	dest[3] = a[3] + b[3];
}

void
EVec4Sub(EVec4 a, EVec4 b)
{
	a[0] -= b[0];
	a[1] -= b[1];
	a[2] -= b[2];
	a[3] -= b[3];
}

void
EVec4SubTo(EVec4 dest, EVec4 a, EVec4 b)
{
	dest[0] = a[0] - b[0];
	dest[1] = a[1] - b[1];
	dest[2] = a[2] - b[2];
	dest[3] = a[3] - b[3];
}

void
EVec4Scale(EVec4 v, float s)
{
	v[0] *= s;
	v[1] *= s;
	v[2] *= s;
	v[3] *= s;
}

void
EVec4ScaleTo(EVec4 dest, EVec4 v, float s)
{
	dest[0] = v[0] * s;
	dest[1] = v[1] * s;
	dest[2] = v[2] * s;
	dest[3] = v[3] * s;
}

void
EVec4Mul(EVec4 a, EVec4 b)
{
	a[0] *= b[0];
	a[1] *= b[1];
	a[2] *= b[2];
	a[3] *= b[3];
}

void
EVec4MulTo(EVec4 dest, EVec4 a, EVec4 b)
{
	dest[0] = a[0] * b[0];
	dest[1] = a[1] * b[1];
	dest[2] = a[2] * b[2];
	dest[3] = a[3] * b[3];
}

void
EVec4Div(EVec4 a, EVec4 b)
{
	a[0] /= b[0];
	a[1] /= b[1];
	a[2] /= b[2];
	a[3] *= b[3];
}

void
EVec4DivTo(EVec4 dest, EVec4 a, EVec4 b)
{
	dest[0] = a[0] / b[0];
	dest[1] = a[1] / b[1];
	dest[2] = a[2] / b[2];
	dest[3] = a[3] / b[3];
}

void
EVec4Negate(EVec4 v)
{
	v[0] = -v[0];
	v[1] = -v[1];
	v[2] = -v[2];
	v[3] = -v[3];
}

void
EVec4NegateTo(EVec4 dest, EVec4 v)
{
	dest[0] = -v[0];
	dest[1] = -v[1];
	dest[2] = -v[2];
	dest[3] = -v[3];
}

float
EVec4Abs(EVec4 v)
{
	return sqrt(powf(v[0], 2) + powf(v[1], 2) + powf(v[2], 2) + powf(v[3], 2));
}

void
EVec4Norm(EVec4 v)
{
	float m = EVec4Abs(v);

	v[0] /= m;
	v[1] /= m;
	v[2] /= m;
	v[3] /= m;
}

void
EVec4NormTo(EVec4 dest, EVec4 v)
{
	float m = EVec4Abs(v);

	dest[0] = v[0] / m;
	dest[1] = v[1] / m;
	dest[2] = v[2] / m;
	dest[3] = v[3] / m;
}

float
EVec4Dot(EVec4 a, EVec4 b)
{
	return (a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]) + (a[3] * b[3]);
}
