extern int D_00388A70;
extern int D_00389C38;
extern "C" void* func_0010A638(int pool, int size, int a, int b);
extern "C" void func_00145648(int a);

struct Mesh_00133848;
struct Elem_00133848 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};

struct Hdr_001022D8 {
    char pad[0x30];
    Hdr_001022D8();
};

struct Slot_00207DC0 {
    char pad[0x30];
    Slot_00207DC0();
};

struct Slots_00133848 {
    Hdr_001022D8 m_hdr;
    Slot_00207DC0 m_slots[20][20];
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

extern "C" void func_00207F98(Slots_00133848* s, void* src);
extern "C" void func_00208088(Slots_00133848* s, Elem_00133848* e, int n);
extern "C" void func_00134F10(Mesh_00133848* m, int key);
extern "C" void func_00135048(Mesh_00133848* m, int a);
extern "C" void func_001354B8(Mesh_00133848* m, Elem_00133848* e);
extern "C" void func_00135580(Mesh_00133848* m, int flags);

struct Scene_00133848 {
    char pad0[0x88];
    int m_88;
    char pad8C[0x24];
    char m_B0[0x24];
    Slots_00133848* m_D4;
    char m_D8[0x80];
    int m_158;
    Elem_00133848* m_15C;
    int m_160;
    char pad164[0x11C];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual int V4(void* a);
    int Load(void* data, int b);
};

extern "C" int func_00133550(Scene_00133848* self, void* data, void* d8, int* count, Elem_00133848** elems,
                              int* m160, void* b0, int b);
extern "C" Mesh_00133848* func_00132FD0(Scene_00133848* self, int key);
extern "C" Mesh_00133848* func_00134660(Scene_00133848* self);
extern "C" void func_00132FF8(Scene_00133848* self, Mesh_00133848* m);

int Scene_00133848::Load(void* data, int b)
{
    func_00133550(this, data, m_D8, &m_158, &m_15C, &m_160, m_B0, b);
    if (m_158 > 0) {
        if (m_88) {
            m_D4 = new Slots_00133848;
            func_00207F98(m_D4, m_B0);
            func_00208088(m_D4, m_15C, m_158);
        }
        for (int i = 0; i < m_158; i++) {
            Mesh_00133848* m = func_00132FD0(this, m_15C[i].m0);
            if (!m) {
                m = func_00134660(this);
                func_00134F10(m, m_15C[i].m0);
                func_00135048(m, 1);
                func_00132FF8(this, m);
            }
            func_001354B8(m, &m_15C[i]);
            func_00135580(m, 0x40);
        }
    }
    func_00145648(D_00389C38);
    return V4(data);
}
