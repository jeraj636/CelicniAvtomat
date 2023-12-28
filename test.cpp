#include "CelicniAvtomat.h"

int main()
{
    int x;
    while (true)
    {
        std::cin >> x;
        CelicniAvtomat m(250, 60, time(NULL), 52);
        for (int i = 0; i < 500; i++)
            m.Sim();
        m.NarediMorje();
        m.NarediMorje();
        m.PopraviMorje();
        m.PopraviMorje();
        std::cout << m << "\n"
                  << m.Procent() << "\n";
    }
}