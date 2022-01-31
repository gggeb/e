#ifndef E_VEC2_H
#define E_VEC2_H

typedef float EVec2[2];

void EVec2Init(EVec2, float, float);
void EVec2Copy(EVec2, EVec2);

void EVec2Add(EVec2, EVec2);            // a = a + b
void EVec2AddTo(EVec2, EVec2, EVec2);   // a = b + c

void EVec2Sub(EVec2, EVec2);            // a = a - b
void EVec2SubTo(EVec2, EVec2, EVec2);   // a = b - c

void EVec2Scale(EVec2, float);          // a = s * a
void EVec2ScaleTo(EVec2, EVec2, float); // a = s * b

void EVec2Mul(EVec2, EVec2);            // a = a * b
void EVec2MulTo(EVec2, EVec2, EVec2);   // a = b * c

void EVec2Div(EVec2, EVec2);            // a = a / b
void EVec2DivTo(EVec2, EVec2, EVec2);   // a = b / c

void EVec2Negate(EVec2);                // a = -a
void EVec2NegateTo(EVec2, EVec2);       // a = -b

float EVec2Abs(EVec2);                  // return abs(a)

void EVec2Norm(EVec2);                  // normalize a
void EVec2NormTo(EVec2, EVec2);         // a = normalize(b)

float EVec2Dot(EVec2, EVec2);           // return dot(a, b)

#endif
