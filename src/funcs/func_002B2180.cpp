struct Msg_002B2180 {
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

extern void* D_00392068;
extern "C" void func_001FA800(Msg_002B2180* m);
extern "C" int func_002A19A8(void* s);
extern "C" int func_002A1A38(void* s);
extern "C" int func_002A1968(void* s);
extern "C" void* func_002A39D8(void* s);
extern "C" void func_001FF970(void* q, int id, Msg_002B2180* m);
extern "C" int func_002A5780(void* s);
extern "C" void func_002A4C78(void* s);

struct Obj_002B2180 {
    char pad[0x14C];
    int m14C;
    void Finish();
};

extern "C" int func_002B1FC8(Obj_002B2180* o);
extern "C" int func_002B3080(Obj_002B2180* o);

void Obj_002B2180::Finish()
{
    void* s = D_00392068;
    m14C |= 0x20;
    if (!func_002A19A8(s))
        return;
    if (!func_002A1A38(s))
        return;
    if (func_002B1FC8(this))
        return;
    switch (func_002A1968(s)) {
    case 0:
        break;
    case 1: {
        Msg_002B2180 msg;
        func_001FA800(&msg);
        void* q = func_002A39D8(s);
        msg.m_type = 0x5E;
        msg.m_C = 2;
        msg.m_10 = 8;
        func_001FF970(q, func_002B3080(this), &msg);
        break;
    }
    case 2:
        if (!func_002A5780(s))
            func_002A4C78(s);
        break;
    }
}
