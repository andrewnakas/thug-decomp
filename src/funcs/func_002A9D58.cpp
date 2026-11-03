extern char D_00371C78[];

struct Iter_002A9D58 {
    int m0;
    int m4;
    void* m8;
    Iter_002A9D58() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A9D58() { m8 = D_00371C78; }
};

struct Sub_002A9D58 {
    char pad[0x68];
    int m68;
};

struct Item_002A9D58 {
    char pad[0x1C];
    Sub_002A9D58* m1C;
};

extern void* D_00392068;
extern "C" int func_002A1A38(void* s);
extern "C" Item_002A9D58* func_002A53F8(void* self, Iter_002A9D58* it, int a);
extern "C" Item_002A9D58* func_002A5490(void* self, Iter_002A9D58* it, int a);

bool func_002A9D58()
{
    void* s = D_00392068;
    Iter_002A9D58 it;
    if (func_002A1A38(s)) {
        for (Item_002A9D58* p = func_002A53F8(s, &it, 1); p; p = func_002A5490(s, &it, 1)) {
            if (p->m1C->m68 & 1)
                continue;
            return false;
        }
    }
    return true;
}
