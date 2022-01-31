#ifndef E_TEST_H
#define E_TEST_H

#include <stdio.h>
#include <stdlib.h>

#include "E_common.h"

#define E_TEST(testName) void E_TEST_ ## testName(void)

#define E_TEST_RUN(testName)                                                                                      \
	{                                                                                                             \
		ETestAssertionReset();                                                                                    \
		ETestBenchStart();                                                                                        \
		fprintf(stderr, E_COL_YELLOW "Testing '%s'\n", #testName);                                                \
		E_TEST_ ## testName();                                                                                    \
		if (ETestAssertionStatus()) {                                                                             \
			ETestBenchStop();                                                                                     \
			fprintf(stdout, E_COL_GREEN "\tTime: %.17fs\n" E_COL_RESET, ETestBenchTime());                        \
		}                                                                                                         \
	}                                                                                                             \

#define E_TEST_RUN_MANY(testName, num)                                                                            \
	do {                                                                                                          \
		long int i, n = num;                                                                                      \
		double sum = 0, *times = malloc(n * sizeof(double));                                                      \
		if (times == NULL) {                                                                                      \
			fprintf(stderr, "Cannot perform test '" #testName "'\n");                                             \
			break;                                                                                                \
		}                                                                                                         \
		printf(E_COL_YELLOW "Testing '%s'\n", #testName);                                                         \
		ETestAssertionReset();                                                                                    \
		for (i = 0; i < n; i++) {                                                                                 \
			ETestBenchStart();                                                                                    \
			E_TEST_ ## testName();                                                                                \
			if (!ETestAssertionStatus())                                                                          \
				goto CLEANUP_TEST_ ## testName;                                                                   \
			ETestBenchStop();                                                                                     \
			times[i] = ETestBenchTime();                                                                          \
		}                                                                                                         \
		for (i = 0; i < n; i++)                                                                                   \
			sum += times[i];                                                                                      \
		fprintf(stdout, E_COL_GREEN "\tIterations: %ld\n"                                                         \
				                    "\tTotal time: %.17fs\n"                                                      \
					            	"\t Avg. time: %.17fs\n" E_COL_RESET, n, sum, sum / n);                       \
CLEANUP_TEST_ ## testName:                                                                                        \
		free(times);                                                                                              \
	} while(0)                                                                                                    \

#define E_ASSERT(cond)                                                                                            \
	if (!(cond)) {                                                                                                \
		fprintf(stderr, E_COL_RED "\tAssertion '%s' in '%s:%d' FAILED\n" E_COL_RESET, #cond, __FILE__, __LINE__); \
		ETestAssertionFailed();                                                                                   \
	}                                                                                                             \

#define E_ASSERT_EQ(a, b) E_ASSERT((a) == (b))
#define E_ASSERT_NE(a, b) E_ASSERT((a) != (b))

void ETestAssertionReset(void);
void ETestAssertionFailed(void);
int ETestAssertionStatus(void);

void ETestBenchStart(void);
void ETestBenchStop(void);
double ETestBenchTime(void);

#endif
