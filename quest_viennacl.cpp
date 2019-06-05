

#include "viennacl/matrix.hpp"


#ifdef __cplusplus
extern "C" {
#endif

// @TESTING 
void mytest() {
    //set up a 3 by 5 matrix:
    viennacl::matrix<double>  vcl_matrix(4, 5);
    //fill it up:
    vcl_matrix(0,2) = 1.0;
    vcl_matrix(1,2) = -1.5;
    vcl_matrix(2,0) = 4.2;
    vcl_matrix(3,4) = 3.1415;
}

#ifdef __cplusplus
}
#endif