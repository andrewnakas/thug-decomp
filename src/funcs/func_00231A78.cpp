extern char D_00371C78[];

struct Net_00231A78;
extern Net_00231A78* D_00392068;

struct MsgDesc_00231A78 {
    unsigned char m_Id;
    unsigned char pad1;
    unsigned short m_Length;
    void* m_Data;
    int pad8;
    int m_Priority;
    unsigned char m_Queue;
    char pad11[0xF];
};

struct Iter_00231A78 {
    int m_0;
    int m_4;
    void* m_vtbl;
    Iter_00231A78() { m_vtbl = D_00371C78; m_4 = 0; }
    ~Iter_00231A78() { m_vtbl = D_00371C78; }
};

struct Info_00231A78 {
    char pad0[0x18];
    int m18;
};

struct Conn_00231A78 {
    char pad0[0x18];
    Info_00231A78* m18;
    int GetId() { return m18->m18; }
};

struct Data_00231A78 {
    int m0;
    char pad4[0x34 - 0x4];
    int m34;
    float m38;
    char m3C;
};

struct Obj_00231A78 {
    char pad0[0x20B4];
    int m20B4;
};

extern "C" Conn_00231A78* func_002A5248(Net_00231A78* net, Obj_00231A78* id);
extern "C" Conn_00231A78* func_002A53F8(Net_00231A78* net, Iter_00231A78* it, int a);
extern "C" Conn_00231A78* func_002A5490(Net_00231A78* net, Iter_00231A78* it, int a);
extern "C" void func_001FA800(MsgDesc_00231A78* desc);
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F938(void* p);
extern "C" int func_00202768(Obj_00231A78* a);
extern "C" int func_002B3080(Conn_00231A78* c);
extern "C" void func_001FF970(void* client, int conn, MsgDesc_00231A78* desc);

struct Cmd_00231A78 {
    Data_00231A78* m0;
    unsigned char m4;
    char pad5[3];
    unsigned short m8;
    char padA[0x10 - 0xA];
    void* m10;
    Obj_00231A78* m14;
    char pad18[0x1C - 0x18];
    void* m1C;
    int Run();
};

int Cmd_00231A78::Run()
{
    Net_00231A78* net = D_00392068;
    Iter_00231A78 it;
    MsgDesc_00231A78 desc;
    Conn_00231A78* self = func_002A5248(net, m14);
    if (!self)
        return 3;
    for (Conn_00231A78* c = func_002A53F8(net, &it, 1); c; c = func_002A5490(net, &it, 1)) {
        func_001FA800(&desc);
        if (c == self)
            continue;
        desc.m_Data = m0;
        desc.m_Length = m8;
        desc.m_Id = m4;
        if (desc.m_Id == 0x3A || desc.m_Id == 0x4C || desc.m_Id == 0x89) {
            desc.m_Priority = 2;
            desc.m_Queue = 8;
        } else if (desc.m_Id == 0x83) {
            void* sk = m1C;
            if (func_0024F938(func_0022E358(sk)) == 0x3D6D444F ||
                func_0024F938(func_0022E358(sk)) == (int)0xBFF33600) {
                Data_00231A78* d = m0;
                if (d->m38 <= 10.0f && d->m34 < 0xF1) {
                    d->m3C = self->GetId();
                    Obj_00231A78* o = m14;
                    d->m0 = func_00202768(o) ? 0 : o->m20B4;
                }
            }
        }
        func_001FF970(m10, func_002B3080(c), &desc);
    }
    return 1;
}
