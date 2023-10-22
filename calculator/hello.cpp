#include <iostream>
#include <cmath>
#include <vector>

void printUsage() {
    std::cout << "Использование: calculator -o операция операнд1 операнд2 ..." << std::endl;
    std::cout << "Доступные операции:" << std::endl;
    std::cout << "  -o summa: Вычисление суммы заданных операндов" << std::endl;
    std::cout << "  -o vysota: Вычисление высоты баллистического полета" << std::endl;
    std::cout << "  -o dalnost: Вычисление дальности баллистического полета" << std::endl;
}

double summa(const std::vector<double>& operandy) {
    double result = 0;
    for (double operand : operandy) {
        result += operand;
    }
    return result;
}

double vysota(double uhol, double nach_skorost) {
    double g = 9.8; // Ускорение свободного падения в м/с^2
    double radiany = uhol * M_PI / 180; // Перевод угла из градусов в радианы
    double result = (pow(nach_skorost, 2) * pow(sin(radiany), 2)) / (2 * g);
    return result;
}

double dalnost(double uhol, double nach_skorost) {
    double radiany = uhol * M_PI / 180; // Перевод угла из градусов в радианы
    double result = (pow(nach_skorost, 2) * sin(2 * radiany)) / 9.8;
    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printUsage();
        return 0;
    }
    
    std::string operation = argv[1];
    
    if (operation == "-o summa") {
        std::vector<double> operandy;
        for (int i = 2; i < argc; i++) {
            double operand = std::stod(argv[i]);
            operandy.push_back(operand);
        }
        double result = summa(operandy);
        std::cout << "Сумма: " << result << std::endl;
    } 
    else if (operation == "-o vysota") {
        double uhol = std::stod(argv[2]);
        double nach_skorost = std::stod(argv[3]);
        double result = vysota(uhol, nach_skorost);
        std::cout << "Высота: " << result << " м" << std::endl;
    } 
    else if (operation == "-o dalnost") {
        double uhol = std::stod(argv[2]);
        double nach_skorost = std::stod(argv[3]);
        double result = dalnost(uhol, nach_skorost);
        std::cout << "Дальность: " << result << " м" << std::endl;
    } 
    else {
        std::cout << "Неизвестная операция: " << operation << std::endl;
        printUsage();
        return 0;
    }
    
    return 0;
}
