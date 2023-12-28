## Primer uporabe
```
#include "CelicniAvtomat.h"

int main()
{
    int x;
    while (true)
    {
        std::cin >> x;
        CelicniAvtomat m(370, 100, time(NULL), 53);
        for (int i = 0; i < 500; i++)
            m.Sim();
        std::cout << m << "\n"
                  << m.Procent() << "\n";
    }
}
```
