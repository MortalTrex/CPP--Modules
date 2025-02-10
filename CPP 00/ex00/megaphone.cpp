#include <iostream>

char up(char c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 32;
    return(c);
}

int main(int argc, char **argv)
{
    int i = 1;
    int j = 0;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while(argv[i])
        {
            j = 0;
            while (argv[i][j])
            {
                std::cout << up(argv[i][j]) ;
                j++;
            }
            i++;
        }
    }
    std::cout << '\n' ;
}