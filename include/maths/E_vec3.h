#ifndef E_VEC3_H
#define E_VEC3_H

typedef float EVec3[3];

void EVec3Init(EVec3, float, float, float);
void EVec3Copy(EVec3, EVec3);

void EVec3Add(EVec3, EVec3);            // a = a + b
void EVec3AddTo(EVec3, EVec3, EVec3);   // a = b + c

void EVec3Sub(EVec3, EVec3);            // a = a - b
void EVec3SubTo(EVec3, EVec3, EVec3);   // a = b - c

void EVec3Scale(EVec3, float);          // a = s * a
void EVec3ScaleTo(EVec3, EVec3, float); // a = s * b

void EVec3Mul(EVec3, EVec3);            // a = a * b
void EVec3MulTo(EVec3, EVec3, EVec3);   // a = b * c

void EVec3Div(EVec3, EVec3);            // a = a / b
void EVec3DivTo(EVec3, EVec3, EVec3);   // a = b / c

void EVec3Negate(EVec3);                // a = -a
void EVec3NegateTo(EVec3, EVec3);       // a = -b

float EVec3Abs(EVec3);                  // return abs(a)

void EVec3Norm(EVec3);                  // normalize a
void EVec3NormTo(EVec3, EVec3);         // a = normalize(b)

float EVec3Dot(EVec3, EVec3);           // return dot(a, b)
void EVec3Cross(EVec3, EVec3, EVec3);   // a = cross(b, c)

#endif
