struct Entry_002297A8 {
    unsigned int m_key;
    int m_value;
};

extern int D_0038FB68;
extern Entry_002297A8 D_003FD988[];

extern "C" unsigned int func_002297A8(unsigned int key)
{
    unsigned int lo = 0;
    unsigned int hi = D_0038FB68 - 1;
    unsigned int mid = hi >> 1;
    while (lo != mid) {
        unsigned int k = D_003FD988[mid].m_key;
        if (k == key)
            return mid;
        if (key < k)
            hi = mid;
        else
            lo = mid;
        mid = (lo + hi) >> 1;
    }
    if (key < D_003FD988[hi].m_key)
        return lo;
    return hi;
}
