#include "../include/similarity_modulelib.hpp"

SimilarityModule::SimilarityModule(){}
SimilarityModule::~SimilarityModule(){}


std::vector<std::vector<float>> SimilarityModule::matrix_multiplication(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B) {
  std::vector<std::vector<float>> C;
  for(int i = 0; i < A.size(); i++) {
    for(int i = 0; i < B[0].size(); i++) {
      C[i][j] = 0;
      for(int k = 0; k < B.size(); k++) {
       C[i][j] = C[i][j] + A[i][k] * B[k][j]; 
      }
    }
  }
  return C;
}

std::vector<std::vector<float>> SimilarityModule::transposed_matrix(std::vector<std::vector<float>> A) {
  std::vector<std::vector<float>> At;
  for(int i = 0; i < A.size(); i++) {
    for(int j = 0; j < A[0].size(); j++) {
      At[j][i] = A[i][j];
    }
  }
  return At;
}
