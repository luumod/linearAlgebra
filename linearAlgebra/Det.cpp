#include "Det.h"
#include <cassert>
#include <iostream>
#include <algorithm>

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

Det::Det(int n)
	:det(n, std::vector<int>(n, 0)) {}

Det::Det(int row, int col, std::vector<std::vector<int>> vec_ls)
	:det(row, std::vector<int>(col, 0)) {
	for (int i = 0; i < vec_ls.size(); i++) {
		for (int j = 0; j < vec_ls[i].size(); j++) {
			det[i][j] = vec_ls[i][j];
		}
	}
}
void Det::fillDet(std::vector<std::vector<int>> vec_ls) {
	det.clear();
	for (int i = 0; i < vec_ls.size(); i++) {
		for (int j = 0; j < vec_ls[i].size(); j++) {
			det[i][j] = vec_ls[i][j];
		}
	}
}
int& Det::at(int i, int j) {
	assert(i < det.size() && j < det.size(), "i,j must be eligible for the determinate");
	return det[i][j];
}
void Det::showDet() {
	for (int i = 0; i < det.size(); i++) {
		for (int j = 0; j < det[i].size(); j++) {
			std::cout << det[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

void Det::T() {
	int row = det.size(), col = det[0].size();
	auto temp = det;
	if (row != col) {
		//resize
		det.clear();
		det.resize(col);
		for (auto& row_ls : det) {
			row_ls.resize(row);
		}
	}
	row = det.size(), col = det[0].size();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			det[i][j] = temp[j][i];
		}
	}
}

int Det::detValue() {
	switch (det.size())
	{
	case 2:
		return dimension_2();
		break;
	case 3:
		return dimension_3();
		break;
	default:
		return 0;
	}
}
void Det::unFoldTheory() {

}
int Det::dimension_3() {
	assert(det.size() == 3 && det[0].size() == 3, "the determinant must be 3*3");
	return det[0][0] * det[1][1] * det[2][2]
		+ det[1][0] * det[2][1] * det[0][2]
		+ det[2][0] * det[0][1] * det[1][2]
		- det[0][2] * det[1][1] * det[2][0]
		- det[0][0] * det[1][2] * det[2][1]
		- det[0][1] * det[1][0] * det[2][2];
}
int Det::dimension_3(std::vector<std::vector<int>> vec) {
	assert(vec.size() == 3 && vec[0].size() == 3, "the determinant must be 3*3");
	return vec[0][0] * vec[1][1] * vec[2][2]
		+ vec[1][0] * vec[2][1] * vec[0][2]
		+ vec[2][0] * vec[0][1] * vec[1][2]
		- vec[0][2] * vec[1][1] * vec[2][0]
		- vec[0][0] * vec[1][2] * vec[2][1]
		- vec[0][1] * vec[1][0] * vec[2][2];
}
int Det::dimension_2() {
	assert(det.size() == 2 && det[0].size() == 2, "the determinant must be 2*2");
	return det[0][0] * det[1][1]
		- det[0][1] * det[1][0];
}
int Det::dimension_2(std::vector<std::vector<int>> vec) {
	assert(vec.size() == 2 && vec[0].size() == 2, "the determinant must be 2*2");
	return vec[0][0] * vec[1][1]
		- vec[0][1] * vec[1][0];
}
int Det::dimension_calculate(std::vector<std::vector<int>> vec) {
	if (vec.size() == 3 && vec[0].size() == 3) {
		return dimension_3(vec);
	}
	else if (vec.size() == 2 && vec[0].size() == 2) {
		return dimension_2(vec);
	}
	return 0;
}

int Det::ld_value() {
	int res{ 1 };
	for (int i = 0; i < det.size(); i++) {
		res *= det[i][i];
	}
	return res;
}

int Det::extractCommonFactor() {
	std::vector<int> factor(det.size());
	//prepare
	for (int i = 0; i < det.size(); i++) {
		factor[i] = det[i][0];
		for (int j = 0; j < det[0].size(); j++) {
			factor[i] =(factor[i], det[i][j]);
		}
	}
	//extract
	for (int i = 0; i < det.size(); i++) {
		for (int j = 0; j < det[0].size(); j++) {
			det[i][j] /= factor[i];
		}
	}
	int res = 1;
	for (auto& x : factor) {
		std::cout << x << ' ';
		res *= x;
	}
	putchar('\n');
	showDet();
	return res * dimension_3();
}
void Det::exchange2Row(int row1, int row2) {
	std::vector<int> row1_vec(det[row1]);
	std::vector<int> row2_vec(det[row2]);
	det[row1] = row2_vec;
	det[row2] = row1_vec;
}
void Det::multiply_K_toAnotherRow(int k, int row1, int row2) {
	std::vector<int> row1_vec(det[row1]);
	for (auto& x : row1_vec)
		x *= k;
	for (int j = 0; j < det[row2].size(); j++) {
		det[row2][j] += row1_vec[j];
	}
}
//余子式
std::vector<std::vector<int>> Det::A() {
	//代数余子式
	std::vector<std::vector<int>> sub(det.size(), std::vector<int>(det[0].size(), 0));
	//某个元素的余子式
	std::vector<std::vector<int>> sub_ex(det.size() - 1, std::vector<int>(det[0].size() - 1, 0));
	for (int i = 0; i < det.size(); i++) {
		for (int j = 0; j < det[0].size(); j++) {
			for (int a = 0; a < det.size(); a++) {
				for (int b = 0; b < det[0].size(); b++) {
					if (a == i || b == j) {
						continue;
					}
					if (a > i && b > j) {
						sub_ex[a - 1][b - 1] = det[a][b];
					}
					else if (a > i) {
						sub_ex[a - 1][b] = det[a][b];
					}
					else if (b > j) {
						sub_ex[a][b - 1] = det[a][b];
					}
					else {
						sub_ex[a][b] = det[a][b];
					}
				}
			}
			sub[i][j] = dimension_calculate(sub_ex);
		}
	}
	for (int i = 0; i < sub.size(); i++) {
		for (int j = 0; j < sub[0].size(); j++) {
			(i + j) & 1 ? sub[i][j] = -sub[i][j] : sub[i][j] = sub[i][j];
		}
	}
	return sub;
}
int Det::unfold_row(int row) {
	auto vec2 = A();
	int res{ 0 };
	for (int i = 0; i < vec2[row].size(); i++) {
		res += vec2[row][i] * det[row][i];
	}
	return res;
}
int Det::unfold_col(int col) {
	auto vec2 = A();
	int res{ 0 };
	for (int i = 0; i < vec2.size(); i++) {
		res += vec2[i][col] * det[i][col];
	}
	return res;
}