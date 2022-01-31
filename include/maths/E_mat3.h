#ifndef E_MAT3_H
#define E_MAT3_H

#define E_MAT3_ZERO     { 0.0f, 0.0f, 0.0f, \
                          0.0f, 0.0f, 0.0f, \
                          0.0f, 0.0f, 0.0f }
#define E_MAT3_ONE      { 1.0f, 1.0f, 1.0f, \
                          1.0f, 1.0f, 1.0f, \
                          1.0f, 1.0f, 1.0f }
#define E_MAT3_IDENTITY { 1.0f, 0.0f, 0.0f, \
                          0.0f, 1.0f, 0.0f, \
                          0.0f, 0.0f, 1.0f }

typedef float EMat3[9];

void EMat3Copy(EMat3, EMat3);

void EMat3Zero(EMat3);
void EMat3One(EMat3);
void EMat3Identity(EMat3);

void EMat3Mul(EMat3, EMat3); // a = b * a`
void EMat3MulTo(EMat3, EMat3, EMat3); // a = b * c

void EMat3Transpose(EMat3); // a = transpose(a)
void EMat3TransposeTo(EMat3, EMat3); // a = transpose(b)

void EMat3Scale(EMat3, float); // a = s * a
void EMat3ScaleTo(EMat3, EMat3, float); // a = s * b

float EMat3Det(EMat3); // return det(a)

void EMat3Inverse(EMat3); // a = a^-1
void EMat3InverseTo(EMat3, EMat3); // a = b^-1

int EMat3IsRoughlyEqual(EMat3, EMat3);

#endif
