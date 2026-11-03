struct Mgr_002CC178 {
    char pad0[0x24];
    int m24;
};

struct Item_002CC178 {
    char pad0[0xC0];
    char mC0[0x20];
    int mE0;
};

extern Mgr_002CC178* D_0038FC78;
extern "C" void* func_002637B0(int a, int b);
extern "C" void func_0026CD98(void* p);
extern "C" void func_0026CE20(void* p, void* q, int a, int b);

struct Obj_002CC178 {
    int m0;
    Item_002CC178* m4[32];
    void Run();
};

void Obj_002CC178::Run()
{
    void* v = func_002637B0(D_0038FC78->m24, -1);
    if (v) {
        func_0026CD98(v);
        for (int i = 0; i < 32; i++) {
            Item_002CC178* p = m4[i];
            if (p)
                func_0026CE20(v, p->mC0, 0, p->mE0);
        }
    }
}
