#include "../include/purchase_history_modulelib.hpp"

PurchaseHistory::PurchaseHistory(int num_of_files, char **files, bool terminal) {
  quit_flag = false;
  PurchaseHistory::load_csv(num_of_files, files);
  if(terminal) PurchaseHistory::terminal_access();
}

PurchaseHistory::~PurchaseHistory(){}

void PurchaseHistory::load_csv(int num_of_files, char **files) {
  unsigned long int client_id = 0, product_id = 0;

  for (int current_file = 1; current_file <= num_of_files; current_file++) {
    std::ifstream file(files[current_file]);
    std::string line;
    if (!file.is_open()) {
      std::cerr << "Erro ao abrir arquivo: " << files[current_file] << std::endl;
      continue;
    }
    while (std::getline(file, line)) {
      std::stringstream current_line(line);
      std::string date, client_code, product_code, product_name;
      std::getline(current_line, date, ',');
      if(date == "DATA_COMPRA") continue;
      std::getline(current_line, client_code, ',');
      std::getline(current_line, product_code, ',');
      std::getline(current_line, product_name);
      if (map_client_code_to_id.find(client_code) == map_client_code_to_id.end()){
        map_client_code_to_id[client_code] = client_id;
        map_client_id_to_client_code[client_id] = client_code;
        purchase_history.push_back(std::list<int>());
        all_clients_codes.push_back(client_code);
        client_id++;
      }
      if (map_product_code_to_id.find(product_code) == map_product_code_to_id.end()) {
        map_product_code_to_id[product_code] = product_id;
        map_product_id_to_product[product_id] = product_code;
        all_products_names.push_back(product_name);
        all_products_codes.push_back(product_code);
        product_id++;
      }
      int client_id_key = map_client_code_to_id[client_code];
      int product_code_key = map_product_code_to_id[product_code];
      purchase_history[client_id_key].push_back(product_code_key);
    }
  }
}

std::string PurchaseHistory::get_client_code_by_id(int client_id) {
  return map_client_id_to_client_code[client_id];
}

std::string PurchaseHistory::get_product_code_by_id(int product_id) {
  return map_product_id_to_product[product_id];
}

int PurchaseHistory::get_product_id_by_product_code(std::string product) {
  return map_product_code_to_id[product];
}

int PurchaseHistory::get_client_id_by_client_code(std::string client) {
  return map_client_code_to_id[client];
}

std::unordered_map<int,int> PurchaseHistory::get_purchased_items_from_client(int client_id) {
  std::unordered_map<int,int> product_count;
  for(int product : purchase_history[client_id]) {
    product_count[product]++;
  }
  return product_count;
}

std::vector<std::list<int>> PurchaseHistory::get_client_purchase_history() {
  return purchase_history;
}

int PurchaseHistory::get_products_size() {
  return ((int)all_products_codes.size());
}

void PurchaseHistory::terminal_access() {
  int option_choosen;
  int id;
  int num_of_clients;
  do {
    option_choosen = 0;
    id = 0;
    std::cout << "\033[2J\033[H"; // limpa terminal
    std::cout << "<=== PurchaseHistoryModule Menu           ===>" << std::endl;
    std::cout << "<===      Choose an option                ===>" << std::endl;
    std::cout << "<=   1 -> Get clients purchased items       =>" << std::endl;
    std::cout << "<=   2 -> Get client code by id             =>" << std::endl;
    std::cout << "<=   3 -> Get product code by id            =>" << std::endl;
    std::cout << "<=   4 -> Quit                              =>" << std::endl;
    std::cin >> option_choosen;

    switch(option_choosen) {
      case 1: {
                do{
                  std::cout << "How many clients do you want to see the items?: ";
                  std::cin >> num_of_clients;
                  if (num_of_clients < 3) std::cout << "Chose at least 3 clients" << std::endl;
                } while(num_of_clients < 3);
                std::vector <std::string> ids;
                std::string original_code;
                auto all_purchase_history = get_client_purchase_history();
                for (int i = 0; i < num_of_clients; i++){
                  std::cout << "Type the client ID " << i + 1 << ": ";
                  std::cin >> original_code;
                  ids.push_back(original_code);
                }
                for (std::string current_code : ids) {
                  int client_id = get_client_id_by_client_code(current_code);
                  
                  std::cout << "Client " << current_code << " purchased: " << std::endl;
                  std::list<int> client_history = all_purchase_history[client_id];
                  for (int product_id : client_history){
                    std::string product_name = all_products_names[product_id];
                    std::cout << product_name << "\n";
                  }
                  std::cout << std::endl;

                }
                sleep(3);
              }
              break;

      case 2: {
                std::cout << "<===      Choose an option      ===>" << std::endl;
                std::cout << "<===    Type the client's id    ===>" << std::endl;
                std::cin >> id;
                std::cout << PurchaseHistory::get_client_code_by_id(id) << std::endl;
                sleep(3);
              }
              break;

      case 3: {
                std::cout << "<===      Choose an option      ===>" << std::endl;
                std::cout << "<===   Type the product's id    ===>" << std::endl;
                std::cin >> id;
                std::cout << PurchaseHistory::get_product_code_by_id(id) << std::endl;
                sleep(3);
              }
              break;

      case 4:
              quit_flag = true;
              break;
      default:{
                std::cout << "Invalid Option!" << std::endl;
              }
              break;
    }


  } while(quit_flag == false);


}
