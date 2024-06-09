#ifndef DET_H_
#define DET_H_

#include <vector>

class Det {
public:
	Det(int n);
	Det(int row, int col, std::vector<std::vector<int>> vec_ls);
	void fillDet(std::vector<std::vector<int>> vec_ls);
	int& at(int i, int j);
	void showDet();
	void T();
	int detValue();
	void unFoldTheory();
	int dimension_3();
	int dimension_3(std::vector<std::vector<int>> vec);
	int dimension_2();
	int dimension_2(std::vector<std::vector<int>> vec);
	int dimension_calculate(std::vector<std::vector<int>> vec);

	int ld_value();

public:
	int extractCommonFactor();
	void exchange2Row(int row1, int row2);
	void multiply_K_toAnotherRow(int k, int row1, int row2);
	std::vector<std::vector<int>> A();
	int unfold_row(int row);
	int unfold_col(int col);
private:
	//std::vector<std::vector<int>> origin_det;
	std::vector<std::vector<int>> det;
};

#endif // !DET_H_H
