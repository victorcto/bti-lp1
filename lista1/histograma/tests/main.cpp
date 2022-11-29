#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()
#include "test_manager.hpp"
#include "function.hpp"

using namespace std;
/*compare floats*/
bool f_equals(float a, float b)
{
    return fabs(a - b) < std::numeric_limits<float>::epsilon();
}

/*nâo modifique esses testes!*/
int main ( void )
{
    TestManager tm{ "Histograma template tests" };
    //== all_of

    std::cout<<"running tests"<<std::endl;

    {
        BEGIN_TEST( tm,"Histograma vazio", "Input: []; testa se funciona com vetor vazio;");

        auto result = histograma(std::vector<int>{});

        EXPECT_TRUE( result.empty() , "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }

    {
        BEGIN_TEST( tm,"Histograma vetor inteiros", "Input: [1 2 3 4 5 1 1 2 1 2]; testa se funciona com vetor de ints;");

        auto result = histograma(std::vector<int>{1,2,3,4,5,1,1,2,1,2});

        EXPECT_TRUE( (result == std::vector<std::pair<int, int>>{{1, 4}, {2, 3}, {3, 1}, {4, 1}, {5, 1}}) , "At tests/main.cpp line " + std::to_string(__LINE__));
    }

    {
        BEGIN_TEST( tm,"Histograma vetor char", "Input: [c b a f x z a f b y]; testa se funciona com vetor de char;");

        auto result = histograma(std::vector<char>{'c', 'b', 'a', 'f', 'x', 'z', 'a', 'f', 'b', 'y'});
        EXPECT_TRUE( (result == std::vector<std::pair<char, int>>{{'a', 2}, {'b', 2}, {'c', 1}, {'f', 2}, {'x', 1}, {'y', 1}, {'z', 1}}) , "At tests/main.cpp line " + std::to_string(__LINE__));
    }

    {
        BEGIN_TEST( tm,"Histograma vetor double/float" , "Input: [18.62 14.1 40.76 58.16 78.26 76.92 27.74]; testa se funciona com vetor de double/float;");

        auto result = histograma(std::vector<double>{18.62,14.1,40.76,58.16,78.26,76.92,27.74});
        EXPECT_TRUE( (result == std::vector<std::pair<double, int>>{{14.1, 1}, {18.62, 1}, {27.74, 1}, {40.76, 1}, {58.16, 1}, {76.92, 1}, {78.26, 1}}) , "At tests/main.cpp line " + std::to_string(__LINE__));
    }

    {
        BEGIN_TEST( tm,"Histograma vetor string" , "Input: [a2S2y U1vvZ 0nrwp GS8f5 VhPaB mWkK1 zNDfI BfTps vPTjE LmhcZ]; testa se funciona com vetor de strings;");

        auto result = histograma(std::vector<string>{"a2S2y", "U1vvZ", "0nrwp", "GS8f5", "VhPaB", "mWkK1", "zNDfI", "BfTps", "vPTjE", "LmhcZ"});
        EXPECT_TRUE((result == std::vector<std::pair<string, int>>{{"0nrwp", 1}, {"BfTps", 1}, {"GS8f5", 1}, {"LmhcZ", 1}, {"U1vvZ", 1}, {"VhPaB", 1}, {"a2S2y", 1}, {"mWkK1", 1}, {"vPTjE", 1}, {"zNDfI", 1}}) , "At tests/main.cpp line " + std::to_string(__LINE__));
    }


    tm.summary();
    std::cout << std::endl;
    //== Reverse
    return EXIT_SUCCESS;

}
