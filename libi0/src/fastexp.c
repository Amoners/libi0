#include "fastexp.h"

// modifed version from http://www.chokkan.org/software/dist/fastexp.c.html
double exp_remez13_05_05(double value)
{
    long n;
    double a, px, x;
    double d;

    // putchar('D');putdouble(value);wrln();

    x = value;

    /* n = round(x / log 2) */
    a = LOG2E * x + 0.5;
    // n = (int)a;
    n = (long)a;
    // n -= (a < 0);
    if (a < 0) n = n - 1;

    // putchar('D');putlong(n);wrln();

    /* x -= n * log2 */
    px = (double)n;
    x = x - px * C1;
    x = x - px * C2;

    /* Compute e^x using a polynomial approximation. */
    a = 1.61356848991757396195626449324190427883666354504187e-10;
    a = a * x;
    a = a + 2.09773502429720720042832865218235470540902290986604e-9;
    a = a * x;
    a = a + 2.50517997973487340520345973228530569065189960125308e-8;
    a = a * x;
    a = a + 2.7556973177905466877853160305636358948188615327725e-7;
    a = a * x;
    a = a + 2.7557319860870868162733628841564031959051602041504e-6;
    a = a * x;
    a = a + 2.48015878916569323181318984106104816451563207545696e-5;
    a = a * x;
    a = a + 1.98412698405602139306149764767811806786694849547848e-4;
    a = a * x;
    a = a + 1.38888888883724638191056667131613472090590184962952e-3;
    a = a * x;
    a = a + 8.333333333333743243093579329746662890641071879753e-3;
    a = a * x;
    a = a + 4.16666666666688187524214985734081300874557496783939e-2;
    a = a * x;
    a = a + 0.16666666666666665609766712753641211515446088211247;
    a = a * x;
    a = a + 0.49999999999999996637019704330727593814705189927683;
    a = a * x;
    a = a + 1.00000000000000000008007233620462705038544342452684;
    a = a * x;
    a = a + 1.0000000000000000000857966908786376708355989802095;

    // putchar('D');putdouble(a);wrln();

    // build 2^n in double.
    // d = 0;
    // n = n + 1023;
    // // u.s[3] = (unsigned short)((n << 4) & 0x7FF0);
    // n = (n * 16) & 0x7FF0;
    // // n = n << 16
    // n = n * 0x10000;
    // *((long*)&d) = n;

    n = ipow(2, n);
    d = (double)n;

    // putchar('D');putdouble(d);wrln();

    return a * d;
}
