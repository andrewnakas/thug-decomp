extern char D_0037BCD8[];

struct Ctr_002D30E8 {
    int m0;
    int m4;
    void Dec() { m4--; }
};

struct Sub_002D30E8 {
    char pad[0x150];
    Ctr_002D30E8 m150;
    char pad158[0x164 - 0x158];
    void* m164;
    void* m168;
};

struct Mgr_002D30E8 {
    char pad[4];
    Sub_002D30E8* m4;
};

struct Addr_002D30E8 {
    short m0;
    unsigned short m2;
    int m4;
};

extern Mgr_002D30E8* D_00392068;
extern "C" int func_002A1A38(void* s);
extern "C" int func_002A18E0(void* m);
extern "C" unsigned short func_00326B40(unsigned short v);
extern "C" void func_002A2CA0(void* m, int kind, long ip, unsigned short port, int idx);
extern "C" void func_001048F0(void* p);
extern "C" void func_00303F20(void* p);
extern "C" void func_00304190();
extern "C" void func_00303958();
extern "C" void* func_002A39E0(void* m, int a);
extern "C" void func_002012B8(void* p, int a);
extern "C" void func_001F0370(char* s, void* a, int b, int c);

void func_002D30E8(int err, int unused, Addr_002D30E8* addr, void* x)
{
    Mgr_002D30E8* mgr = D_00392068;
    if (!err && !func_002A1A38(mgr)) {
        int host = func_002A18E0(mgr) == 1;
        int ip = addr->m4;
        func_002A2CA0(mgr, host, ip, func_00326B40(addr->m2), 0);
    }
    if (func_002A1A38(mgr)) {
        mgr->m4->m150.Dec();
        if (mgr->m4->m150.m4 == 0)
            func_001048F0(mgr->m4->m164);
        return;
    }
    func_00303F20(x);
    func_00304190();
    func_00303958();
    func_002012B8(func_002A39E0(mgr, 0), 0);
    func_001048F0(mgr->m4->m164);
    func_001048F0(mgr->m4->m168);
    if (err)
        func_001F0370(D_0037BCD8, 0, 0, 0);
}
