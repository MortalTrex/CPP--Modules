#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "\033[34mTesting too much increment or decrement:\033[0m" << std::endl;

    // Test too much increment or decrement
    try
    {
        Bureaucrat first = Bureaucrat("bureaucrat", 34);
        Form form = Form("important", false, 50, 50);
        
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }    
}