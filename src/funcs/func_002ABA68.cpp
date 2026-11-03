struct Msg_002ABA68 {
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

extern void* D_0038FC78;
extern "C" void func_001FA800(Msg_002ABA68* m);
extern "C" void func_00200C00(void* q, Msg_002ABA68* m);
extern "C" void func_002A8250(void* s, int v);
extern "C" int func_002A1A38(void* s);
extern "C" void* func_002A39E0(void* s, int v);
extern "C" void func_00235878(void* g, void* p, int i);

struct Obj_002ABA68 {
    char pad[0x10];
    void* m10;
    char pad2[0x1C - 0x14];
    void* m1C;
    bool Start();
};

bool Obj_002ABA68::Start()
{
    Msg_002ABA68 msg;
    void* g = D_0038FC78;
    func_001FA800(&msg);
    void* s = m1C;
    func_002A8250(s, 5);
    msg.m_type = 0x54;
    msg.m_C = 2;
    msg.m_10 = 8;
    func_00200C00(m10, &msg);
    if (!func_002A1A38(s)) {
        for (int i = 0; i < 2; i++) {
            void* p = func_002A39E0(s, i);
            if (p)
                func_00235878(g, p, i);
        }
    }
    return true;
}
