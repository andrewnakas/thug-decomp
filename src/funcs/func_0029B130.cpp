extern "C" int func_00185578(void* p, unsigned int key);

struct Obj_0029B130 {
    char pad0[0xC];
    void* mC;
    char pad10[0xC];
    int m1C;
    int m20;
    void Lookup();
};

void Obj_0029B130::Lookup()
{
    m1C = func_00185578(mC, 0x27D7CD28);
    m20 = func_00185578(mC, 0xAC8946E2);
}
