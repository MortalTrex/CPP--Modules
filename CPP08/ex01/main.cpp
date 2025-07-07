#include "Span.hpp"
#define MAX_VAL 10000

int main()
{
    srand(time(NULL));
    try {
        Span sp = Span(5);
    
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(11);
        std::cout << "------------------" << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    
        // My Test
         // INSERT LOT VALUES
        Span maxVal = Span(MAX_VAL);
        for (int i = 0; i < MAX_VAL; i++)
        {
            maxVal.addNumber(rand());
        }
        std::cout << "------------------" << std::endl;
        std::cout << maxVal.shortestSpan() << std::endl;
        std::cout << maxVal.longestSpan() << std::endl;
    
        // TEST ADDNUMBER SPAN
        Span spanVal = Span(5);
        int nb[5] = { 4, 3, 5 , 48, 10 };
        std::vector<int> numbers( nb, nb + 5 );
        spanVal.addNumber(numbers.begin(), numbers.end());
        std::cout << "------------------" << std::endl;
        std::cout << spanVal.shortestSpan() << std::endl;
        std::cout << spanVal.longestSpan() << std::endl;
        std::cout << "------------------" << std::endl;
        
        // TEST COPY
        Span copy = Span(spanVal);
        std::cout << "------COPY---------" << std::endl;
        std::cout << copy.shortestSpan() << std::endl;
        std::cout << copy.longestSpan() << std::endl;
        std::cout << "------------------" << std::endl;
        copy = sp;
        std::cout << "------COPY---------" << std::endl;
        std::cout << copy.shortestSpan() << std::endl;
        std::cout << copy.longestSpan() << std::endl;
        std::cout << "------------------" << std::endl;
    } catch (const std::exception& e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}