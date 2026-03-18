#include "../include/similarity_modulelib.hpp"

SimilarityModule::SimilarityModule(int qnt_products, std::vector<std::list<int>> purchase_vector){
  purchase_matrix = SimilarityModule::set_purchase_matrix(qnt_products, purchase_vector);
  purchase_matrix_transposed = SimilarityModule::set_transposed_matrix(purchase_matrix);
  intersection_matrix = SimilarityModule::set_intersection_matrix(purchase_matrix);
  similarity_matrix = SimilarityModule::set_similarity_matrix(intersection_matrix);
}

SimilarityModule::~SimilarityModule(){}

std::vector<std::vector<float>> SimilarityModule::matrix_multiplication(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B) {
  std::vector<std::vector<float>> C = std::vector<std::vector<float>>(A.size(), std::vector<float>(B[0].size(), 0.0));

  for(unsigned int i = 0; i < A.size(); i++) {
    for(unsigned int j = 0; j < B[0].size(); j++) {
      C[i][j] = 0;
      for(unsigned int k = 0; k < B.size(); k++) {
        C[i][j] = C[i][j] + A[i][k] * B[k][j]; 
      }
    }
  }
  return C;
}

std::vector<std::vector<float>> SimilarityModule::set_transposed_matrix(std::vector<std::vector<float>> A) {
  std::vector<std::vector<float>> At =  std::vector<std::vector<float>>(A[0].size(), std::vector<float>(A.size(), 0.0));
  for(unsigned int i = 0; i < A.size(); i++) {
    for(unsigned int j = 0; j < A[0].size(); j++) {
      At[j][i] = A[i][j];
    }
  }
  return At;
}


void SimilarityModule::show_matrix(std::vector<std::vector<float>> matrix) {
  std::cout << std::endl;
  for(unsigned int i = 0; i < matrix.size(); i++) {
    for(unsigned int j = 0; j < matrix[0].size(); j++) {
      std::cout << matrix[i][j] << " "; 
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

std::vector<std::vector<float>> SimilarityModule::set_purchase_matrix(int qnt_products, std::vector<std::list<int>> purchase_vector) {
  std::vector<std::vector<float>> matrix = std::vector<std::vector<float>>(purchase_vector.size(), std::vector<float>(qnt_products, 0.0));

  for(unsigned int i = 0; i < purchase_vector.size(); i++) {
    for(unsigned int product : purchase_vector[i]) {
      matrix[i][product] = 1;
    }
  }
  return matrix;
}

std::vector<std::vector<float>> SimilarityModule::set_intersection_matrix(std::vector<std::vector<float>> matrix) {
  std::vector<std::vector<float>> return_matrix = SimilarityModule::matrix_multiplication(matrix, SimilarityModule::set_transposed_matrix(matrix));
  return return_matrix;
}

std::vector<std::vector<float>> SimilarityModule::set_similarity_matrix(std::vector<std::vector<float>> intersection_matrix) {
  std::vector<std::vector<float>> return_matrix = std::vector<std::vector<float>>(intersection_matrix.size(), std::vector<float>(intersection_matrix[0].size(), 0.0));
  for(unsigned int i = 0; i < return_matrix.size(); i++) {
    for(unsigned int j = 0; j < return_matrix[0].size(); j++) {
      if(intersection_matrix[i][i] == 0) {
        return_matrix[i][j] = 1;
      } else {
        return_matrix[i][j] = 1 - (intersection_matrix[i][j] / intersection_matrix[i][i]);
      }
    }
  }
  return return_matrix;
}

std::vector<int> SimilarityModule::get_most_similar_client(int client_code) {
  float min_similarity = 1.0;
  std::vector<int> same_similarity_clients;
  for(int i = 0; i < similarity_matrix.size(); i++) {
    if(i == client_code) continue;
    if(similarity_matrix[client_code][i] < min_similarity) {
      min_similarity = similarity_matrix[client_code][i];
    }
  }
  for(int i = 0; i < similarity_matrix.size(); i++) {
    if(similarity_matrix[client_code][i] == min_similarity) 
      same_similarity_clients.push_back(i);
  }
  return same_similarity_clients;
}

std::vector<std::vector<float>> SimilarityModule::get_purchase_matrix() {
  return purchase_matrix;
}

std::vector<std::vector<float>> SimilarityModule::get_purchase_matrix_transposed() {
  return purchase_matrix_transposed;
}

std::vector<std::vector<float>> SimilarityModule::get_intersection_matrix() {
  return intersection_matrix;
}

std::vector<std::vector<float>> SimilarityModule::get_similarity_matrix() {
  return similarity_matrix;
}
