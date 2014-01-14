enum list{
	test_1,
	test_2,
	total
};

struct Detail{
	string name;
	int bin;
	float min;
	float max;
};

struct Detail detail[total] = {
	{ "test.1", 10, 0, 100},
	{ "test.2", 2, 0, 100}
}; 

