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

std::vector<std::string> fill(std::vector<std::string> tmp, std::string symbol, int number){
    while (number-- > 0){
        tmp.push_back(symbol);
    }
    return tmp;
}

std::vector<std::string> add_on_side(std::vector<std::string> tmp, std::string symbols, int number){
    for (int i = 0; i < number; ++i) {
        tmp[i] = tmp[i] + symbols;
    }
    return tmp;
}

std::string calculate(int biggest, int smaller, std::string biggest_sym, std::string smaller_sym){
    std::vector<std::string>    tmp;
    int                         lines, temp_int, counter;

    tmp = fill(tmp, smaller_sym, smaller);
    tmp = fill(tmp, biggest_sym, biggest);
    temp_int = 0;
    lines = biggest + smaller;
    while (lines != 1){
        counter = (lines - smaller)/smaller;
                std::cout << "smaller: " << smaller << std::endl << "biggest: " << biggest << std::endl
                << "counter: "<< counter << std::endl
                << "lines: "<< lines << std::endl
                << "temp_int: "<< temp_int << std::endl
                << tmp[0] << std::endl
                << "__________________" << std::endl;
        for (int i = counter; i > 0; i--) {
            tmp = add_on_side(tmp, tmp[lines - 1], smaller);
            lines -= smaller;
        }
        temp_int = smaller;
        smaller = biggest - temp_int * counter;
        biggest = temp_int;
        lines = biggest + smaller;
    }
    tmp = add_on_side(tmp, tmp[lines - 1], smaller);
    return (tmp[0]);
}
//        std::cout << lines << std::endl << counter << std::endl;

std::string getRythm(int x, int o){
    if (x > o){
        return (calculate(x, o, "x", "o"));
    }else
        return (calculate(o, x, "o", "x"));

}

int main(void){
    std::cout << getRythm(getParameter("x"), getParameter("o"));
}