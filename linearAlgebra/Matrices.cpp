#include "Matrices.h"
#include <cassert>

Matrices::Matrices(int n)
	:Det(n) {}

Matrices::Matrices(int row, int col)
	:Det(row, col) {}

Matrices::Matrices(int row, int col, std::vector<std::vector<int>> vec_ls)
	:Det(row, col, vec_ls) {}

void Matrices::T(){
	Det::T();
}

Matrices Matrices::add(const Matrices& lhs){
	assert(det.size() == lhs.det.size() && det[0].size() == lhs.det[0].size(), "矩阵相加时，必须是同型矩阵");
	Matrices add_det(det.size(), det[0].size());
	for (int i = 0; i < det.size(); i++) {
		for (int j = 0; j < det[0].size(); j++) {
			add_det.at(i, j) = det[i][j] + lhs.det[i][j];
		}
	}
	return add_det;
}

Matrices Matrices::add(int num)
{
	Matrices add_det(det.size(), det[0].size());
	for (int i = 0; i < det.size(); i++) {
		for (int j = 0; j < det[0].size(); j++) {
			add_det.at(i, j) = det[i][j] + num;
		}
	}
	return add_det;
}

Matrices Matrices::mul(const Matrices& lhs){
	assert(det[0].size() == lhs.det.size(), "矩阵相乘时，必须是前一个矩阵的列数等于后一个矩阵的行数");
	Matrices mul_det(det.size(),lhs.det[0].size());
	for (int i = 0; i < mul_det.row(); i++) {
		for (int j = 0; j < mul_det.col(); j++) {
			int res = 0;
			for (int k = 0; k < mul_det.col(); k++) {
				res += det[i][k] * lhs.det[k][j];
			}
			mul_det.at(i, j) = res;
		}
	}
	return mul_det;
}

Matrices Matrices::mul(int num)
{
	Matrices add_det(det.size(), det[0].size());
	for (int i = 0; i < det.size(); i++) {
		for (int j = 0; j < det[0].size(); j++) {
			add_det.at(i, j) = det[i][j] * num;
		}
	}
	return add_det;
}

Matrices Matrices::minus(const Matrices& lhs)
{
	Matrices minus_mat(det.size(), det[0].size());
	for (int i = 0; i < det.size(); i++) {
		for (int j = 0; j < det[0].size(); j++) {
			minus_mat.at(i, j) = det[i][j] - lhs.det[i][j];
		}
	}
	return minus_mat;
}

Matrices Matrices::minus(int num)
{
	Matrices add_det(det.size(), det[0].size());
	for (int i = 0; i < det.size(); i++) {
		for (int j = 0; j < det[0].size(); j++) {
			add_det.at(i, j) = det[i][j] - num;
		}
	}
	return add_det;
}

Matrices Matrices::pow(int num)
{
	Matrices pow_det(det.size(), det[0].size(), det), temp(pow_det);
	for (int i = 1; i < num; i++) {
		pow_det = pow_det * temp;
	}
	return pow_det;	
}

Matrices Matrices::operator+(int num)
{
	return add(num);
}

Matrices Matrices::operator+(const Matrices& lhs)
{
	return add(lhs);
}

Matrices Matrices::operator-(int num)
{
	return minus(num);
}

Matrices Matrices::operator-(const Matrices& lhs)
{
	return minus(lhs);
}

Matrices Matrices::operator*(int num)
{
	return mul(num);
}

Matrices Matrices::operator*(const Matrices& lhs)
{
	return mul(lhs);
}

std::ostream& operator<<(std::ostream& out, const Matrices& mat)
{
	mat.showDet();
	return out;
}
