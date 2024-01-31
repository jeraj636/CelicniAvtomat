#ifndef CELICNIAVTOMAT_H
#define CELICNIAVTOMAT_H
#include <iostream>

#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <iomanip>

class CelicniAvtomat
{
public:
    ~CelicniAvtomat() { delete[] m_tab; }
    void Naredi(int x, int y, unsigned int seme)
    {
        srand(seme);
        x += 2;
        y += 2;
        m_tab = new char[x * y];
        m_x = x;
        m_y = y;

        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                m_tab[i * x + j] = rand() % 100;
            }
        }
        for (int i = 0; i < 22; i++)
            Sim();
        DajVrednosti();
        for (int i = 0; i < 9; i++)
            NarediOtoke();
        NarediPlazo();
        PopraviPlazo();
    }
    friend std::ostream &operator<<(std::ostream &os, CelicniAvtomat m)
    {

        for (int i = 1; i < m.m_y - 1; i++)
        {
            for (int j = 1; j < m.m_x - 1; j++)
            {
                os << m.m_tab[i * m.m_x + j];
            }
            os << "\n";
        }
        return os;
    }
    float pop()
    {
        float vsota = 0;
        for (int i = 1; i < m_y - 1; i++)
        {
            for (int j = 1; j < m_x - 1; j++)
            {

                if (m_tab[i * m_x + j] == ' ')
                    vsota++;
            }
        }
        return vsota / ((m_x - 2) * (m_y - 2)) * 100;
    }
    int GetX() { return m_x - 2; }
    int GetY() { return m_y - 2; }
    char &at(int x, int y) { return m_tab[(y + 1) * m_x + x + 1]; }
    char *GetTab() { return &m_tab[0]; }
    bool Trk(float pozx, float pozy, float velx, float vely, char c, int resx, int resy)
    {
        pozx /= resx / (m_x - 2);
        pozy /= resy / (m_y - 2);

        velx /= resx / (m_x - 2);
        vely /= resy / (m_y - 2);
        for (int i = pozy - vely / 2; i < pozy + vely / 2; i++)
        {
            for (int j = pozx - velx / 2; j < pozx + velx / 2; j++)
                if (m_tab[i * m_x + j] == c)
                    return true;
        }
        return false;
    }
    void Unici()
    {
        delete[] m_tab;
    }

private:
    void Sim()
    {

        char *nov = new char[m_x * m_y];

        memcpy(nov, m_tab, m_y * m_x * sizeof(char));

        for (int i = 1; i < m_y - 1; i++)
        {
            for (int j = 1; j < m_x - 1; j++)
            {
                int pop = 0;
                pop += nov[i * m_x + j];
                pop += nov[(i - 1) * m_x + j - 1];
                pop += nov[(i - 1) * m_x + j + 1];
                pop += nov[(i - 1) * m_x + j];
                pop += nov[(i + 1) * m_x + j - 1];
                pop += nov[(i + 1) * m_x + j];
                pop += nov[(i + 1) * m_x + j + 1];
                pop += nov[i * m_x + j - 1];
                pop += nov[i * m_x + j + 1];
                m_tab[i * m_x + j] = pop / 9;
            }
        }
        delete[] nov;
    }
    void DajVrednosti()
    {
        for (int i = 1; i < m_y - 1; i++)
        {
            for (int j = 1; j < m_x - 1; j++)
            {

                if (m_tab[i * m_x + j] > 41)
                {
                    m_tab[i * m_x + j] = '0';
                }
                else
                {
                    m_tab[i * m_x + j] = ' ';
                }
            }
        }
    }
    void NarediOtoke()
    {
        for (int i = 1; i < m_y - 1; i++)
        {
            for (int j = 1; j < m_x - 1; j++)
            {
                if (m_tab[i * m_x + j] == '0')
                {
                    int stTrave = 0;
                    if (m_tab[i * m_x + j - 1] == '0')
                        stTrave++;
                    if (m_tab[i * m_x + j + 1] == '0')
                        stTrave++;
                    if (m_tab[(i - 1) * m_x + j - 1] == '0')
                        stTrave++;
                    if (m_tab[(i - 1) * m_x + j + 1] == '0')
                        stTrave++;
                    if (m_tab[(i - 1) * m_x + j] == '0')
                        stTrave++;
                    if (m_tab[(i + 1) * m_x + j - 1] == '0')
                        stTrave++;
                    if (m_tab[(i + 1) * m_x + j] == '0')
                        stTrave++;
                    if (m_tab[(i + 1) * m_x + j + 1] == '0')
                        stTrave++;
                    if (stTrave < 4)
                    {
                        m_tab[i * m_x + j] = ' ';
                    }
                }
            }
        }
    }
    void NarediPlazo()
    {
        for (int i = 1; i < m_y - 1; i++)
        {
            for (int j = 1; j < m_x - 1; j++)
            {
                if (m_tab[i * m_x + j] == '0')
                {
                    int stMorij = 0;
                    if (m_tab[i * m_x + j - 1] == ' ')
                        stMorij++;
                    if (m_tab[i * m_x + j + 1] == ' ')
                        stMorij++;
                    if (m_tab[(i - 1) * m_x + j - 1] == ' ')
                        stMorij++;
                    if (m_tab[(i - 1) * m_x + j + 1] == ' ')
                        stMorij++;
                    if (m_tab[(i - 1) * m_x + j] == ' ')
                        stMorij++;
                    if (m_tab[(i + 1) * m_x + j - 1] == ' ')
                        stMorij++;
                    if (m_tab[(i + 1) * m_x + j] == ' ')
                        stMorij++;
                    if (m_tab[(i + 1) * m_x + j + 1] == ' ')
                        stMorij++;
                    if (stMorij > 0)
                    {
                        m_tab[i * m_x + j] = '.';
                    }
                }
            }
        }
    }
    void PopraviPlazo()
    {
        for (int i = 1; i < m_y - 1; i++)
        {
            for (int j = 1; j < m_x - 1; j++)
            {
                if (m_tab[i * m_x + j] == '.')
                {
                    int stTrave = 0;
                    if (m_tab[i * m_x + j - 1] == '0')
                        stTrave++;
                    if (m_tab[i * m_x + j + 1] == '0')
                        stTrave++;
                    if (m_tab[(i - 1) * m_x + j - 1] == '0')
                        stTrave++;
                    if (m_tab[(i - 1) * m_x + j + 1] == '0')
                        stTrave++;
                    if (m_tab[(i - 1) * m_x + j] == '0')
                        stTrave++;
                    if (m_tab[(i + 1) * m_x + j - 1] == '0')
                        stTrave++;
                    if (m_tab[(i + 1) * m_x + j] == '0')
                        stTrave++;
                    if (m_tab[(i + 1) * m_x + j + 1] == '0')
                        stTrave++;

                    if (stTrave == 0)
                    {
                        m_tab[i * m_x + j] = ' ';
                    }
                }
            }
        }
    }
    char *m_tab;

    int m_x, m_y;
};
#endif