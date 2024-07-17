int testDoubleFunction(void)
{
	double dblA = 0.0, dblB = 0.0;
	int fail = 0;

	printf("---------------------------\n");
	printf("Function: getDoublePositive\n");
	printf("---------------------------\n");
	printf("For each of these tests, enter the following\n");
	printf("three values (space delimited):  %d %d %.1lf\n\n", TEST_NEG, TEST_ZERO, TEST_DBL);

	//-----------------------------------
	// Test-1: argument and return value
	printf("TEST-1: ");
	dblB = getDoublePositive(&dblA);
	if (dblA == dblB && dblA == TEST_DBL)
	{
		printf("<PASSED>\n");
	}
	else
	{
		printf("<!!! FAILED !!!>\n");
		fail++;
	}

	//-----------------------------------
	// Test-2: return value only
	dblA = dblB = 0.0;
	printf("TEST-2: ");
	dblA = getDoublePositive(NULL);
	if (dblA == TEST_DBL)
	{
		printf("<PASSED>\n");
	}
	else
	{
		printf("<!!! FAILED !!!>\n");
		fail++;
	}

	//-----------------------------------
	// Test-3: argument only
	dblA = dblB = 0.0;
	printf("TEST-3: ");
	getDoublePositive(&dblA);
	if (dblA == TEST_DBL)
	{
		printf("<PASSED>\n\n");
	}
	else
	{
		printf("<!!! FAILED !!!>\n\n");
		fail++;
	}
	
	return fail;
}
