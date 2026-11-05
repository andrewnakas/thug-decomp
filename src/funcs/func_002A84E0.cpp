struct Msg_002A84E0 {
    unsigned char m_type;
    unsigned char m_1;
    unsigned short m_size;
    void* m_data;
    int m_8;
    int m_C;
    unsigned char m_10;
    int m_14;
    int m_18;
    int m_1C;
};

extern "C" void func_001FA800(Msg_002A84E0* m);
extern "C" void func_00200C00(void* q, Msg_002A84E0* m);

struct Obj_002A84E0 {
    char pad[0x18];
    void* m18;
    char pad1C[0x10];
    unsigned char m2C;
    unsigned char m2D;
    void Send();
};

void Obj_002A84E0::Send()
{
    Msg_002A84E0 msg;
    func_001FA800(&msg);
    msg.m_data = &m2C;
    msg.m_size = 1;
    msg.m_type = 0x59;
    msg.m_C = 2;
    msg.m_10 = 8;
    func_00200C00(m18, &msg);
    m2D = m2C;
}
