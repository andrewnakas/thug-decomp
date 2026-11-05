struct Arr_002637D0 {
    char pad0[0xC];
    unsigned int mC;
};

extern "C" Arr_002637D0* func_001E55B8(unsigned int id, int a);
extern "C" int func_001E9300(Arr_002637D0* a, unsigned int i);
extern "C" unsigned int func_001E5628(int s, int a);
extern "C" int func_002637B0(int o, unsigned int i);
extern "C" int func_00263950(int o, unsigned int i);
extern "C" int func_0026D560(int t);

int func_002637D0(int obj)
{
    unsigned int idx = 0;
    Arr_002637D0* a = func_001E55B8(0xEB1A4BC9, 1);
    unsigned int n = a->mC;
    do {
        unsigned int i = 0;
        while (i < n && idx != func_001E5628(func_001E9300(a, i), 1)) i++;
        if (i != n) {
            int t = func_002637B0(obj, idx);
            if (!func_00263950(obj, idx)) return 0;
            if (!func_0026D560(t)) return 0;
        }
        idx++;
    } while (idx < 21);
    return 1;
}
