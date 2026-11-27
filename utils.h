// utils.h
#pragma once
#include <random>
#include <type_traits>
#include <windows.h>
#include <iostream>

using  std::cout , std::endl;

namespace utils {

    template <typename T>
    auto make_distr(T& min, T& max) {
        if constexpr (std::is_integral_v<T>) {
            return std::uniform_int_distribution<T>(min, max);
        }
        else {
            return std::uniform_real_distribution<T>(min, max);
        }
    }

    //Utitlity engine for the random generation of fruits
    inline auto randomGenerator(auto min, auto max) {
        static thread_local std::mt19937 eng{ std::random_device{}() };
        auto distr = make_distr(min, max);
        return distr(eng);
    }

    //Move the cursor to the top-left corner instead of clearing the console.
    //The whole board is redrawn in place, which avoids flashing in the console.
    inline void ClearScreen()
    {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD topLeft = { 0, 0 };
        SetConsoleCursorPosition(console, topLeft);
    }


    //Splash screen
    inline void Loading()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << static_cast<char>(220);
            Sleep(200);
        }
        Sleep(10);
    }

} // namespace utils