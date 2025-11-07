#pragma once
#include <iostream>

class Base {
public:
    static int people_on_base;
    static int vehicles_on_base;
    static double petrol_on_base;
    static double goods_on_base;

    static void Init(int people, int vehicles, double petrol, double goods);
    static void PrintStatus();
};