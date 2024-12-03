template <typename T1, typename T2, typename T3>
struct triple {
    T1 first;
    T2 second;
    T3 third;

    triple(T1 f, T2 s, T3 t) : first(f), second(s), third(t) {}
    triple() = default;
};