#ifndef E_VEC3_H
#define E_VEC3_H

typedef float EVec4[4];

void EVec4Init(EVec4, float, float, float, float);
void EVec4Copy(EVec4, EVec4);

void EVec4Add(EVec4, EVec4);            // a = a + b
void EVec4AddTo(EVec4, EVec4, EVec4);   // a = b + c

void EVec4Sub(EVec4, EVec4);            // a = a - b
void EVec4SubTo(EVec4, EVec4, EVec4);   // a = b - c

void EVec4Scale(EVec4, float);          // a = s * a
void EVec4ScaleTo(EVec4, EVec4, float); // a = s * b

void EVec4Mul(EVec4, EVec4);            // a = a * b
void EVec4MulTo(EVec4, EVec4, EVec4);   // a = b * c

void EVec4Div(EVec4, EVec4);            // a = a / b
void EVec4DivTo(EVec4, EVec4, EVec4);   // a = b / c

void EVec4Negate(EVec4);                // a = -a
void EVec4NegateTo(EVec4, EVec4);       // a = -b

float EVec4Abs(EVec4);                  // return abs(a)

void EVec4Norm(EVec4);                  // normalize a
void EVec4NormTo(EVec4, EVec4);         // a = normalize(b)

float EVec4Dot(EVec4, EVec4);           // return dot(a, b)

#endif
