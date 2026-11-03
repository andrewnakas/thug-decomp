extern char* D_0038C308;
extern int D_00394174;
extern char D_00378E28[];
extern char D_00379020[];
extern char D_003922C0[];
extern char D_00379310[];
extern char D_00379330[];

struct Data_002AEE50 {
    int m0;
    signed char m4;
};

struct Mgr_002AEE50 {
    char pad0[0x28];
    int m28;
    char pad2C[4];
    int m30;
    char pad34[0xA4 - 0x34];
    void* mA4;
};

extern "C" void func_002A8020(Mgr_002AEE50* m);
extern "C" int func_00104968(void* p);
extern "C" int func_002A1A38(Mgr_002AEE50* s);
extern "C" int func_0010FC30();
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" int func_001F0D78(char* s);
extern "C" char* func_002A22D0(Mgr_002AEE50* m, int v);
extern "C" void func_001E7A30(void* p, int name, int type, char* v);
extern "C" void func_001E7A68(void* s, int name, int type, int v);
extern "C" void* func_002A6070(Mgr_002AEE50* m);
extern "C" void func_00203068(void* p, int name, void* s);
extern "C" void func_00105260(void* p, void* q);
extern "C" void func_002A7B50(Mgr_002AEE50* s, int a, int b, char* c, int d, int e, int f, int g, int h);
extern "C" void func_001F0370(char* s, void* a, int b, int c);

struct Obj_002AEE50 {
    Data_002AEE50* m0;
    char pad4[0x18];
    Mgr_002AEE50* m1C;
    int Handle();
};

int Obj_002AEE50::Handle()
{
    Mgr_002AEE50* m = m1C;
    Data_002AEE50* d = m0;
    func_002A8020(m);
    m->m30 = 0;
    if (d->m4) {
        char* g = D_0038C308;
        if (func_00104968(m->mA4)) {
            if (func_002A1A38(m) == 0)
                m->m28 = d->m0;
            return 3;
        } else {
            m->m28 = d->m0;
            D_00394174 = func_0010FC30() + 3000;
            if (func_002A1A38(m)) {
                void* p = func_001E6978(func_001190D0(8));
                func_001E7A30(p, func_001F0D78(D_00378E28), 3, func_002A22D0(m, 0));
                func_001E7A68(p, func_001F0D78(D_00379020), 0xD, m->m28);
                func_00203068(func_002A6070(m), func_001F0D78(D_003922C0), p);
                if (p)
                    func_001E6AE8(p, 3);
                if (m->m28 == (int)0xB664035D)
                    D_00394174 += 1000;
            }
            func_00105260(g + 8, m->mA4);
            func_002A7B50(m, 0, func_001F0D78(D_00379310), func_002A22D0(m, 1), 0, 0, 0, 0, 5000);
            func_001F0370(D_00379330, 0, 0, 0);
        }
    return 3;
    }
    return 1;
}
