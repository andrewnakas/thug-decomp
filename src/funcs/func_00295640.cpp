struct Entry_00295640 {
    int m0;
    char pad[0x2A1];
    unsigned char m2A5;
    char pad2[0x350 - 0x2A6];
};
struct Arr_00295640 {
    char pad[0xC];
    int mC;
};
extern "C" unsigned int func_00291E60(unsigned int checksum);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" int func_001E9D70(void* s, void* buf);
extern "C" void func_00292630(Entry_00295640* e);
extern "C" int func_001E8248(void* p, unsigned int key, Arr_00295640** out, int req);
extern "C" void* func_001E9378(Arr_00295640* a, int i);
extern "C" void func_002935C8(Entry_00295640* e, void* s);
extern "C" void func_001E6AE8(void* p, int v);

struct Obj_00295640 {
    char pad0[0x20];
    Entry_00295640 m20[50];
    char pad1[0xA5C0 - 0x20 - 0x350 * 50];
    int mA5C0;
    int Load(unsigned int id, void* buf);
};

int Obj_00295640::Load(unsigned int id, void* buf)
{
    unsigned int key = func_00291E60(id);
    void* s = func_001E6978(func_001190D0(8));
    int ret = func_001E9D70(s, buf);
    Entry_00295640* p = m20;
    for (int i = 0; i < 50; i++, p++) {
        if (p->m2A5 && p->m0 == key) func_00292630(p);
    }
    mA5C0 = 0;
    Arr_00295640* a = 0;
    func_001E8248(s, 0x38DBE1D0, &a, 1);
    int j = 0;
    int n = a->mC;
    int i = 0;
    if (n) {
        Entry_00295640* e = m20;
        for (; i < 50 && n; i++, e++) {
            if (!e->m2A5) {
                func_002935C8(e, func_001E9378(a, j++));
                n--;
                e->m0 = key;
            }
        }
    }
    if (s) func_001E6AE8(s, 3);
    return ret;
}
