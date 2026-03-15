#include "../include/similarity_modulelib.hpp"

SimilarityModule::SimilarityModule(){}
SimilarityModule::~SimilarityModule(){}


std::vector<std::vector<float>> SimilarityModule::matrix_multiplication(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B) {
  std::vector<std::vector<float>> C = std::vector<std::vector<float>>(A.size(), std::vector<float>(B[0].size(), 0.0));

  for(int i = 0; i < A.size(); i++) {
    for(int j = 0; j < B[0].size(); j++) {
      C[i][j] = 0;
      for(int k = 0; k < B.size(); k++) {
        C[i][j] = C[i][j] + A[i][k] * B[k][j]; 
      }
    }
  }
  return C;
}

std::vector<std::vector<float>> SimilarityModule::transposed_matrix(std::vector<std::vector<float>> A) {
  std::vector<std::vector<float>> At =  std::vector<std::vector<float>>(A[0].size(), std::vector<float>(A.size(), 0.0));
  for(int i = 0; i < A.size(); i++) {
    for(int j = 0; j < A[0].size(); j++) {
      At[j][i] = A[i][j];
    }
  }
  return At;
}


void SimilarityModule::show_matrix(std::vector<std::vector<float>> matrix) {
  std::cout << std::endl;
  for(int i = 0; i < matrix.size(); i++) {
    for(int j = 0; j < matrix[0].size(); j++) {
      std::cout << matrix[i][j] << " "; 
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
