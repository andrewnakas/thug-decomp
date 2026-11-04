extern char D_00371C78[];
extern char D_003784B0[];
extern char D_00378260[];

struct Iter_002A4C78 {
    int m0;
    int m4;
    void* m8;
    Iter_002A4C78() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A4C78() { m8 = D_00371C78; }
};

struct Msg_002A4C78 {
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

extern "C" void func_001FA800(Msg_002A4C78* m);
extern "C" int func_002B1FC8(void* s);
extern "C" int func_002B2280(void* s);
extern "C" void func_002B2290(void* s);
extern "C" int func_002B3080(void* s);
extern "C" int func_001F0D78(char* s);
extern "C" void* func_00202EF8(void* p, int crc);
extern "C" int func_001E8A50(void* p, char* name, void* out, int a);
extern "C" void func_001FF970(void* q, int id, Msg_002A4C78* m);

struct Obj_002A4C78 {
    char pad[0x14];
    void* m14;
    char pad2[0xBC - 0x18];
    char mBC[4];
    void Run();
};

extern "C" void* func_002A53F8(Obj_002A4C78* self, Iter_002A4C78* it, int a);
extern "C" void* func_002A5490(Obj_002A4C78* self, Iter_002A4C78* it, int a);

void Obj_002A4C78::Run()
{
    Iter_002A4C78 it;
    Msg_002A4C78 msg;
    func_001FA800(&msg);
    int buf[4];
    for (void* s = func_002A53F8(this, &it, 0); s; s = func_002A5490(this, &it, 0)) {
        if (!func_002B1FC8(s) && func_002B2280(s)) {
            func_002B2290(s);
            func_001E8A50(func_00202EF8(mBC, func_001F0D78(D_003784B0)), D_00378260, buf, 1);
            msg.m_data = buf;
            msg.m_size = 4;
            msg.m_type = 0x5F;
            msg.m_C = 2;
            msg.m_10 = 8;
            func_001FF970(m14, func_002B3080(s), &msg);
            break;
        }
    }
}
