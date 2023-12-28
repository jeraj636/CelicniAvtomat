#ifndef CELICNIAVTOMAT_H
#define CELICNIAVTOMAT_H
#include <iostream>
#include <cstdlib>
#include <cstring>
class CelicniAvtomat
{
public:
    CelicniAvtomat(int x, int y, unsigned int seed, int MinProcentZa0)
    {
        x++;
        y++;
        tab = new char[x * y];
        m_x = x;
        m_y = y;
        srand(seed);
        for (int i = 0; i < m_y; i++)
        {
            for (int j = 0; j < m_x; j++)
            {
                int v = rand() % 100;
                if (v > MinProcentZa0)
                    tab[i * m_x + j] = '0';
                else
                    tab[i * m_x + j] = '1';
            }
        }
    }
    ~CelicniAvtomat()
    {
        delete[] tab;
    }
    float Procent()
    {
        float vsota = 0;
        for (int i = 0; i < m_y; i++)
        {
            for (int j = 0; j < m_x; j++)
            {
                if (tab[i * m_x + j] == '1')
                    vsota++;
            }
        }
        return vsota / (m_x * m_y) * 100;
    }
    friend std::ostream &operator<<(std::ostream &os, const CelicniAvtomat &m)
    {
        for (int i = 1; i < m.m_y - 1; i++)
        {
            for (int j = 1; j < m.m_x - 1; j++)
            {
                if (m.tab[i * m.m_x + j] == '1')
                    os << ' ';
                else
                    os << m.tab[i * m.m_x + j];
            }
            os << "\n";
        }
        return os;
    }
    void Sim()
    {
        char *nov = new char[m_x * m_y];

        memcpy(nov, tab, m_x * m_y * sizeof(char));
        for (int i = 1; i < m_y - 1; i++)
        {
            for (int j = 1; j < m_x - 1; j++)
            {

                int nicle = 0;

                if (nov[(i - 1) * m_x + (j - 1)] == '0')
                    nicle++;
                if (nov[(i - 1) * m_x + j] == '0')
                    nicle++;
                if (nov[(i - 1) * m_x + (j + 1)] == '0')
                    nicle++;
                if (nov[i * m_x + (j - 1)] == '0')
                    nicle++;
                if (nov[i * m_x + (j + 1)] == '0')
                    nicle++;
                if (nov[(i + 1) * m_x + (j - 1)] == '0')
                    nicle++;
                if (nov[(i + 1) * m_x + j] == '0')
                    nicle++;
                if (nov[(i + 1) * m_x + (j + 1)] == '0')
                    nicle++;
                if (nov[i * m_x + j] == '0')
                    nicle++;

                if (nicle >= 5)
                    tab[i * m_x + j] = '0';
                else
                    tab[i * m_x + j] = '1';
            }
        }
        delete[] nov;
    }
    char &at(int x, int y)
    {
        return tab[y * m_x + x];
    }
    char *GetTab()
    {
        return tab;
    }
    int getX()
    {
        return m_x;
    }
    int getY()
    {
        return m_y;
    }

private:
    char *tab;
    int m_x, m_y;
};
#endif