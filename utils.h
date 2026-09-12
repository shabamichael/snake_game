// utils.h
#pragma once
#include <random>
#include <type_traits>
#include <windows.h>
#include <iostream>

using namespace std;

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

    inline auto randomGenerator(auto min, auto max) {
        static thread_local std::mt19937 eng{ std::random_device{}() };
        auto distr = make_distr(min, max);
        return distr(eng);
    }

    inline void ClearScreen()
    {
        system("cls");
        /*
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD home = { 0, 0 };
        SetConsoleCursorPosition(hOut, home);

        CONSOLE_CURSOR_INFO info;
        GetConsoleCursorInfo(hOut, &info);
        info.bVisible = FALSE;
        SetConsoleCursorInfo(hOut, &info);
        */
    }

    inline void Loading()
    {
		cout  <<"Welcome to Snake Game!" << endl;
        cout << endl;
        cout << "Loading... ";
        for (int i = 0; i < 20; i++)
        {
            cout << static_cast<char>(254);
            Sleep(200);
        }
        Sleep(500);
    }

} // namespace utils