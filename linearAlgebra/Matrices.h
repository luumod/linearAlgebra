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
	//�������
	Matrices add(const Matrices& lhs);
	Matrices add(int num);
	//�������
	Matrices mul(const Matrices& lhs);
	Matrices mul(int num);
	//�������
	Matrices minus(const Matrices& lhs);
	Matrices minus(int num);
	//�����ݴ�
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
