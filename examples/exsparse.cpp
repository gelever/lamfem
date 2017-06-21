//                                LAMFEM Example 1
//

#include "mfem.hpp"
#include <fstream>
#include <iostream>

using namespace std;
using namespace mfem;

int main(int argc, char *argv[])
{
	SparseMatrix s(10, 10);

	std::vector<int> indptr(4,0);
	std::vector<int> indices(3);
	std::vector<double> data(3,1);

	std::iota(begin(indices), end(indices), 0);
	std::iota(begin(indptr), end(indptr), 0);

	SparseMatrix s2(indptr, indices, data, 2, 3);

	const int nnz = s.NumNonZeroElems();
	const int nnz2 = s2.NumNonZeroElems();
	printf("%d\n", nnz);
	printf("%d\n", nnz2);

	std::vector<int> indptr2(3);
	std::vector<int> indices2(4);
	std::vector<double> data2(4, 1);

	indptr2[0] = 0;
	indptr2[1] = 2;
	indptr2[2] = 4;

	indices2[0] = 2;
	indices2[1] = 1;
	indices2[2] = 3;
	indices2[3] = 0;

	SparseMatrix s3(indptr2, indices2, data2, 2, 3);

	s3.SortColumnIndices();

	SparseMatrix s4 = Transpose(s3);
	SparseMatrix s5 = Mult(s4, s3);

	printf("sort:\n");
	s3.Print();
	printf("s3 * s4:\n");
	s5.Print();


}
