extern "C" void func_0010BEB8(void* p);

struct Tree_00160C40 {
    void Free(void** n, int depth);
};

void Tree_00160C40::Free(void** n, int depth)
{
    if (!n)
        return;
    if (depth > 0) {
        for (int i = 0; i < 16; i++)
            Free((void**)n[i], depth - 1);
    }
    func_0010BEB8(n);
}
