#pragma once
#include <iostream>
#include <string>


typedef std::string string;
#define d 4

/* pat -> pattern
    txt -> text
    q -> A prime number
*/
//Rabin-Karp
/// <summary>Find P in S and return the first index.</summary>
int RKSearch(string txt, string pat)
{
    int q = INT_MAX; // a prime number
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++) 
    {
        if (i > 0)
        {
            if (i - 1 < N - M) 
            {
                t = (d * (t - txt[i - 1] * h) + txt[i + M - 1]) % q;

                if (t < 0)
                    t = (t + q);
            }
        }

        if (p == t)
        {
            for (j = 0; j < M; j++)
                if (txt[i + j] != pat[j])
                    break;

            if (j == M)
                return i;
        }
    }

    return 10001;
}