#pragma once

#if __cplusplus >= 202002L

    #include <format>
    namespace fmt
    {
        template<typename... _Args>
        void println(std::format_string<_Args...> __fmt, _Args&&... __args){
                std::cout << std::format(__fmt, __args...) << "\n";
        }
        template<typename... _Args>
        void print(std::format_string<_Args...> __fmt, _Args&&... __args){
                std::cout << std::format(__fmt, __args...);
        }


    };// namespace fmt
    
#endif