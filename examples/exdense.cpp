//                                LAMFEM Example 1
//

#include "mfem.hpp"
#include <fstream>
#include <iostream>

using namespace std;
using namespace mfem;

int main(int argc, char *argv[])
{
	DenseMatrix d(2, 2);

    d(0, 0) = 2;
    d(1, 1) = 2;

    DenseMatrixInverse d_inv(d);
    DenseMatrix x =  d_inv.Mult(d);

    DenseMatrix four = d.Mult(d);
    DenseMatrix four_also = d.MultTranspose(d);

    d.Print();
    x.Print();

    four.Print();
    four_also.Print();


}
