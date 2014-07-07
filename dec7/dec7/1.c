#include <stdio.h>

struct coodi {
	double point;
};

struct tetragon {
	struct coodi codi[2];
};

int main(void)
{
	struct tetragon x;

	x.codi.point = 1;


	return 0;
}