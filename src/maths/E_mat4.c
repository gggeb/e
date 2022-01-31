#include <stdio.h>
#include <math.h>

#include "E_common.h"
#include "maths/E_mat3.h"
#include "maths/E_mat4.h"

void
EMat4Copy(EMat4 dest, EMat4 m)
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
	dest[9] = m[9];
	dest[10] = m[10];
	dest[11] = m[11];
	dest[12] = m[12];
	dest[13] = m[13];
	dest[14] = m[14];
	dest[15] = m[15];
}

void
EMat4Zero(EMat4 m)
{
	EMat4 temp = E_MAT4_ZERO;
	EMat4Copy(m, temp);
}

void
EMat4One(EMat4 m)
{
	EMat4 temp = E_MAT4_ONE;
	EMat4Copy(m, temp);
}

void
EMat4Identity(EMat4 m)
{
	EMat4 temp = E_MAT4_IDENTITY;
	EMat4Copy(m, temp);
}

void
EMat4Mul(EMat4 a, EMat4 b)
{
	EMat4 temp;
	EMat4Copy(temp, a);

	a[0]  = (b[0] * temp[0]) + (b[1] * temp[4]) + (b[2] * temp[8]) + (b[3] * temp[12]);
	a[1]  = (b[0] * temp[1]) + (b[1] * temp[5]) + (b[2] * temp[9]) + (b[3] * temp[13]);
	a[2]  = (b[0] * temp[2]) + (b[1] * temp[6]) + (b[2] * temp[10]) + (b[3] * temp[14]);
	a[3]  = (b[0] * temp[3]) + (b[1] * temp[7]) + (b[2] * temp[11]) + (b[3] * temp[15]);
	a[4]  = (b[4] * temp[0]) + (b[5] * temp[4]) + (b[6] * temp[8]) + (b[7] * temp[12]);
	a[5]  = (b[4] * temp[1]) + (b[5] * temp[5]) + (b[6] * temp[9]) + (b[7] * temp[13]);
	a[6]  = (b[4] * temp[2]) + (b[5] * temp[6]) + (b[6] * temp[10]) + (b[7] * temp[14]);
	a[7]  = (b[4] * temp[3]) + (b[5] * temp[7]) + (b[6] * temp[11]) + (b[7] * temp[15]);
	a[8]  = (b[8] * temp[0]) + (b[9] * temp[4]) + (b[10] * temp[8]) + (b[11] * temp[12]);
	a[9]  = (b[8] * temp[1]) + (b[9] * temp[5]) + (b[10] * temp[9]) + (b[11] * temp[13]);
	a[10] = (b[8] * temp[2]) + (b[9] * temp[6]) + (b[10] * temp[10]) + (b[11] * temp[14]);
	a[11] = (b[8] * temp[3]) + (b[9] * temp[7]) + (b[10] * temp[11]) + (b[11] * temp[15]);
	a[12] = (b[12] * temp[0]) + (b[13] * temp[4]) + (b[14] * temp[8]) + (b[15] * temp[12]);
	a[13] = (b[12] * temp[1]) + (b[13] * temp[5]) + (b[14] * temp[9]) + (b[15] * temp[13]);
	a[14] = (b[12] * temp[2]) + (b[13] * temp[6]) + (b[14] * temp[10]) + (b[15] * temp[14]);
	a[15] = (b[12] * temp[3]) + (b[13] * temp[7]) + (b[14] * temp[11]) + (b[15] * temp[15]);
}

void
EMat4MulTo(EMat4 dest, EMat4 a, EMat4 b)
{
	dest[0]  = (a[0] * b[0]) + (a[1] * b[4]) + (a[2] * b[8]) + (a[3] * b[12]);
	dest[1]  = (a[0] * b[1]) + (a[1] * b[5]) + (a[2] * b[9]) + (a[3] * b[13]);
	dest[2]  = (a[0] * b[2]) + (a[1] * b[6]) + (a[2] * b[10]) + (a[3] * b[14]);
	dest[3]  = (a[0] * b[3]) + (a[1] * b[7]) + (a[2] * b[11]) + (a[3] * b[15]);
	dest[4]  = (a[4] * b[0]) + (a[5] * b[4]) + (a[6] * b[8]) + (a[7] * b[12]);
	dest[5]  = (a[4] * b[1]) + (a[5] * b[5]) + (a[6] * b[9]) + (a[7] * b[13]);
	dest[6]  = (a[4] * b[2]) + (a[5] * b[6]) + (a[6] * b[10]) + (a[7] * b[14]);
	dest[7]  = (a[4] * b[3]) + (a[5] * b[7]) + (a[6] * b[11]) + (a[7] * b[15]);
	dest[8]  = (a[8] * b[0]) + (a[9] * b[4]) + (a[10] * b[8]) + (a[11] * b[12]);
	dest[9]  = (a[8] * b[1]) + (a[9] * b[5]) + (a[10] * b[9]) + (a[11] * b[13]);
	dest[10] = (a[8] * b[2]) + (a[9] * b[6]) + (a[10] * b[10]) + (a[11] * b[14]);
	dest[11] = (a[8] * b[3]) + (a[9] * b[7]) + (a[10] * b[11]) + (a[11] * b[15]);
	dest[12] = (a[12] * b[0]) + (a[13] * b[4]) + (a[14] * b[8]) + (a[15] * b[12]);
	dest[13] = (a[12] * b[1]) + (a[13] * b[5]) + (a[14] * b[9]) + (a[15] * b[13]);
	dest[14] = (a[12] * b[2]) + (a[13] * b[6]) + (a[14] * b[10]) + (a[15] * b[14]);
	dest[15] = (a[12] * b[3]) + (a[13] * b[7]) + (a[14] * b[11]) + (a[15] * b[15]);
}

