#pragma once
#include <iostream>
#include <time.h>

template<typename T>
void Swap(T* a, T* b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

/// <summary> Fisher-Yates Shuffle.</summary>
template<typename T>
void FYShuffle(T arr[], int size)
{
    srand(time(NULL));

    for (int i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        Swap(&arr[i], &arr[j]);
    }
}