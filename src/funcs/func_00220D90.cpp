/* NOTE: like 00220FC0, needs the zero initialisers of b and c (overwritten by b = a; c = a; before any read) to produce the game's sw $zero,4/8($sp). Lead to decide. */
struct MemMgr_00220D90 {
    char m_pad[0x148];
    void* m_148[1];
    char m_pad14C[0x188 - 0x14C];
    void* m_188[1];
};

struct Comp_00220D90 {
    char m_pad[0x18];
    virtual void V0();
    virtual int Refresh();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void Apply(char* desc, int a, int heap, int b);
};

struct Skater_00220D90 {
    char m_pad[0x320];
    int m_320;
};

extern void* D_0038FC78;
extern void* D_0038C608;
extern MemMgr_00220D90* D_00388A70;

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" Skater_00220D90* func_0022DE70(void* self, int index);
extern "C" char* func_0022E3C8(void* self, int index);
extern "C" void* func_00187B48(void* self, unsigned int name);
extern "C" void func_00184950(void* obj);
extern "C" void func_001876A8(void* self);
extern "C" int func_002041F8(Skater_00220D90* self);
extern "C" void func_0010A950(MemMgr_00220D90* self, void* context);
extern "C" void func_0010A9B0(MemMgr_00220D90* self);
extern "C" void func_001325A0();
extern "C" Comp_00220D90* func_00185578(void* self, unsigned int id);
extern "C" void func_00205290(Skater_00220D90* self, char* profile);
extern "C" void func_001AB7C0(Comp_00220D90* self, char* profile);
extern "C" void func_00205428(Skater_00220D90* self, char* profile);
extern "C" void func_0018C230(Comp_00220D90* self, unsigned int name, int a, int b);

bool Cmd_00220D90(void* params, void* script)
{
    int a;
    int b = 0;
    int c = 0;
    a = 0;
    func_001E7DE8(params, 0, &a, 0);
    b = a;
    c = a;
    func_001E7DE8(params, 0x7EA855F0, &b, 0);
    func_001E7DE8(params, 0x5B8AB877, &c, 0);
    Skater_00220D90* skater = func_0022DE70(D_0038FC78, c);
    if (!skater->m_320) {
        void* obj = func_00187B48(D_0038C608, 0x884EF81B);
        if (obj) {
            func_00184950(obj);
            func_001876A8(D_0038C608);
        }
    }
    char* profile = func_0022E3C8(D_0038FC78, b);
    MemMgr_00220D90* mem = D_00388A70;
    func_0010A950(mem, mem->m_188[func_002041F8(skater)]);
    func_001325A0();
    func_00185578(skater, 0x286A8D26)->Apply(profile + 4, 0, func_002041F8(skater), 0);
    func_0010A9B0(D_00388A70);
    MemMgr_00220D90* mem2 = D_00388A70;
    func_0010A950(mem2, mem2->m_148[func_002041F8(skater)]);
    func_00205290(skater, profile);
    func_001AB7C0(func_00185578(skater, 0x270F56E1), profile);
    func_00205428(skater, profile);
    func_0010A9B0(D_00388A70);
    unsigned int flag;
    if (func_001E8398(params, 0x41EEC86B, &flag, 0)) {
        Comp_00220D90* comp = func_00185578(skater, 0x286A8D26);
        func_0018C230(comp, 0xA7A9D4B8, 1, 1);
        comp->Refresh();
    }
    return true;
}
