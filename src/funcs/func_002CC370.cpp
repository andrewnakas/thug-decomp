struct Item_002CC370 {
    char pad0[0xC];
    void* mC[2];
    char pad14[0xC0 - 0x14];
    char mC0[4];
};

struct Holder_002CC370 {
    void* m0;
};

extern void* D_0038FC78;
extern void* D_00388A70;
extern "C" void func_002B7968(void* a, void* b);
extern "C" void* func_00230628(void* p);
extern "C" int func_0026D168(void* p, void* name);
extern "C" void* func_002977B0();
extern "C" void func_002969D8(void* p, int idx);
extern "C" void func_0010A8D8(void* pool, void* p);

struct Obj_002CC370 {
    int m0;
    Item_002CC370* m4[32];
    char pad84[0x104 - 0x84];
    Holder_002CC370* m104;
    void Remove(int idx, int flag);
};

void Obj_002CC370::Remove(int idx, int flag)
{
    Item_002CC370* item = m4[idx];
    for (int i = 0; i < 2; i++) {
        if (item->mC[i])
            func_002B7968(m104->m0, item->mC[i]);
    }
    if (flag) {
        int n = func_0026D168(func_00230628(D_0038FC78), item->mC0);
        if (n >= 0)
            func_002969D8(func_002977B0(), n);
    }
    for (int j = 0; j < 32; j++) {
        if (m4[j] == item)
            m4[j] = 0;
    }
    func_0010A8D8(D_00388A70, item);
}
