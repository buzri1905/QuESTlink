

#include "viennacl/scalar.hpp"
#include "viennacl/vector.hpp"
#include "viennacl/matrix.hpp"
#include "viennacl/matrix_proxy.hpp"
#include "viennacl/compressed_matrix.hpp"
#include "viennacl/linalg/lanczos.hpp"

#include <iostream>
#include <string>
#include <iomanip>

#ifdef __cplusplus
extern "C" {
#endif

// TESTING eigenvalues of non-square matrix, populated with alt columns for real-imag
void mytest() {
    
    
    //set up a 3 by 3 complex matrix (6 by 6 real matrix):
    
    // DOUBLE the size of the input Hermitian matrix
    long long int dim = 8;
    
    viennacl::matrix<double> m(dim,dim);

    m(0,0)=0.3320820211; m(0,1)=0.; m(0,2)=0.6699477692; m(0,3)=-0.405973848; m(0,4)=0.677182054; m(0,5)=-0.1949962063; m(0,6)=0.1369502543; m(0,7)=-0.1483970803;
    m(1,0)=0.; m(1,1)=0.3320820211; m(1,2)=0.405973848; m(1,3)=0.6699477692; m(1,4)=0.1949962063; m(1,5)=0.677182054; m(1,6)=0.1483970803; m(1,7)=0.1369502543;
    m(2,0)=0.6699477692; m(2,1)=0.405973848; m(2,2)=0.01060019334; m(2,3)=0.; m(2,4)=0.3309064604; m(2,5)=-0.1329722856; m(2,6)=0.7470626654; m(2,7)=-0.08490966432;
    m(3,0)=-0.405973848; m(3,1)=0.6699477692; m(3,2)=0.; m(3,3)=0.01060019334; m(3,4)=0.1329722856; m(3,5)=0.3309064604; m(3,6)=0.08490966432; m(3,7)=0.7470626654;
    m(4,0)=0.677182054; m(4,1)=0.1949962063; m(4,2)=0.3309064604; m(4,3)=0.1329722856; m(4,4)=0.6909132009; m(4,5)=0.; m(4,6)=0.3528451954; m(4,7)=-0.006617375307;
    m(5,0)=-0.1949962063; m(5,1)=0.677182054; m(5,2)=-0.1329722856; m(5,3)=0.3309064604; m(5,4)=0.; m(5,5)=0.6909132009; m(5,6)=0.006617375307; m(5,7)=0.3528451954;
    m(6,0)=0.1369502543; m(6,1)=0.1483970803; m(6,2)=0.7470626654; m(6,3)=0.08490966432; m(6,4)=0.3528451954; m(6,5)=0.006617375307; m(6,6)=0.880548364; m(6,7)=0.;
    m(7,0)=-0.1483970803; m(7,1)=0.1369502543; m(7,2)=-0.08490966432; m(7,3)=0.7470626654; m(7,4)=-0.006617375307; m(7,5)=0.3528451954; m(7,6)=0.; m(7,7)=0.880548364;

    viennacl::linalg::lanczos_tag ltag(
        0.9,    // Select a power of 0.75 as the tolerance for the machine precision.
        dim,      // Compute (approximations to) the 8 largest eigenvalues
        1,
        2*dim);   // Maximum size of the Krylov space
        
    std::vector<double> lanczos_eigenvalues = viennacl::linalg::eig(m, ltag);

    for (std::size_t i = 0; i < lanczos_eigenvalues.size(); i++) {
        
        std::cout << "Approx. eigenvalue " << std::setprecision(7) << lanczos_eigenvalues[i] << "\n";
 
    }
}

#ifdef __cplusplus
}
#endif