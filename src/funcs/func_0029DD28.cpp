extern "C" int func_00185578(void* p, unsigned int key);

struct Obj_0029DD28 {
    char pad0[0xC];
    void* mC;
    char pad10[0xC];
    int m1C;
    void Lookup();
};

void Obj_0029DD28::Lookup()
{
    m1C = func_00185578(mC, 0xCE0CA665);
}
