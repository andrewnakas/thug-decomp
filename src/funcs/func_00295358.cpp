struct Entry_00295358 {
    int m0;
    char pad[0x2A1];
    unsigned char m2A5;
    char pad2[0x350 - 0x2A6];
};
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int n, int type);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_00293380(Entry_00295358* e, void* s);
extern "C" void func_001E9170(void* arr, int i, void* s);
extern "C" void func_001E7720(void* s, unsigned int name, void* arr);

struct Obj_00295358 {
    char pad0[0x20];
    Entry_00295358 m20[50];
    void Save(void* out);
};

void Obj_00295358::Save(void* out)
{
    int n = 0;
    for (int i = 0; i < 50; i++) {
        if (m20[i].m2A5 && m20[i].m0 != (int)0xE8B4B836) n++;
    }
    if (n == 0) return;
    void* arr = func_001E8DD0(func_00122CF8(16));
    func_001E8E98(arr, n, 10);
    int k = 0;
    Entry_00295358* e = m20;
    for (int i = 0; i < 50; i++, e++) {
        if (e->m2A5 && e->m0 != (int)0xE8B4B836) {
            void* s = func_001E6978(func_001190D0(8));
            func_00293380(e, s);
            func_001E9170(arr, k++, s);
        }
    }
    func_001E7720(out, 0x38DBE1D0, arr);
}
