struct Stream_00111CF8 {
    char pad0[0x10];
    int m_10;
    unsigned char m_14;
    char pad15[0x1C - 0x15];
    int m_1C;
    int m_20;
    int m_24;
    volatile int m_28;
    volatile int m_2C;
    char pad30[0x34 - 0x30];
    volatile int m_34;
    int NextId() { return ++m_34; }
    char pad38[0x3C - 0x38];
    volatile int m_3C;
};

struct Request_00111CF8 {
    char pad0[0x10];
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    char pad20[0x68 - 0x20];
    short m_68;
    char m_6A;
    char m_6B;
    int m_6C;
};

extern int D_0038881C;
extern int D_00388C84;
extern volatile int D_00388C90;

extern "C" int func_00112238(Request_00111CF8* req, Stream_00111CF8* s, int wait, int id);
extern "C" int func_0010E4B0(Stream_00111CF8* s);

extern "C" int func_00111CF8(Stream_00111CF8* s, int sector, int async, int size)
{
    Request_00111CF8 req;
    if (!D_0038881C) {
        return 0;
    }
    s->m_2C = 0;
    s->m_28 = D_00388C84;
    s->m_1C = async;
    s->m_24 = size;
    s->m_10 = 1;
    req.m_6C = 1;
    req.m_18 = sector;
    req.m_1C = s->m_28;
    req.m_6A = 0;
    req.m_6B = s->m_14;
    req.m_10 = s->m_20;
    req.m_14 = size;
    D_00388C90++;
    s->NextId();
    req.m_68 = 0;
    int r = func_00112238(&req, s, 1, -1);
    if (s->m_1C) {
        return func_0010E4B0(s) >= 0;
    }
    s->m_3C = r | 0x80000000;
    return 1;
}
