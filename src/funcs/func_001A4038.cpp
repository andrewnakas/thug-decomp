extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E84E8(void* params, const char* name, unsigned int* out, int req);
extern "C" void* func_001D4058(unsigned int id);
extern "C" void* func_001317D0(unsigned int id);
extern char D_0038CCF8[];

struct Info_001A4038 {
    int m0[2];
    int m8;
};

extern "C" Info_001A4038* func_001354F8(void* p);

struct C_001A4038 {
    int m_base[6];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void Attach(void* obj, int value);
    void Setup(void* params);
};

void C_001A4038::Setup(void* params)
{
    unsigned int id = 0;
    func_001E8398(params, 0x2D7E583B, &id, 0);
    void* obj = func_001D4058(id);
    if (!obj) return;
    unsigned int type = 0;
    func_001E84E8(params, D_0038CCF8, &type, 0);
    if (type == 0xB7B3BD86) {
        unsigned int n;
        func_001E8398(params, 0xA1DC81F9, &n, 1);
        Info_001A4038* info = func_001354F8(func_001317D0(n));
        Attach(obj, info->m8);
    } else {
        Attach(obj, 0);
    }
}
