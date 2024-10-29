#include <vector>
#include <iostream>

int main(){

    std::cout << "----min----" << "\n";
    std::cout << std::min<double>(2, 3) << "\n";
    std::cout << std::min<const char*>("abc", "def") << "\n";


    std::cout << "----vector----" << "\n";
    std::vector<int> v {1, 2, 3};
    v.push_back(4);
    for(const auto e: v){
        std::cout << e << "\n";
    }
}
