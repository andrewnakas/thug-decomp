struct Msg_002B0A30 {
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

struct Data_002B0A30 {
    int m_0;
    int m_4;
};

extern int D_0038FC78;
extern "C" void func_001FA800(Msg_002B0A30* m);
extern "C" int func_00236248(int x);
extern "C" void func_00200C00(void* q, Msg_002B0A30* m);

struct Obj_002B0A30 {
    Data_002B0A30* m_data;
    int m_4, m_8, m_C;
    void* m_queue;
    bool Send();
};

bool Obj_002B0A30::Send()
{
    Msg_002B0A30 msg;
    int g = D_0038FC78;
    func_001FA800(&msg);
    Data_002B0A30* d = m_data;
    d->m_4 = func_00236248(g);
    msg.m_type = 0x81;
    msg.m_C = 2;
    msg.m_10 = 8;
    msg.m_data = d;
    msg.m_size = 8;
    func_00200C00(m_queue, &msg);
    return true;
}
