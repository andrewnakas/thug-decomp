struct Snd_002D2C40 {
    char pad0[8];
    char m8[4];
};

extern void* D_00392068;
extern Snd_002D2C40* D_0038C308;
extern char D_004532C8[];
extern int D_00392B18;
extern unsigned int D_00394194;
extern unsigned int D_00394190;
extern int D_00394198;
extern int D_0039418C;
extern "C" void* func_002A39D8(void* m);
extern "C" void func_002D2730();
extern "C" void func_002012B8(void* p, void (*f)());
extern "C" void* func_002012B0(void* p);
extern "C" int func_00306E38(void* a, void* b, int port);
extern "C" void func_00306F38(void* a);
extern "C" unsigned int func_0010FC30();
extern "C" void func_00105260(void* p, int v);

struct Obj_002D2C40 {
    char pad0[0x14C];
    int m14C;
    char pad150[8];
    void* m158;
    char pad15C[0xC];
    int m168;
    void Connect();
};

void Obj_002D2C40::Connect()
{
    Snd_002D2C40* snd = D_0038C308;
    void* p = func_002A39D8(D_00392068);
    func_002012B8(p, func_002D2730);
    D_004532C8[0] = 0;
    D_00392B18 = 0;
    if (func_00306E38(m158, func_002012B0(p), 0x141E) == 1)
        func_00306F38(m158);
    unsigned int t = func_0010FC30();
    D_00394190 = t;
    D_00394194 = t;
    D_00394198 = 0;
    D_0039418C = 0;
    func_00105260(snd->m8, m168);
    m14C = 1;
}
