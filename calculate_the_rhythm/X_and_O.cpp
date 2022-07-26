//
// Created by grafsky on 7/9/22.
//

#include <iostream>

int getParameter(std::string number_of){
    int tmp;

    std::cout   << "please, enter the number of " << number_of << std::endl;
    std::cin >> tmp;
    while (tmp <= 0){
        std::cout << "enter correct number of " << number_of << std::endl;
        std::cin >> tmp;
    }
    return (tmp);
}

std::string getOutBiggestXOrOs(std::string x_or_o, int number){
    std::string tmp = x_or_o;
    for (int i = 1; i < number; ++i) {
        tmp += x_or_o;
    }
    return (tmp);
}

void print(std::string symbol, int number){
    while (number-- > 0){
        std::cout << symbol;
    }
}

void calculate(int biggest, int smaller, std::string biggest_sym, std::string smaller_sym){
    int tmp = smaller;
    while (tmp > 0){
        print(smaller_sym, 1);
        print(biggest_sym, (biggest / smaller));
        tmp--;
        if (biggest % smaller != 0 && tmp > 0){
            print(smaller_sym, 1);
            print(biggest_sym, (biggest % smaller));
            tmp--;
        }
    }
}

void getRythm(int x, int o){
    if (x > o){
        calculate(x, o, "x", "o");
    }else
        calculate(o, x, "o", "x");

}

int main(void){
    getRythm(getParameter("x"), getParameter("o"));
}