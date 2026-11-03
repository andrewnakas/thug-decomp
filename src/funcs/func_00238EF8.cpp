extern unsigned short D_0038FE88[];
extern char D_0038FE90[];
extern char D_0038FE98[];
extern char D_003736F0[];
extern void* D_00389A30;
extern void* D_0038FC78;

struct Ref_00238EF8 {
    void* m_p;
    int pad[3];
};

struct Obj_00238EF8 {
    short pad0;
    short m_id;
};

extern "C" void* func_0022DF08(void* mgr, int id);
extern "C" int func_002041F8(void* skater);
extern "C" void func_0012DB48(Ref_00238EF8* ref, void* a, unsigned int key, int b);
extern "C" void func_00183CB8(void* p, Ref_00238EF8* ref);
extern "C" char* func_001044A8(int value, int sep);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void func_001262A0(void* p, char* text);
extern "C" void func_001F0370(char* name, void* params, void* a, int b);

void func_00238EF8(Obj_00238EF8* obj, int score, int mult)
{
    Ref_00238EF8 ref;
    char buf[0x80];
    void* screen = D_00389A30;
    void* skater = func_0022DF08(D_0038FC78, obj->m_id);
    int idx = 0;
    if (skater)
        idx = func_002041F8(skater);
    func_0012DB48(&ref, screen, idx + 0xF4D3A70E, 0);
    void* e = ref.m_p;
    if (e) {
        func_00183CB8(e, &ref);
        ref.m_p = 0;
    }
    if (!score)
        *(unsigned short*)buf = D_0038FE88[0];
    else if (mult)
        func_003331D0(buf, D_0038FE90, func_001044A8(score, ','), mult);
    else
        func_003331D0(buf, D_0038FE98, func_001044A8(score, ','));
    func_001262A0(e, buf);
    func_001F0370(D_003736F0, 0, 0, 0);
}
