#include "matrix.h"
#include <omp.h>
#include <random>
#include <chrono>
#include <stdexcept>
#include <sstream>

std::vector<double> get_random_OpenMp(size_t size){

  std::vector<double>result(size);

  #pragma omp parallel shared(result)
  {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::cauchy_distribution<double>dis(1, 2);

    #pragma omp for schedule(static)
    for (size_t i = 0; i < size; i++) {
      result[i] = dis(gen);
    }
  }

  return result;

}

Matrix MultOpenMp(const Matrix &A,const Matrix &B){ 


  Matrix C(A.rows(),B.cols());

  size_t i,j,k;
  double localResult=0;
  
  if (A.cols() == B.rows()) {

    #pragma omp parallel for private(i,j,k,localResult)
    for (i = 0; i< C.cols(); ++i)
    {
      for (j = 0; j < C.cols(); ++j)
      {   
        for (k = 0; k < C.rows(); ++k)
        {
         localResult+= A(i,k) * B(k,j);
       }
       C(i,j)=localResult;
     }
   }

 }
 else
  throw std::invalid_argument("wrong dims!");

return C;
}

Matrix MultOpenMp2(const Matrix &A,const Matrix &B){ 


  Matrix C(A.rows(),B.cols());

  size_t i,j,k;
  
  if (A.cols() == B.rows()) {

    #pragma omp parallel for shared(A,B,C) private(i,j,k) schedule(guided)
    for (i = 0; i< C.cols(); ++i)
    {
      for (j = 0; j < C.cols(); ++j)
      {   
        for (k = 0; k < C.rows(); ++k)
        {
         C(i,j)+= A(i,k) * B(k,j);
        }
     }
   }

 }
 else
  throw std::invalid_argument("wrong dims!");

return C;
}


Matrix Matrix::operator*(const Matrix& matrix) {
  return MultOpenMp((*this), matrix);
}