#pragma once

#include <functional>
#include <list>
#include <tuple>

template <typename T>
std::list<T> map(std::list<T> list, std::function<T(T)> func)
{
    std::list<T> result;
    for (T item : list)
    {
        result.push_back(func(item));
    }
    return result;
}

template <typename T>
std::list<T> filter(std::list<T> list, std::function<bool(T)> filt)
{
    std::list<T> result;
    for (T item : list)
    {
        if (filt(item))
        {
            result.push_back(item);
        }
    }
    return result;
}


template <typename T1, typename T2>
std::list<std::tuple<T1, T2>> zip(std::list<T1> list1, std::list<T2> list2)
{
    typename std::list<T1>::iterator iter1 = list1.begin();
    typename std::list<T1>::iterator iter2 = list2.begin();
    std::list<std::tuple<T1, T2>> result;

    while (iter1 != list1.end() && iter2 != list2.end())
    {
        std::tuple<T1, T2> tup(*iter1++, *iter2++);
        result.push_back(tup);
    }
    return result;
}

