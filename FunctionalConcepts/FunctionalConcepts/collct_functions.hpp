#pragma once

#include <functional>


template <typename Titem, template <typename, typename> typename Tcollect, typename Allocator>
Tcollect<Titem, Allocator> map(Tcollect <Titem, Allocator> collect, std::function < Titem(Titem)> func)
{
    Tcollect<Titem, Allocator> result;
    for (auto item : collect)
    {
        result.push_back(func(item));
    }
    return result;
}

template <typename T1, typename T2, template <typename, typename> typename Tcollect, typename Allocator>
Tcollect<std::tuple<T1, T2>, Allocator> zip(Tcollect<T1, Allocator> collect1, Tcollect<T2, Allocator> collect2)
{
    typename Tcollect<T1, Allocator>::iterator iter1 = collect1.begin();
    typename Tcollect<T2, Allocator>::iterator iter2 = collect2.begin();
    Tcollect<std::tuple<T1, T2>, Allocator> result;

    while (iter1 != collect1.end() && iter2 != collect2.end())
    {
        std::tuple<T2, T2> tup(*iter1++, *iter2++);
        result.push_back(tup);
    }

    return result;
}

template <typename T, template <typename, typename> typename Tcollect, typename Allocator>
Tcollect<T, Allocator> filter(Tcollect<T, Allocator> collect, std::function<bool(T)> filt)
{
    Tcollect<T, Allocator> result;
    for (T item : collect)
    {
        if (filt(item))
        {
            result.push_back(item);
        }
    }
    return result;
}




