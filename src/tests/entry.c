#include <stdlib.h>

#include "E_test.h"
#include "E_maths.h"

E_TEST(EMat4Inverse) {
	int i;
	EMat4 a, out;

	do {
		for (i = 0; i < 16; i++)
			a[i] = (float)(rand() % 20);
	} while (EMat4Det(a) != 0.0f);

	EMat4InverseTo(out, a);
	EMat4Mul(a, out);

	E_ASSERT(EMat4IsRoughlyEqual(a, (EMat4)E_MAT4_IDENTITY));
}

int
main()
{
	E_TEST_RUN_MANY(EMat4Inverse, 10000);
	return 0;
}
