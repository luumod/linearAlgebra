#include "Det.h"
#include "GenerateDet.h"
#include <iostream>

int main(){
	Det d(3, 3, { {1,1,3},{2,1,2},{3,5,3} });
	d.showDet();
	std::cout << "原始行列式的值： " << d.detValue()<<'\n';
	d.T();
	d.showDet();
	std::cout << "行列式转置后，值不变 " << d.detValue()<<"\n\n";

	Det d1(3, 3, { { 0,0,0 }, { -1,-2,-3 }, { 4,6,3 } });
	d1.showDet();
	std::cout << "行列式某行元素全是0，值为：" << d1.detValue() << "\n\n";

	Det d2(3, 3, { { 1,2,3 }, { -1,-2,-3 }, { 4,6,3 } });
	d2.showDet();
	std::cout << "行列式两行成比例，值为：" << d2.detValue() << "\n\n";

	Det d3(3, 3, { { 3,6,9 }, { 12,4,8 }, { 20,25,15 } });
	d3.showDet();
	std::cout << "行列式的值："<< d3.detValue() << '\n';
	std::cout << "行列式的某行含有公因子k，则k可以提到外面：" << d3.extractCommonFactor() << "\n\n";
	
	Det d4(3, 3, { { 3,6,9 }, { 12,4,8 }, { 2,3,4 } });
	d4.showDet();
	std::cout << "行列式的值：" << d4.detValue() << '\n';
	int row1 = 0, row2 = 2;
	d4.exchange2Row(row1,row2);
	d4.showDet();
	std::cout << "行列式任意两行互换，行列式变号 " << row1 << ", " << row2 << ": " << d4.detValue() << "\n\n";

	Det d5(3, 3, { { 1,2,3 }, { 3,4,8 }, { 2,1,4 } });
	d5.showDet();
	std::cout << "行列式的值：" << d5.detValue() << '\n';
	int k = 10;
	row1 = 0, row2 = 2;
	d5.multiply_K_toAnotherRow(k, row1, row2);
	d5.showDet();
	std::cout << "行列式某行元素乘以k倍，加到另一行上去，行列式的值不变 (" <<k<<" * "<< row1 << ") +-> " << row2 << ": " << d5.detValue() << "\n\n";


	Det d6(3, 3, { { 1,2,3 }, { 1,0,2}, { 0,1,3 } });
	std::cout << "行列式的代数余子式：" << '\n';
	auto vec2 = d6.A();
	for (auto& x : vec2) {
		for (auto& y : x) {
			std::cout << y << ' ';
		}
		putchar('\n');
	}
	putchar('\n');

	Det d7(4, 4, { { 2,-1,0,0 }, { 0,2,-1,0}, { 0,0,2,-1 },{-1,0,0,2} });
	vec2 = d7.A();
	for (auto& x : vec2) {
		for (auto& y : x) {
			std::cout << y << ' ';
		}
		putchar('\n');
	}
	putchar('\n');
	std::cout << "行列式按行展开，第1行: " << d7.unfold_row(0) << '\n';
	std::cout << "行列式按行展开，第2行: " << d7.unfold_row(1) << '\n';
	std::cout << "行列式按行展开，第3行: " << d7.unfold_row(2) << '\n';
	std::cout << "行列式按行展开，第4行: " << d7.unfold_row(3) << '\n';
	std::cout << "行列式按列展开，第1列: " << d7.unfold_col(0) << '\n';
	std::cout << "行列式按列展开，第2列: " << d7.unfold_col(1) << '\n';
	std::cout << "行列式按列展开，第3列: " << d7.unfold_col(2) << '\n';
	std::cout << "行列式按列展开，第4列: " << d7.unfold_col(3) << "\n\n";

	Det d8(4, 4, { { 1,1,1,1 }, { 1,2,0,0}, { 1,0,3,0 },{1,0,0,4} });
	vec2 = d8.A();
	for (auto& x : vec2) {
		for (auto& y : x) {
			std::cout << y << ' ';
		}
		putchar('\n');
	}
	putchar('\n');
	std::cout << "行列式按行展开，第1行: " << d8.unfold_row(0) << '\n';
	std::cout << "行列式按行展开，第2行: " << d8.unfold_row(1) << '\n';
	std::cout << "行列式按行展开，第3行: " << d8.unfold_row(2) << '\n';
	std::cout << "行列式按行展开，第4行: " << d8.unfold_row(3) << '\n';
	std::cout << "行列式按列展开，第1列: " << d8.unfold_col(0) << '\n';
	std::cout << "行列式按列展开，第2列: " << d8.unfold_col(1) << '\n';
	std::cout << "行列式按列展开，第3列: " << d8.unfold_col(2) << '\n';
	std::cout << "行列式按列展开，第4列: " << d8.unfold_col(3) << "\n\n";
	

	Det d9 = GenerateDet::generate(GenerateDet::Type::left_down_triangle, 4);
	d9.showDet();
	std::cout << "下三角行列式的值：" << d9.ld_value() << "\n\n";

	return 0;
}
