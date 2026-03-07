#include <fstream>
#include <sstream>
#include <string>
#include <iostream>



void load_csv(int num, char **file) {
  for(int i = 0; i < num-1; i++) { 
    std::string path_file = "../../sales_data/" + std::string(file[i+1]) + ".csv";
    std::ifstream arquivo(path_file);
    std::string linha;

    if (!arquivo.is_open()) {
      std::cout << "Erro ao abrir: " << path_file << std::endl;
      continue;
    }

    while (std::getline(arquivo, linha)) {

      std::stringstream ss(linha);
      std::string data, cliente, produto, nome;

      std::getline(ss, data, ','); // data da compra
      std::getline(ss, cliente, ','); //codigo de cliente
      std::getline(ss, produto, ','); // codiog de produto
      std::getline(ss, nome); // nome do produto

    }
  }



}


int main (int argc, char **argv) {

  load_csv(argc, argv);
  return 0;



}

