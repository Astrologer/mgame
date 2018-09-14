#include <iostream>


enum CommandType {
    TEST,
    CMD
};


int main(int argc, char *argv[]) {
    CommandType c = CMD;
    std::cout << c << "\n";
    return 0;
}
