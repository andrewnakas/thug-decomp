struct Arr_002440B0 {
    char pad0[0xC];
    unsigned int mC;
};

struct Obj_002440B0 {
    char pad0[0x20];
    int m20;
    int m24;
    char pad28[0x34];
    int m5C;
    void Load(int script);
};

extern "C" void func_001E6B30(int s);
extern "C" int func_001E8248(int s, unsigned int id, Arr_002440B0** out, int f);
extern "C" int func_001E9300(Arr_002440B0* a, unsigned int i);
extern "C" void func_001E7200(int s, int id, int v);

void Obj_002440B0::Load(int script)
{
    Arr_002440B0* arr;
    func_001E6B30(m24);
    m5C = 0;
    if (func_001E8248(script, 0xCC3C4CC4, &arr, 0)) {
        unsigned int i = 0;
        if (arr->mC) {
            do {
                func_001E7200(m24, func_001E9300(arr, i), 0);
                i++;
                m5C++;
            } while (i < arr->mC);
        }
    }
    func_001E7200(m20, 0xB3790F33, m5C);
}
