#include <time.h>

static int E_assertStatus;
static clock_t E_benchStart, E_benchStop;

void
ETestAssertionReset(void)
{
	E_assertStatus = 1;
}

void
ETestAssertionFailed(void)
{
	E_assertStatus = 0;
}

int
ETestAssertionStatus(void)
{
	return E_assertStatus;
}

void
ETestBenchStart(void)
{
	E_benchStart = clock();
}

void
ETestBenchStop(void)
{
	E_benchStop = clock();
}

double
ETestBenchTime(void)
{
	return (double)(E_benchStop - E_benchStart) / CLOCKS_PER_SEC;
}
