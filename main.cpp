#include "src/Application.hpp"
#include <iostream>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file_path>" << std::endl;
        return 1;
    }

    std::string filePath = argv[1];

    Application app;
    app.setParser(filePath);
    app.run();
    
    return 0;
}
