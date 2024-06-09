#ifndef DET_H_
#define DET_H_

#include <vector>
#include <iostream>

class Det {
public:
	Det(int n);
	Det(int row, int col);
	Det(int row, int col, std::vector<std::vector<int>> vec_ls);
	void fillDet(std::vector<std::vector<int>> vec_ls);
	int& at(int i, int j);
	void showDet()const;
	friend std::ostream& operator<<(std::ostream& out, const Det& lhs);
	void T();
	int detValue();
	void unFoldTheory();
	int dimension_3();
	int dimension_3(std::vector<std::vector<int>> vec);
	int dimension_2();
	int dimension_2(std::vector<std::vector<int>> vec);
	int dimension_calculate(std::vector<std::vector<int>> vec);
	int ld_value();

	std::pair<int, int> shape() {
		return std::pair<int, int>(det.size(), det[0].size());
	}
	int row() { return det.size(); }
	int col() { return det[0].size(); }
public:
	int extractCommonFactor();
	void exchange2Row(int row1, int row2);
	void multiply_K_toAnotherRow(int k, int row1, int row2);
	std::vector<std::vector<int>> A();
	int unfold_row(int row);
	int unfold_col(int col);
protected:
	//std::vector<std::vector<int>> origin_det;
	std::vector<std::vector<int>> det;
};

#endif // !DET_H_H
