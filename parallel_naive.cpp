// parallel_naive.cpp
// Created by svalenti on 2/17/2020.
// 17-Feb-2020
// Galowicz 9307

#include <iostream>
#include <iomanip>
#include <thread>
#include <string>
#include <future>
#include <val/montecarlo/Chronology.h>

using namespace std;
using namespace chrono_literals;

static mutex cout_mutex;

static string create(const char* s)
{
    {
        lock_guard<mutex> l{cout_mutex};
        cout << "3s CREATE " << quoted(s) << '\n';
    }
    this_thread::sleep_for(3s);
    return {s};
}

static string concat(const string& a, const string& b)
{
    {
        lock_guard<mutex> l {cout_mutex};
        cout << "5s CONCAT " << quoted(a) << " " << quoted(b) << '\n';
    }
    this_thread::sleep_for(5s);
    return a + b;
}

static string twice(const string& s)
{
    {
        lock_guard<mutex> l {cout_mutex};
        cout << "3s TWICE " << quoted(s) << '\n';
    }
    this_thread::sleep_for(3s);
    return s + s;
}

int main()
{
    StopWatch s;
    auto a (async(launch::async, create, "foo "));
    auto b (async(launch::async, create, "bar "));
    auto c (async(launch::async, create, "this "));
    auto d (async(launch::async, create, "that "));
    auto e (async(launch::async, concat, a.get(), b.get()));
    auto f (async(launch::async, concat, c.get(), d.get()));
    auto g (async(launch::async, twice, e.get()));
    auto h (async(launch::async, concat, g.get(), f.get()));
    cout << h.get() << '\n';
    s.stop();
}