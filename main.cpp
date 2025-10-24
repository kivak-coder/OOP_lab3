
#include "include/figures.hpp"
#include <iostream>
#include <vector>

int main() {
    std::vector<Figure*> figures;
    int choice;
    
    do {
        std::cout << "1. Add Triangle\n";
        std::cout << "2. Add Square\n";
        std::cout << "3. Add Rectangle\n";
        std::cout << "4. Print all figures info\n";
        std::cout << "5. Calculate total area\n";
        std::cout << "6. Remove figure by index\n";
        std::cout << "7. Exit\n";
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                Triangle* triangle = new Triangle();
                std::cout << "Enter 3 vertices for triangle (x y for each vertex):\n";
                std::cin >> *triangle;
                figures.push_back(triangle);
                std::cout << "Triangle added !\n";
                break;
            }
            case 2: {
                Square* square = new Square();
                std::cout << "Enter 4 vertices for square (x y):\n";
                std::cin >> *square;
                figures.push_back(square);
                std::cout << "Square added!\n";
                break;
            }
            case 3: {
                Rectangle* rectangle = new Rectangle();
                std::cout << "Enter 4 vertices for rectangle (x y):\n";
                std::cin >> *rectangle;
                figures.push_back(rectangle);
                std::cout << "Rectangle added\n";
                break;
            }
            case 4:
                if (figures.empty()) {
                    std::cout << "Array is clean.\n";
                } else {
                    printAllFiguresInfo(figures);
                }
                break;
            case 5:
                if (figures.empty()) {
                    std::cout << "No figures in the array.\n";
                } else {
                    double totalArea = calculateTotalArea(figures);
                    std::cout << "Total area of all figures: " << totalArea << "\n";
                }
                break;
            case 6: {
                if (figures.empty()) {
                    std::cout << "No figures to remove.\n";
                } else {
                    size_t index;
                    std::cout << "Enter index to remove (0-" << figures.size()-1 << "): ";
                    std::cin >> index;
                    removeFigureByIndex(figures, index);
                    std::cout << "Figure removed successfully!\n";
                }
                break;
            }
            case 7:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 7);
    
    for (auto figure : figures) {
        delete figure;
    }
    
    return 0;
}
