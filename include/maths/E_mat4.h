#ifndef E_MAT4_H
#define E_MAT4_H

#define E_MAT4_ZERO     { 0.0f, 0.0f, 0.0f, 0.0f, \
                          0.0f, 0.0f, 0.0f, 0.0f, \
                          0.0f, 0.0f, 0.0f, 0.0f, \
                          0.0f, 0.0f, 0.0f, 0.0f }
#define E_MAT4_ONE      { 1.0f, 1.0f, 1.0f, 1.0f, \
                          1.0f, 1.0f, 1.0f, 1.0f, \
                          1.0f, 1.0f, 1.0f, 1.0f, \
                          1.0f, 1.0f, 1.0f, 1.0f }
#define E_MAT4_IDENTITY { 1.0f, 0.0f, 0.0f, 0.0f, \
                          0.0f, 1.0f, 0.0f, 0.0f, \
                          0.0f, 0.0f, 1.0f, 0.0f, \
                          0.0f, 0.0f, 0.0f, 1.0f }

typedef float EMat4[16];

void EMat4Copy(EMat4, EMat4);

void EMat4Zero(EMat4);
void EMat4One(EMat4);
void EMat4Identity(EMat4);

void EMat4Mul(EMat4, EMat4); // a = b * a`
void EMat4MulTo(EMat4, EMat4, EMat4); // a = b * c

void EMat4Transpose(EMat4); // a = transpose(a)
void EMat4TransposeTo(EMat4, EMat4); // a = transpose(b)

void EMat4Scale(EMat4, float); // a = s * a
void EMat4ScaleTo(EMat4, EMat4, float); // a = s * b

float EMat4Det(EMat4); // return det(a)

void EMat4Inverse(EMat4); // a = a^-1
void EMat4InverseTo(EMat4, EMat4); // a = b^-1

int EMat4IsRoughlyEqual(EMat4, EMat4);

#endif
