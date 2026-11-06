/* fuzzy: 66.7 */
struct Entry_002957A0 {
    int m0;
    char pad[0x2A1];
    unsigned char m2A5;
    char pad2[0x350 - 0x2A6];
};
struct Arr_002957A0 {
    char pad[0xC];
    unsigned int mC;
};
struct Obj_002957A0;
extern "C" void func_002965D8(Obj_002957A0*);
extern "C" void func_00296550(Obj_002957A0*);
extern "C" int func_001E8248(void* p, unsigned int key, Arr_002957A0** out, int req);
extern "C" void* func_001E9378(Arr_002957A0* a, int i);
extern "C" int func_00291E80(void* params);
extern "C" void func_002935C8(Entry_002957A0* e, void* s);

struct Obj_002957A0 {
    char pad0[0x20];
    Entry_002957A0 m20[50];
    int mA5C0;
    void Load(void* params, int flag);
    Entry_002957A0* GetFree() {
        for (int k = 0; k < 50; k++) {
            if (!m20[k].m2A5) return &m20[k];
        }
        return 0;
    }
};

void Obj_002957A0::Load(void* params, int flag)
{
    if (flag) func_002965D8(this);
    else func_00296550(this);
    Arr_002957A0* a = 0;
    func_001E8248(params, 0x38DBE1D0, &a, 0);
    if (!a) return;
    unsigned int n = a->mC;
    for (unsigned int i = 0; i < n; i++) {
        void* s = func_001E9378(a, i);
        if (flag) {
            if (func_00291E80(s) != (int)0xE8B4B836) continue;
        } else {
            if (func_00291E80(s) == (int)0xE8B4B836) continue;
        }
        int k = 0;
    next:
        if (k < 50) {
            if (m20[k].m2A5) {
                k++;
                goto next;
            }
            func_002935C8(&m20[k], s);
        }
    }
    mA5C0 = 0;
}
