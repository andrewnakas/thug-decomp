extern char D_00371C78[];
extern char D_00378DC8[];

struct Iter_002AFB68 {
    int m0;
    int m4;
    void* m8;
    Iter_002AFB68() { m4 = 0; m8 = D_00371C78; }
    ~Iter_002AFB68() { m8 = D_00371C78; }
};

struct Msg_002AFB68 {
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

struct Elem_002AFB68 {
    char pad0[0x18];
    void* m18;
};

extern void* D_0038FC78;
extern "C" Msg_002AFB68* func_001FA800(Msg_002AFB68* m);
extern "C" Elem_002AFB68* func_002A52F0(void* s, unsigned short id);
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F938(void* p);
extern "C" int func_001F0D78(char* s);
extern "C" Elem_002AFB68* func_002A53F8(void* self, Iter_002AFB68* it, int a);
extern "C" Elem_002AFB68* func_002A5490(void* self, Iter_002AFB68* it, int a);
extern "C" void* func_002A39D8(void* s);
extern "C" int func_002B3080(Elem_002AFB68* o);
extern "C" void func_001FF970(void* q, int id, Msg_002AFB68* m);

struct Obj_002AFB68 {
    signed char* m0;
    char pad4[0x18];
    void* m1C;
    int Handle();
};

int Obj_002AFB68::Handle()
{
    char buf[2];
    Msg_002AFB68 msg;
    func_001FA800(&msg);
    void* mgr = m1C;
    signed char* d = m0;
    Iter_002AFB68 it;
    void* sk = D_0038FC78;
    Elem_002AFB68* e = func_002A52F0(mgr, d[0]);
    if (!e || !e->m18 || func_0024F938(func_0022E358(sk)) != func_001F0D78(D_00378DC8))
        return 3;
    buf[0] = d[0];
    buf[1] = d[1];
    void* q = func_002A39D8(mgr);
    msg.m_data = buf;
    msg.m_size = 2;
    msg.m_type = 0x68;
    msg.m_C = 2;
    msg.m_10 = 8;
    for (e = func_002A53F8(mgr, &it, 1); e; e = func_002A5490(mgr, &it, 1))
        func_001FF970(q, func_002B3080(e), &msg);
    return 1;
}
