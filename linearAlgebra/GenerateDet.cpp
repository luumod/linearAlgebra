#include "GenerateDet.h"
#include <iostream>

//generate n*n determinant.
Det GenerateDet::generate(Type type, int n) {
	gen_seek();
	switch (type)
	{
	case GenerateDet::left_down_triangle:
		return gen_left_down_triangle(n);
		break;
	case GenerateDet::right_up_triangle:
		break;
	case GenerateDet::left_up_triangle:
		break;
	case GenerateDet::right_down_triangle:
		break;
	case GenerateDet::vandermond:
		break;
	default:
		break;
	}
}
void GenerateDet::gen_seek() {
	srand(time(0));
}

Det GenerateDet::gen_left_down_triangle(int n) {
	Det det(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j) {
				continue;
			}
			det.at(i, j) = rand() % 100;
		}
	}
	return det;
}