void
EMat4Transpose(EMat4 m)
{
	float a = m[1],  b = m[2],  c = m[3],
	      d = m[4],  e = m[6],  f = m[7],
		  g = m[8],  h = m[9],  i = m[11],
		  j = m[12], k = m[13], l = m[14];
	
	m[1]  = d;
	m[2]  = g; 
	m[3]  = j;
	m[4]  = a;
	m[6]  = h;
	m[7]  = k;
	m[8]  = b;
	m[9]  = e;
	m[11] = l;
	m[12] = c;
	m[13] = f;
	m[14] = i;
}

void
EMat4TransposeTo(EMat4 dest, EMat4 m)
{
	dest[0]  = m[0];
	dest[1]  = m[4];
	dest[2]  = m[8];
	dest[3]  = m[12];
	dest[4]  = m[1];
	dest[5]  = m[5];
	dest[6]  = m[9];
	dest[7]  = m[13];
	dest[8]  = m[2];
	dest[9]  = m[6];
	dest[10] = m[10];
	dest[11] = m[14];
	dest[12] = m[3];
	dest[13] = m[7];
	dest[14] = m[11];
	dest[15] = m[15];
}

void
EMat4Scale(EMat4 m, float s)
{
	m[0]  *= s;
	m[1]  *= s;
	m[2]  *= s;
	m[3]  *= s;
	m[4]  *= s;
	m[5]  *= s;
	m[6]  *= s;
	m[7]  *= s;
	m[8]  *= s;
	m[9]  *= s;
	m[10] *= s;
	m[11] *= s;
	m[12] *= s;
	m[13] *= s;
	m[14] *= s;
	m[15] *= s;
}

void
EMat4ScaleTo(EMat4 dest, EMat4 m, float s)
{
	dest[0]  = m[0] * s;
	dest[1]  = m[1] * s;
	dest[2]  = m[2] * s;
	dest[3]  = m[3] * s;
	dest[4]  = m[4] * s;
	dest[5]  = m[5] * s;
	dest[6]  = m[6] * s;
	dest[7]  = m[7] * s;
	dest[8]  = m[8] * s;
	dest[9]  = m[9] * s;
	dest[10] = m[10] * s;
	dest[11] = m[11] * s;
	dest[12] = m[12] * s;
	dest[13] = m[13] * s;
	dest[14] = m[14] * s;
	dest[15] = m[15] * s;
}

float
EMat4Det(EMat4 mat)
{
	float a = mat[0],  b = mat[1],  c = mat[2],  d = mat[3],
	      e = mat[4],  f = mat[5],  g = mat[6],  h = mat[7],
		  i = mat[8],  j = mat[9],  k = mat[10], l = mat[11],
		  m = mat[12], n = mat[13], o = mat[14], p = mat[15];
	
	return (a * EMat3Det((EMat3){ f, g, h, j, k, l, n, o, p })) -
	       (b * EMat3Det((EMat3){ e, g, h, i, k, l, m, o, p })) +
	       (c * EMat3Det((EMat3){ e, f, h, i, j, l, m, n, p })) -
	       (d * EMat3Det((EMat3){ e, f, g, i, j, k, m, n, o }));
}

void
EMat4Inverse(EMat4 mat)
{
	float a = mat[0],  b = mat[1],  c = mat[2],  d = mat[3],
	      e = mat[4],  f = mat[5],  g = mat[6],  h = mat[7],
		  i = mat[8],  j = mat[9],  k = mat[10], l = mat[11],
		  m = mat[12], n = mat[13], o = mat[14], p = mat[15];
	float det = EMat4Det(mat);
	
	mat[0]  =  EMat3Det((EMat3){ f, g, h, j, k, l, n, o, p });
	mat[1]  = -EMat3Det((EMat3){ e, g, h, i, k, l, m, o, p });
	mat[2]  =  EMat3Det((EMat3){ e, f, h, i, j, l, m, n, p });
	mat[3]  = -EMat3Det((EMat3){ e, f, g, i, j, k, m, n, o });
	mat[4]  = -EMat3Det((EMat3){ b, c, d, j, k, l, n, o, p });
	mat[5]  =  EMat3Det((EMat3){ a, c, d, i, k, l, m, o, p });
	mat[6]  = -EMat3Det((EMat3){ a, b, d, i, j, l, m, n, p });
	mat[7]  =  EMat3Det((EMat3){ a, b, c, i, j, k, m, n, o });
	mat[8]  =  EMat3Det((EMat3){ b, c, d, f, g, h, n, o, p });
	mat[9]  = -EMat3Det((EMat3){ a, c, d, e, g, h, m, o, p });
	mat[10] =  EMat3Det((EMat3){ a, b, d, e, f, h, m, n, p });
	mat[11] = -EMat3Det((EMat3){ a, b, c, e, f, g, m, n, o });
	mat[12] = -EMat3Det((EMat3){ b, c, d, f, g, h, j, k, l });
	mat[13] =  EMat3Det((EMat3){ a, c, d, e, g, h, i, k, l });
	mat[14] = -EMat3Det((EMat3){ a, b, d, e, f, h, i, j, l });
	mat[15] =  EMat3Det((EMat3){ a, b, c, e, f, g, i, j, k });

	EMat4Transpose(mat);

	EMat4Scale(mat, 1.0f/det);
}

void
EMat4InverseTo(EMat4 dest, EMat4 m)
{
	EMat4Copy(dest, m);
	EMat4Inverse(dest);
}

int
EMat4IsRoughlyEqual(EMat4 a, EMat4 b)
{
	int i;
	for (i = 0; i < 16; i++) {
		if (fabs(a[i] - b[i]) > E_EQUALITY_EPSILON)
			return 0;
	}

	return 1;
}
