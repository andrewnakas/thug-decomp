struct Rec_00293E08 { unsigned char id, a, b, c; };
extern "C" void* func_00122CF8(int);
extern "C" void* func_001E8DD0(void*);
extern "C" void func_001E8E98(void*, int, int);
extern "C" void* func_001190D0(int);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7200(void* p, unsigned int key, int v);
extern "C" void func_001E7360(void* p, int, unsigned int);
extern "C" void func_001E9170(void*, int, void*);
extern "C" void func_001E7720(void*, unsigned int, void*);

struct Obj_00293E08 {
    char pad0[0x2E0];
    Rec_00293E08 m2E0[10];
    int m308;
    void WriteRecs(void* s);
};

void Obj_00293E08::WriteRecs(void* s)
{
    if (!m308) return;
    void* arr = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(arr, m308, 10);
    for (int i = 0; i < m308; i++) {
        void* st = func_001E6978(func_001190D0(8));
        func_001E7200(st, 0xEB7D6498, m2E0[i].id);
        if (m2E0[i].a) func_001E7360(st, 0, 0x687E2C25);
        func_001E7200(st, 0xEDF5DB70, m2E0[i].b * 180);
        func_001E7200(st, 0xA4BEE6A1, m2E0[i].c);
        func_001E9170(arr, i, st);
    }
    func_001E7720(s, 0x0490F171, arr);
}
