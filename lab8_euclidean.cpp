#include <iostream>
#include <tuple>

int euclidean_gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    
    if (b == 0)
        return a;
        
    return euclidean_gcd(b, a % b);
}


std::tuple<int, int, int> extended_euclidean_gcd(int a, int b) {
    if (b == 0)
        return std::make_tuple(a, 1, 0);
        
    auto [gcd, x1, y1] = extended_euclidean_gcd(b, a % b);
    
    int x = y1;
    int y = x1 - (a / b) * y1;
    
    return std::make_tuple(gcd, x, y);
}

void show_euclidean_steps(int a, int b) {
    std::cout << "\nSteps for Euclidean Algorithm:\n";
    std::cout << "--------------------------------\n";
    
    int originalA = a;
    int originalB = b;
    
    a = std::abs(a);
    b = std::abs(b);
    
    int step = 1;
    
    while (b != 0) {
        int quotient = a / b;
        int remainder = a % b;
        
        std::cout << "Step " << step << ": ";
        std::cout << a << " = " << b << " * " << quotient << " + " << remainder << std::endl;
        
        a = b;
        b = remainder;
        step++;
    }
    
    std::cout << "GCD(" << originalA << ", " << originalB << ") = " << a << std::endl;
}

void show_extended_euclidean_steps(int a, int b) {
    std::cout << "\nSteps for Extended Euclidean Algorithm:\n";
    std::cout << "--------------------------------------\n";
    
    int originalA = a;
    int originalB = b;
    
    int a1 = a;
    int b1 = b;
    
    int x0 = 1, x1 = 0;
    int y0 = 0, y1 = 1;
    
    int step = 1;
    
    while (b1 != 0) {
        int quotient = a1 / b1;
        int remainder = a1 % b1;
        
        int tempX = x0 - quotient * x1;
        int tempY = y0 - quotient * y1;
        
        std::cout << "Step " << step << ": ";
        std::cout << a1 << " = " << b1 << " * " << quotient << " + " << remainder << std::endl;
        std::cout << "   x" << step << " = " << x0 << " - " << quotient << " * " << x1 << " = " << tempX << std::endl;
        std::cout << "   y" << step << " = " << y0 << " - " << quotient << " * " << y1 << " = " << tempY << std::endl;
        
        a1 = b1;
        b1 = remainder;
        
        x0 = x1;
        x1 = tempX;
        
        y0 = y1;
        y1 = tempY;
        
        step++;
    }
    
    std::cout << "GCD(" << originalA << ", " << originalB << ") = " << a1 << std::endl;
    std::cout << "Bezout's identity: " << originalA << " * " << x0 << " + " 
              << originalB << " * " << y0 << " = " << a1 << std::endl;
}

int main() {
    int a, b;
    
    std::cout << "Enter two integers to find their GCD using Euclidean algorithms:" << std::endl;
    std::cout << "First number (a): ";
    std::cin >> a;
    std::cout << "Second number (b): ";
    std::cin >> b;
    
    int gcd = euclidean_gcd(a, b);
    std::cout << "\nUsing Euclidean Algorithm:" << std::endl;
    std::cout << "GCD(" << a << ", " << b << ") = " << gcd << std::endl;
    
    show_euclidean_steps(a, b);
    
    auto [extGcd, x, y] = extended_euclidean_gcd(a, b);
    std::cout << "\nUsing Extended Euclidean Algorithm:" << std::endl;
    std::cout << "GCD(" << a << ", " << b << ") = " << extGcd << std::endl;
    std::cout << "Coefficients x and y such that " << a << " * " << x << " + " 
              << b << " * " << y << " = " << extGcd << std::endl;
    
    show_extended_euclidean_steps(a, b);
    
    std::cout << "\nVerification:" << std::endl;
    std::cout << a << " * " << x << " + " << b << " * " << y << " = " << (a * x + b * y) << std::endl;
    
    return 0;
}