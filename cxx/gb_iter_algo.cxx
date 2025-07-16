#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <array>
#include <functional>

std::array<int,7> some{123, 4235 ,324, 714236, 723, 738, 99};
constexpr auto binary_code{std::to_array<int>({1,0,0,1,1,0,1,0,1,0,0,1,1,0,0,1,0,1,0})};

constexpr bool grater_than(const int a, const int b){
    return a > b;
}

constexpr bool zero(const int a){
    return a == 0;
}

template<typename T>
constexpr void print(const T& container){
    using std::cout;
    
    cout << "Container size:" << std::ssize(container) << "\nData:"; // std::ssize() - std20
    if(container.size() <= 0){
        cout << "N/A";
    }else{
        for(const auto&i : container){
            cout << '[' << i << ']';
        }
    }
    cout << "\n#######################################\n";
}

template<typename T>
constexpr void print_with_it(const T& container){
    using std::cout;
    
    cout << "Container size:" << std::ssize(container) << "\nData:"; // std::ssize() - std20
    if(container.size() <= 0){
        cout << "N/A";
    }else{
        for(auto it{container.begin()}; it != container.end(); it++){
            cout << '[' << *it << ']';
        }
    }
    cout << "\n#######################################\n";
}

int main(int argc, char** argv){
    using std::cout;
    using std::endl;

    std::cout << "some\n";
    print_with_it(some);
    std::sort(some.begin(), some.end(), grater_than);
    print(some);
    // the standard comparisos are classes so you have to put braces to make unnamed object
    // before cxx17 you have to define template type for less: std::less<int>{}
    std::sort(std::begin(some), std::end(some), std::less{}); 
    print(some);
    std::cout << std::setw(15) << "find 4235:" << std::ranges::find(some, 4235) << std::endl;
    std::cout << std::setw(15) << "find :" << std::ranges::find(some, 1) << std::endl;
    // the standard algorithm returns end() if they was faullty
    std::cout << std::setw(15) << "end of some:" << some.end() << std::endl;

    std::cout << "binary_code\n";
    print(binary_code);
    auto it(std::find(binary_code.begin(), binary_code.end(), 0));
    auto it_begin(binary_code.begin());
    auto it_diff(it - it_begin);
    std::cout << std::setw(15) << "begin:" << it_begin << std::endl;
    std::cout << std::setw(15) << "first zero:" << it << " value:" << *it << std::endl;
    std::cout << std::setw(15) << "ptrdiff:" << it_diff << std::endl;
    std::cout << std::setw(15) << "count if zero:" << std::ranges::count_if(binary_code, zero) << std::endl;;

    int c_style_array[]{0,1,2,3,4,5};
    cout << "\nc style array can be also used with range based for loop\n";
    // but it wount work if you pass array to function because it will decay to pointer
    // and range based for loop doesn't know anything about pointer and how mach memmory was allocated
    for(auto i: c_style_array){
        cout << '[' << i << ']';
    }
    cout << endl;
    cout << *std::ranges::find(c_style_array, 3) << endl;
    return 0;
}
