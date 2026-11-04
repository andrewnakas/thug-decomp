extern char D_00371C78[];

struct Iter_002AA598 {
    int m0;
    int m4;
    void* m8;
    Iter_002AA598() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002AA598() { m8 = D_00371C78; }
};

struct Item_002AA598 {
    char pad[0x14C];
    int m14C;
};

extern void* D_00392068;
extern "C" Item_002AA598* func_002A53F8(void* self, Iter_002AA598* it, int a);
extern "C" Item_002AA598* func_002A5490(void* self, Iter_002AA598* it, int a);

bool func_002AA598()
{
    void* s = D_00392068;
    Iter_002AA598 it;
    for (Item_002AA598* p = func_002A53F8(s, &it, 0); p; p = func_002A5490(s, &it, 0)) {
        p->m14C &= ~0x400;
    }
    return true;
}
