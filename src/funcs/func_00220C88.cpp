extern char D_00371868[];

struct MemMgr_00220C88 {
    char m_pad[0x188];
    void* m_contexts[1];
};

struct Desc_00220C88 {
    char m_data[0x60];
};

struct Comp_00220C88 {
    char m_pad[0x18];
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
    virtual void Apply(Desc_00220C88* desc, int a, int heap, int b);
};

extern void* D_0038FC78;
extern MemMgr_00220C88* D_00388A70;

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" void* func_0022DE70(void* self, int index);
extern "C" int func_002041F8(void* self);
extern "C" void func_0010A950(MemMgr_00220C88* self, void* context);
extern "C" void func_0010A9B0(MemMgr_00220C88* self);
extern "C" bool func_001E8A50(void* self, const char* name, int* out, int assert_);
extern "C" void func_0011F880(Desc_00220C88* self);
extern "C" void func_0011FB18(Desc_00220C88* self, int checksum, int flag);
extern "C" void func_0011F8C8(Desc_00220C88* self, int flags);
extern "C" Comp_00220C88* func_00185578(void* self, unsigned int id);

bool func_00220C88(void* params)
{
    int index = 0;
    func_001E7DE8(params, 0, &index, 0);
    void* skater = func_0022DE70(D_0038FC78, index);
    MemMgr_00220C88* mem = D_00388A70;
    func_0010A950(mem, mem->m_contexts[func_002041F8(skater)]);
    int appearance;
    func_001E8A50(params, D_00371868, &appearance, 1);
    Desc_00220C88 desc;
    func_0011F880(&desc);
    func_0011FB18(&desc, appearance, 1);
    func_00185578(skater, 0x286A8D26)->Apply(&desc, 0, func_002041F8(skater), 0);
    func_0010A9B0(D_00388A70);
    func_0011F8C8(&desc, 2);
    return true;
}
