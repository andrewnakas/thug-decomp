struct Ent_00295498 {
    int m0;
    char pad4[0x2A5 - 0x4];
    unsigned char m2A5;
    char pad2A6[0x350 - 0x2A6];
};

struct Mgr_00295498 {
    char pad[0x20];
    Ent_00295498 m20[50];
    void Collect(int id, void* params);
};

extern "C" int func_00295E28(Mgr_00295498* m, int id);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* a, int n, int t);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_00293380(Ent_00295498* e, void* s);
extern "C" void func_001E9170(void* a, int i, void* s);
extern "C" void func_001E7720(void* p, unsigned int name, void* a);

void Mgr_00295498::Collect(int id, void* params)
{
    Ent_00295498* e = m20;
    int n = func_00295E28(this, id);
    void* arr = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(arr, n, 10);
    int k = 0;
    for (int i = 0; i < 50; i++, e++) {
        if (e->m2A5 && e->m0 == id) {
            void* s = func_001E6978(func_001190D0(8));
            func_00293380(e, s);
            func_001E9170(arr, k++, s);
        }
    }
    func_001E7720(params, 0x38DBE1D0, arr);
}
