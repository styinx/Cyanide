#ifndef CYANIDE_RANGE_HPP
#define CYANIDE_RANGE_HPP

namespace cyanide::cystd
{

    template<typename T>
    class Range
    {
    public:
        class Iterator
        {
        public:
            T current;
            T start;
            T stop;
            T step;

            Iterator(T current, T start, T stop, T step)
                : current(current)
                , start(start)
                , stop(stop)
                , step(step)
            {
            }

            T operator*() const
            {
                return current;
            }

            explicit operator T&()
            {
                return current;
            }

            Iterator& operator++()
            {
                if(start <= stop)
                {
                    current += step;
                }
                else
                {
                    current -= step;
                }
                return *this;
            }

            bool operator==(const T& other) const
            {
                if(start <= stop)
                {
                    return current >= other;
                }
                else if(start > stop)
                {
                    return current <= other;
                }
            }

            bool operator!=(const T& other) const
            {
                return current != other;
            }
        };

        T start;
        T stop;
        T step;

        Range(T from, T to, T step)
            : start(from)
            , stop(to)
            , step(step)
        {
        }

        Iterator begin() const
        {
            return Iterator(start, start, stop, step);
        };

        Iterator end() const
        {
            return Iterator(stop, start, stop, step);
        };
    };

    template<typename T>
    Range<T> range(T from, T to, T step)
    {
        return Range<T>(from, to, step);
    }

}  // namespace cyanide

#endif  // CYANIDE_RANGE_HPP
