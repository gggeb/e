#ifndef E_MAT2_H
#define E_MAT2_H

#define E_MAT2_ZERO     { 0.0f, 0.0f, \
                          0.0f, 0.0f }
#define E_MAT2_ONE      { 1.0f, 1.0f, \
                          1.0f, 1.0f }
#define E_MAT2_IDENTITY { 1.0f, 0.0f, \
                          0.0f, 1.0f }

typedef float EMat2[4];

void EMat2Copy(EMat2, EMat2);

void EMat2Zero(EMat2);
void EMat2One(EMat2);
void EMat2Identity(EMat2);

void EMat2Mul(EMat2, EMat2); // a = b * a`
void EMat2MulTo(EMat2, EMat2, EMat2); // a = b * c

void EMat2Transpose(EMat2); // a = transpose(a)
void EMat2TransposeTo(EMat2, EMat2); // a = transpose(b)

void EMat2Scale(EMat2, float); // a = s * a
void EMat2ScaleTo(EMat2, EMat2, float); // a = s * b

float EMat2Det(EMat2); // return det(a)

void EMat2Inverse(EMat2); // a = a^-1
void EMat2InverseTo(EMat2, EMat2); // a = b^-1

int EMat2IsRoughlyEqual(EMat2, EMat2);

#endif
