// Deterministic process outcomes for the desktop's failure/cancellation contract.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
int main(int argc, char** argv) {
    if (argc < 3) return 2;
    std::ifstream input(argv[1]);
    std::string mode;
    input >> mode;
    std::ofstream report(argv[2]);
    if (mode == "empty") return 0;
    report << "Model report\n";
    if (mode == "errors") report << "*ERR:123* invalid model\n";
    if (mode == "warnings") report << "*WRN:123* review this model\n";
    report.flush();
    if (mode == "stop") std::cout << "FEQ engine stopped: deliberate test\n" << std::flush;
    if (mode == "wait") {
        std::cout << "READY FOR CANCELLATION\n" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }
    return 0;
}
