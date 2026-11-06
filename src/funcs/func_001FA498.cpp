extern "C" int func_00331950(const char* a, const char* b);
extern "C" char* func_00331A9C(char* d, const char* s);

struct Obj_001FA498 {
    char pad0[0x150];
    char m_names[12][16];
    char pad210[0x2CC - 0x210];
    int m2CC;
};

extern "C" void func_001FA498(Obj_001FA498* o, int i, const char* s)
{
    char* d = o->m_names[i];
    if (func_00331950(s, d)) {
        func_00331A9C(d, s);
        o->m2CC = 1;
    }
}
