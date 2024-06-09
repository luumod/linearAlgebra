#ifndef GENERATE_DET_H_
#define GENERATE_DET_H_

#include "Det.h"

class GenerateDet {
public:
	enum Type {
		left_down_triangle,
		right_up_triangle,

		left_up_triangle,
		right_down_triangle,

		vandermond,
	};
	//generate n*n determinant.
	static Det generate(Type type, int n);
protected:
	static void gen_seek();
	static Det gen_left_down_triangle(int n);
private:
	GenerateDet() {}

};

#endif // !GENERATE_DET_H_

