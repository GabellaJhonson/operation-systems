#include <iostream>
#include <vector>
#include <thread>
using namespace std;
int StringAndColumn(vector <vector<int>>& Matrix1, vector <vector<int>> Matrix2, int j, int k) {
	int result = 0;
	for (int i = 0; i < Matrix1.size(); i++) {
		result += Matrix1[j][i] * Matrix2[i][k];
	}
	return result;
}
void MatrixMultiply(vector <vector<int>>& MatrixRes, vector <vector<int>> Matrix, int k, int sz) {
	//vector <thread> th;
	for (int i = k; i < Matrix.size(); i += sz) {
		for (int j = 0; j < Matrix[0].size(); j++) {
			MatrixRes[i][j] = StringAndColumn(MatrixRes, Matrix, i, j);
		}
	}
}

int main() {
	int n1, m1, n2, m2;
	cout << "Enter size of first matrix: " << endl;
	cin >> n1 >> m1;
	cout << "Enter elements: " << endl;
	vector <vector<int>> Matrix1(n1, vector <int>(m1));
	for (int i = 0; i < Matrix1.size(); i++) {
		for (int j = 0; j < Matrix1[0].size(); j++) {
			cin >> Matrix1[i][j];
		}
	}
	cout << "Enter size of second matrix: " << endl;
	cin >> n2 >> m2;
	vector <vector<int>> Matrix2(n2, vector <int>(m2));
	cout << "Enter elements: " << endl;
	for (int i = 0; i < Matrix2.size(); i++) {
		for (int j = 0; j < Matrix2[0].size(); j++) {
			cin >> Matrix2[i][j];
		}
	}

	cout << endl;
	cout << "Enter count of threads: ";
	int sz;
	cin >> sz;
	vector <thread> th;
	for (int i = 0; i < sz; i++)
	{
		//th.emplace_back(power, vec, i);  // на паре так делали
		th.emplace_back([&Matrix1, &Matrix2, sz, i]() {MatrixMultiply(Matrix1, Matrix2, i, sz); });
	}
	for (int i = 0; i < sz; i++)
	{
		th[i].join();
	}
	for (int i = 0; i < Matrix1.size(); i++) {
		for (int j = 0; j < Matrix1[0].size(); j++) {
			cout << Matrix1[i][j] << " ";
		}
		cout << endl;
	}
}