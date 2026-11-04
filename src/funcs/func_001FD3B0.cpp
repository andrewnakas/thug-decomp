extern "C" void* func_001FA800(void* self);
extern "C" void func_001FF970(int a, int b, void* msg);
extern "C" int func_002012A0(int a);
extern "C" int func_00202768(void* a);
extern "C" void func_00200C68(int a, int b, int c, int d, int e, unsigned short f, int g);

struct Msg_001FD3B0 {
    unsigned char m_type;
    char pad1[7];
    int m_8;
    int m_C;
    char pad10[0x10];
};

struct Inner_001FD3B0 {
    char pad0[0x48];
    int m_48;
    int m_4C;
    unsigned short m_50;
};

struct Obj_001FD3B0 {
    char pad0[0x10];
    int m_10;
    Inner_001FD3B0* m_14;
    int m_18;
    int Run();
};

int Obj_001FD3B0::Run()
{
    Msg_001FD3B0 msg;
    func_001FA800(&msg);
    if (m_18 & 1) {
        if (func_002012A0(m_10)) {
            func_00200C68(m_10, 4, 0, 0, m_14->m_4C, m_14->m_50, 0);
            return 1;
        }
        return 3;
    }
    if (func_00202768(m_14)) {
        msg.m_type = 4;
        msg.m_8 = 0xFF;
        msg.m_C = 1;
        func_001FF970(m_10, m_14->m_48, &msg);
        return 1;
    }
    return 3;
}
