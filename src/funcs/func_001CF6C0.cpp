struct Arr_001CF6C0 {
    int m0;
    int m4;
    int m8;
    int mC;
};

extern "C" void* func_001E5548(unsigned int, int);
extern "C" int func_001E8180(void*, unsigned int, void*, int);
extern "C" int func_001E8398(void*, unsigned int, float*, int);
extern "C" int func_001E8248(void*, unsigned int, Arr_001CF6C0**, int);
extern "C" void* func_001E9378(Arr_001CF6C0*, int);
extern "C" int func_001E7EB0(void*, unsigned int, float*, int);

struct Cfg_001CF6C0 {
    char pad[0x1358];
    unsigned int m1358;
};

struct Entry_001CF6C0 {
    float a;
    float b;
    float c;
    float d;
};

struct Obj_001CF6C0 {
    char pad0[0x1C];
    void* m1C;
    int m20;
    int pad24[2];
    int m2C;
    float m30;
    float m34;
    int m38;
    Entry_001CF6C0 m3C[8];
    char padBC[0xB8 - 0xBC + 0x80];
    void Load();
};

struct Obj2_001CF6C0 {
    char pad[0xB8];
    Cfg_001CF6C0* mB8;
};

void Obj_001CF6C0::Load()
{
    Arr_001CF6C0* arr;
    func_001E8180(func_001E5548(0x3C2DA7F5, 1), ((Obj2_001CF6C0*)this)->mB8->m1358, &m1C, 1);
    func_001E8398(m1C, 0x306F8A9F, &m30, 0);
    func_001E8398(m1C, 0x667FA96A, &m34, 0);
    func_001E8248(m1C, 0x83273E6B, &arr, 1);
    m38 = arr->mC;
    for (int i = 0; i < m38; i++) {
        void* e = func_001E9378(arr, i);
        func_001E7EB0(e, 0xFAD20901, &m3C[i].a, 1);
        func_001E7EB0(e, 0xFCF5C8A2, &m3C[i].b, 1);
        func_001E7EB0(e, 0x735B5CE4, &m3C[i].c, 1);
        func_001E7EB0(e, 0xE59A89A6, &m3C[i].d, 1);
    }
    func_001E8180(m1C, 0xBF8E0ACE, &m2C, 1);
    if (m20) {
        void* s = func_001E5548(0x38EC37AC, 1);
        func_001E8398(s, 0xF5406E1A, &m30, 1);
        func_001E8398(s, 0x060E93A2, &m34, 1);
        func_001E8180(s, 0x22995285, &m2C, 1);
    }
}
