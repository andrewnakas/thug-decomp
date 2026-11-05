extern "C" int func_001D0E90(void* p, int* v, int n);

struct Obj_001D0820 {
    char pad0[0xC];
    void* mC;
    bool Has(int v);
};

bool Obj_001D0820::Has(int v)
{
    return func_001D0E90(mC, &v, 1) != 0;
}
