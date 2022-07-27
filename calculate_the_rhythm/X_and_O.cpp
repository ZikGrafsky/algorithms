//
// Created by grafsky on 7/9/22.
//

#include <iostream>
#include <vector>

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

std::vector<std::string> fill(std::vector<std::string> tmp, std::string symbol, int number){
    while (number-- > 0){
        tmp.push_back(symbol);
    }
    return tmp;
}

std::string calculate(int biggest, int smaller, std::string biggest_sym, std::string smaller_sym){
    std::vector<std::string> tmp;

    tmp = fill(tmp, smaller_sym, smaller);
    tmp = fill(tmp, biggest_sym, biggest);
    //REALISATION
    return (tmp);
}

std::string getRythm(int x, int o){
    if (x > o){
        return (calculate(x, o, "x", "o"));
    }else
        return (calculate(o, x, "o", "x"));

}

int main(void){
    std::cout << getRythm(getParameter("x"), getParameter("o"));
}