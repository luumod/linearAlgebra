#ifndef MATRICES_H_
#define MATRICES_H_

#include "Det.h"

class Matrices :public Det {
public:
	Matrices(int n);
	Matrices(int row, int col);
	Matrices(int row, int col, std::vector<std::vector<int>> vec_ls);

	friend std::ostream& operator<<(std::ostream& out, const  Matrices& mat);

	void T();
	//¾ØÕóÏà¼Ó
	Matrices add(const Matrices& lhs);
	Matrices add(int num);
	//¾ØÕóÏà³Ë
	Matrices mul(const Matrices& lhs);
	Matrices mul(int num);
	//¾ØÕóÏà¼õ
	Matrices minus(const Matrices& lhs);
	Matrices minus(int num);
	//¾ØÕóÃÝ´Î
	Matrices pow(int num);

	Matrices operator+(int num);
	Matrices operator+(const Matrices& lhs);
	Matrices operator-(int num);
	Matrices operator-(const Matrices& lhs);
	Matrices operator*(int num);
	Matrices operator*(const Matrices& lhs);
private:

};

//class GenerateMatrices {
//public:
//	enum Type {
//
//	};
//	static Matrices generate
//private:
//	
//};

#endif // !MATRICES_H_
