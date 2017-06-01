//                                LAMFEM Example 1
//

#include "mfem.hpp"
#include <fstream>
#include <iostream>

using namespace std;
using namespace mfem;

int main(int argc, char *argv[])
{
	SparseMatrix m(10);
	DenseMatrix d(10);

	Vector v(10);

	printf("Sparse: %d\n", m.Width());
	printf("Dense: %d\n", d.Width());
	printf("Vector: %d\n", v.Size());
}
