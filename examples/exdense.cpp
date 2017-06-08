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

    Vector ev(2);

#ifdef MFEM_USE_LAPACK
    auto d_dsyev = d;

    printf("before\n");
    d_dsyev.Print();

    DenseMatrix evects;
    d_dsyev.Eigenvalues(ev);

    printf("after evavlues\n");
    d_dsyev.Print();

    d_dsyev.Eigenvalues(ev, evects);

    printf("after evectors\n");
    d_dsyev.Print();

    printf("evects\n");
    evects.Print();
    ev.Print();

    DenseMatrixSVD d_svd(d);

    DenseMatrixSVD d_svd_stand_alone;

    auto d_copy = d;

    auto d_svd_no_destroy = d_svd_stand_alone.EvalCopy(d_copy);

    DenseMatrixEigensystem d_eig(d);
    d_eig.Eval();

#endif

    DenseMatrixInverse d_inv(d);
    DenseMatrix x =  d_inv.Mult(d);

    DenseMatrix four = d.Mult(d);
    DenseMatrix four_also = d.MultTranspose(d);
    DenseMatrix four_copy = four;
    DenseMatrix four_copy2 = std::move(four_copy);

    std::vector<DenseMatrix> dvect(3);

    for (auto& d_i : dvect)
    {
        d_i.SetSize(2, 2);
        d_i(0, 0) = 5.0;
    }


    auto dvect_copy = dvect;

    for (auto& d_i : dvect_copy)
        d_i.SetSize(4, 4);

    for (auto& d_i : dvect)
        d_i.Print();

    for (auto& d_i : dvect_copy)
        d_i.Print();

    d.Print();
    x.Print();

    four.Print();
    four_also.Print();


}
