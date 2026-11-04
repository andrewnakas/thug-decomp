struct Msg_002B0AB0 {
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

struct S_002B0AB0 {
    char pad[0x10];
    void* m10;
};

extern char D_00379518[];
extern char D_00378E28[];
extern "C" void func_001FA800(Msg_002B0AB0* m);
extern "C" void func_00200C00(void* q, Msg_002B0AB0* m);
extern "C" void* func_002A6070(S_002B0AB0* s);
extern "C" int func_001F0D78(char* s);
extern "C" int func_00202F78(void* p, int a, int b);
extern "C" int func_002DA0F0(void* p, int a, int b, char* out);

struct Obj_002B0AB0 {
    int m0;
    char pad[0xC];
    void* m10;
    char pad2[0x1C - 0x14];
    S_002B0AB0* m1C;
    bool Send();
};

bool Obj_002B0AB0::Send()
{
    Msg_002B0AB0 msg;
    char data[33];
    func_001FA800(&msg);
    S_002B0AB0* s = m1C;
    void* a = func_002A6070(s);
    int c = func_001F0D78(D_00379518);
    func_002DA0F0(s->m10, m0, func_00202F78(a, c, func_001F0D78(D_00378E28)), data);
    msg.m_type = 0x7D;
    msg.m_data = data;
    msg.m_C = 2;
    msg.m_10 = 8;
    msg.m_size = 0x21;
    func_00200C00(m10, &msg);
    return true;
}
