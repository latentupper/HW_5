#include <iostream>
#include <filesystem>
#include <fstream>

int main() {
    std::filesystem::path parent_dir{".."};
    std::filesystem::path dir{"processed"};
    std::filesystem::create_directory(parent_dir/dir);
    std::ifstream file_in{"../gitar.txt"};
    std::ofstream c_out{"../processed/c.txt"};
    std::ofstream even_out{"../processed/even.txt"};
    std::ofstream odd_out{"../processed/odd.txt"};
    for(std::string word; file_in >> word;) {
        bool c_exists = false;
        int quantity = 0;
        for(auto& u : word) {
            quantity++;
            u = std::tolower(u);
            if(u == 'c') {
                c_exists = true;
                u = std::toupper(u);
            }
        }
        if(c_exists) {
            c_out << word << std::endl;
        } else if(quantity%2 == 0) {
            word.push_back('_');
            std::string q = std::to_string(quantity);
            word.append(q);
            even_out << word << std::endl;
        } else {
            word.push_back('_');
            std::string q = std::to_string(quantity);
            word.append(q);
            odd_out << word << std::endl;
        }
    }
    file_in.close();
    c_out.close();
    odd_out.close();
    even_out.close();
    return 0;
}
