//
// Created by grafsky on 7/26/22.
//
#include <iostream>

int getParameter(std::string number_of){
    int tmp;

    std::cout   << "please, enter " << number_of << " digit: ";
    std::cin >> tmp;
    return (tmp);
}

int main(){
    int m, n, r;
    m = getParameter("first");
    n = getParameter("second");
    std::cout   << "greatest common divisor (наибольший общий делитель) for "
                << m << " and " << n;
    r = m % n;
    while (true) {
        if (r == 0)
            break;
        m = n;
        n = r;
        r = m % n;
    }
    std::cout << ": " << n;
}