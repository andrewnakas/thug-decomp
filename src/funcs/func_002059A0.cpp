struct Conn_002059A0 {
    int m_0;
};

extern void* D_00392068;

struct Obj_002059A0 {
    char pad0[0x18];
    int m_18;
    char pad1C[0x294];
    void* m_2B0;
    void* m_2B4;
    char pad2B8[0x64];
    int m_31C;

    void Reset();
};

extern "C" int func_002041F8(Obj_002059A0* self);
extern "C" Conn_002059A0* func_002A39E0(void* net, int a);
extern "C" void* func_00185578(void* obj, unsigned int type);
extern "C" int func_002918E0(void* c, int a, int b, int c2, int d);
extern "C" void func_00291AD8(void* c);
extern "C" void func_0018C230(void* c, unsigned int name, int a, int b);
extern "C" void func_0019FAB8(void* c);

void Obj_002059A0::Reset()
{
    void* net = D_00392068;
    Conn_002059A0* conn = func_002A39E0(net, func_002041F8(this));
    void* c = func_00185578(this, 0x488AF07A);
    func_002918E0(c, m_18, 0, conn->m_0, m_31C);
    func_00291AD8(c);
    func_0018C230(m_2B4, 0xA7A9D4B8, 0, m_31C);
    func_0019FAB8(m_2B0);
}
