extern "C" void* func_002A52F0(void* net, int id);
extern "C" int func_002B1FC8(void* p);
extern "C" int func_002B30A0(void* p);
extern "C" void* func_002A39E0(void* net, int i);
extern "C" void func_00200C00(void* conn, void* msg);
extern void* D_00392068;

struct Msg_001A2610 {
    unsigned char m_id;
    unsigned char m1;
    unsigned short m_size;
    void* m_data;
    int m8[3];
    int m14;
    int m18[2];
};

extern "C" void func_001FA800(Msg_001A2610* msg);

struct Obj_001A2610;
extern "C" void func_001A26F8(Obj_001A2610* o, int v);

struct Obj_001A2610 {
    char pad[0x48];
    int m48lo : 29;
    int m48hi : 3;
    int Set(int v)
    {
        int old = m48hi;
        old &= 1;
        func_001A26F8(this, v);
        return old;
    }
    int Method(int id, int v, int unused, int send);
};

int Obj_001A2610::Method(int id, int v, int unused, int send)
{
    if (send) {
        void* net = D_00392068;
        void* p = func_002A52F0(net, (unsigned short)id);
        if (p && func_002B1FC8(p)) {
            unsigned char data[2];
            Msg_001A2610 msg;
            func_001FA800(&msg);
            void* conn = func_002A39E0(net, func_002B30A0(p));
            data[0] = id;
            data[1] = v;
            msg.m_data = data;
            msg.m_size = 2;
            msg.m_id = 0x2C;
            func_00200C00(conn, &msg);
        }
    }
    return Set(v);
}
