extern char D_00361A28[];
extern void* D_0038C608;
extern "C" int func_001E84E8(void* params, char* name, unsigned int* out, int required);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" int func_001E6A50(void* p, void* src);
extern "C" void func_001E6AE8(void* p, int mode);

struct K_00185300 {
    char pad[0x18];
    virtual void V0();
    virtual void V1();
    virtual void Init(void* params);
};
extern "C" K_00185300* func_00186E28(void* factory, unsigned int type);

struct C_00185300 {
    void Add(K_00185300* c);
    void Create(void* params, void* extra);
};

void C_00185300::Create(void* params, void* extra)
{
    unsigned int type;
    func_001E84E8(params, D_00361A28, &type, 1);
    K_00185300* c = func_00186E28(D_0038C608, type);
    Add(c);
    if (extra) {
        void* s = func_001E6978(func_001190D0(8));
        func_001E6A50(s, params);
        func_001E6A50(s, extra);
        c->Init(s);
        if (s) func_001E6AE8(s, 3);
    } else {
        c->Init(params);
    }
}
