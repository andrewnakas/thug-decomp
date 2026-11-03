struct Obj_002D51E8 {
    char pad0[0x8];
    void* m8;
    void* mC;
};

extern Obj_002D51E8* D_00392068;
extern char D_00392C60[];
extern char D_0037BFF0[];

extern "C" void func_001E7D18(void* p, char* name, char** out, int v);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void func_002D8158(void* p);
extern "C" void func_002D50B8(void* p, char* msg);

int func_002D51E8(void* params)
{
    char buf[128];
    char* s;
    Obj_002D51E8* m = D_00392068;
    func_001E7D18(params, D_00392C60, &s, 1);
    func_003331D0(buf, D_0037BFF0, s);
    void* p = m->m8;
    func_002D8158(m->mC);
    func_002D50B8(p, buf);
    return 1;
}
