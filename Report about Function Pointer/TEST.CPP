#include <iostream>
#include <functional>
//typedef bool (*validate)(int);

void func()
{
    std::cout << "hello" << std::endl;
    return;
}

void func_year(int year)
{
    std::cout << "hello " << year << std::endl;
    return;
}

bool check_even(int x)
{
    if (x % 2 == 0)
        return true;
    return false;
}

bool check_odd(int x)
{
    if (x % 2 == 0)
        return false;
    return true;
}

//int add(int x, int y, validate check)
int add(int x, int y, bool (*check)(int))
{
    if (check(x + y))
        return x + y;
    return 0;
}

int main()
{
    void (*fp)();
    fp = func;
    fp = &func;
    void (*fpp)()(func);
    fp();
    fpp();

    int year = 2020;
    void (*fpy)(int){func_year};
    fpy(year);

    bool (*validate)(int);
    validate = check_odd;
    std::cout << add(1, 2, validate) << std::endl;
    validate = check_even;
    std::cout << add(1, 2, validate) << std::endl;

    /*
    bool (*check_func)(int);
    check_func = check_odd;
    std::cout << add(1, 2, check_func) << std::endl;
    check_func = check_even;
    std::cout << add(1, 2, check_func);
    //std::function<bool(int)> check_func;
    */
    return 0;
}