#include <math.h>

#include "maths/E_vec2.h"

void
EVec2Init(EVec2 v, float x, float y)
{
	v[0] = x;
	v[1] = y;
}

void
EVec2Copy(EVec2 dest, EVec2 v)
{
	dest[0] = v[0];
	dest[1] = v[1];
}

void
EVec2Add(EVec2 a, EVec2 b)
{
	a[0] += b[0];
	a[1] += b[1];
}

void
EVec2AddTo(EVec2 dest, EVec2 a, EVec2 b)
{
	dest[0] = a[0] + b[0];
	dest[1] = a[1] + b[1];
}

void
EVec2Sub(EVec2 a, EVec2 b)
{
	a[0] -= b[0];
	a[1] -= b[1];
}

void
EVec2SubTo(EVec2 dest, EVec2 a, EVec2 b)
{
	dest[0] = a[0] - b[0];
	dest[1] = a[1] - b[1];
}

void
EVec2Scale(EVec2 v, float s)
{
	v[0] *= s;
	v[1] *= s;
}

void
EVec2ScaleTo(EVec2 dest, EVec2 v, float s)
{
	dest[0] = v[0] * s;
	dest[1] = v[1] * s;
}

void
EVec2Mul(EVec2 a, EVec2 b)
{
	a[0] *= b[0];
	a[1] *= b[1];
}

void
EVec2MulTo(EVec2 dest, EVec2 a, EVec2 b)
{
	dest[0] = a[0] * b[0];
	dest[1] = a[1] * b[1];
}

void
EVec2Div(EVec2 a, EVec2 b)
{
	a[0] /= b[0];
	a[1] /= b[1];
}

void
EVec2DivTo(EVec2 dest, EVec2 a, EVec2 b)
{
	dest[0] = a[0] / b[0];
	dest[1] = a[1] / b[1];
}

void
EVec2Negate(EVec2 v)
{
	v[0] = -v[0];
	v[1] = -v[1];
}

void
EVec2NegateTo(EVec2 dest, EVec2 v)
{
	dest[0] = -v[0];
	dest[1] = -v[1];
}

float
EVec2Abs(EVec2 v)
{
	return sqrt(powf(v[0], 2) + powf(v[1], 2));
}

void
EVec2Norm(EVec2 v)
{
	float m = EVec2Abs(v);

	v[0] /= m, v[1] /= m;
}

void
EVec2NormTo(EVec2 dest, EVec2 v)
{
	float m = EVec2Abs(v);

	dest[0] = v[0] / m, dest[1] = v[1] / m;
}

float
EVec2Dot(EVec2 a, EVec2 b)
{
	return (a[0] * b[0]) + (a[1] * b[1]);
}
