extern "C" void* func_001FA800(void* self);
extern "C" void func_001FF970(void* conn, int id, void* msg);

struct Msg_001FD298 {
    unsigned char m_type;
    char pad1;
    unsigned short m_size;
    void* m_data;
    char pad8[0x18];
    void Set(void* d, unsigned short n, unsigned char t) { m_data = d; m_size = n; m_type = t; }
};

struct Inner_001FD298 {
    char pad0[0x48];
    int m_48;
    const int& Id() const { return m_48; }
};

struct Src_001FD298 {
    int m_0;
};

struct Obj_001FD298 {
    Src_001FD298* m_0;
    char pad4[0xC];
    void* m_10;
    Inner_001FD298* m_14;
    int Run();
};

int Obj_001FD298::Run()
{
    Msg_001FD298 msg;
    int val;
    func_001FA800(&msg);
    val = m_0->m_0;
    msg.Set(&val, 4, 2);
    func_001FF970(m_10, m_14->Id(), &msg);
    return 1;
}
