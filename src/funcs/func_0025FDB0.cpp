struct List_0025FDB0;
extern "C" void* func_0025F128(List_0025FDB0* l, int i);
extern "C" int func_0025AB70(void* n);

struct List_0025FDB0 {
    int Fn();
};

int List_0025FDB0::Fn()
{
    void* n = func_0025F128(this, 0);
    if (n) return func_0025AB70(n);
    return 0;
}
