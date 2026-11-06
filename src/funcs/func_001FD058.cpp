extern "C" void* func_001FA800(void* self);
extern "C" void func_001FF970(int a, int b, void* msg);

struct Msg_001FD058 {
    unsigned char m_type;
    char pad1;
    unsigned short m_size;
    void* m_data;
    char pad8[0x18];
    void Set(void* d, unsigned short n, unsigned char t) { m_data = d; m_size = n; m_type = t; }
};

struct Inner_001FD058 {
    char pad0[0x48];
    int m_48;
    const int& Id() const { return m_48; }
};

struct Obj_001FD058 {
    unsigned short* m_0;
    char pad4[4];
    long m_8;
    int m_10;
    Inner_001FD058* m_14;
    int m_18;
    int Run();
};

int Obj_001FD058::Run()
{
    Msg_001FD058 msg;
    unsigned short val;
    func_001FA800(&msg);
    m_8 = 2;
    if (m_18 & 1) {
        return 3;
    }
    val = *m_0;
    msg.Set(&val, 2, 8);
    func_001FF970(m_10, m_14->Id(), &msg);
    return 1;
}
