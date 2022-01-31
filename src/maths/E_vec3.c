#include <math.h>

#include "maths/E_vec3.h"

void
EVec3Init(EVec3 v, float x, float y, float z)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

void
EVec3Copy(EVec3 dest, EVec3 v)
{
	dest[0] = v[0];
	dest[1] = v[1];
	dest[2] = v[2];
}

void
EVec3Add(EVec3 a, EVec3 b)
{
	a[0] += b[0];
	a[1] += b[1];
	a[2] += b[2];
}

void
EVec3AddTo(EVec3 dest, EVec3 a, EVec3 b)
{
	dest[0] = a[0] + b[0];
	dest[1] = a[1] + b[1];
	dest[2] = a[2] + b[2];
}

void
EVec3Sub(EVec3 a, EVec3 b)
{
	a[0] -= b[0];
	a[1] -= b[1];
	a[2] -= b[2];
}

void
EVec3SubTo(EVec3 dest, EVec3 a, EVec3 b)
{
	dest[0] = a[0] - b[0];
	dest[1] = a[1] - b[1];
	dest[2] = a[2] - b[2];
}

void
EVec3Scale(EVec3 v, float s)
{
	v[0] *= s;
	v[1] *= s;
	v[2] *= s;
}

void
EVec3ScaleTo(EVec3 dest, EVec3 v, float s)
{
	dest[0] = v[0] * s;
	dest[1] = v[1] * s;
	dest[2] = v[2] * s;
}

void
EVec3Mul(EVec3 a, EVec3 b)
{
	a[0] *= b[0];
	a[1] *= b[1];
	a[2] *= b[2];
}

void
EVec3MulTo(EVec3 dest, EVec3 a, EVec3 b)
{
	dest[0] = a[0] * b[0];
	dest[1] = a[1] * b[1];
	dest[2] = a[2] * b[2];
}

void
EVec3Div(EVec3 a, EVec3 b)
{
	a[0] /= b[0];
	a[1] /= b[1];
	a[2] /= b[2];
}

void
EVec3DivTo(EVec3 dest, EVec3 a, EVec3 b)
{
	dest[0] = a[0] / b[0];
	dest[1] = a[1] / b[1];
	dest[2] = a[2] / b[2];
}

void
EVec3Negate(EVec3 v)
{
	v[0] = -v[0];
	v[1] = -v[1];
	v[2] = -v[2];
}

void
EVec3NegateTo(EVec3 dest, EVec3 v)
{
	dest[0] = -v[0];
	dest[1] = -v[1];
	dest[2] = -v[2];
}

float
EVec3Abs(EVec3 v)
{
	return sqrt(powf(v[0], 2) + powf(v[1], 2) + powf(v[2], 2));
}

void
EVec3Norm(EVec3 v)
{
	float m = EVec3Abs(v);

	v[0] /= m;
	v[1] /= m;
	v[2] /= m;
}

void
EVec3NormTo(EVec3 dest, EVec3 v)
{
	float m = EVec3Abs(v);

	dest[0] = v[0] / m;
	dest[1] = v[1] / m;
	dest[2] = v[2] / m;
}

float
EVec3Dot(EVec3 a, EVec3 b)
{
	return (a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]);
}

void
EVec3Cross(EVec3 dest, EVec3 a, EVec3 b)
{
	dest[0] = (a[1] * b[2]) - (a[2] * b[1]);
	dest[1] = (a[2] * b[0]) - (a[0] * b[2]);
	dest[2] = (a[0] * b[1]) - (a[1] * b[0]);
}
