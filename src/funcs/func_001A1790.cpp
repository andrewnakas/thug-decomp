extern "C" void* func_002A52F0(void* net, unsigned short id);
extern "C" int func_002B1FC8(void* p);
extern "C" int func_002B30A0(void* p);
extern "C" void* func_002A39E0(void* net, int i);
extern "C" void func_00200C00(void* conn, void* msg);
extern void* D_00392068;
extern signed char D_0038CBCE;

struct Msg_001A1790 {
    unsigned char m_id;
    unsigned char m1;
    unsigned short m_size;
    void* m_data;
    int m8[3];
    int m14;
    int m18[2];
};

extern "C" Msg_001A1790* func_001FA800(Msg_001A1790* msg);
extern "C" void func_001198C8(void* comp, int v);

struct Info_001A1790 {
    int m_pad[6];
    int m18;
};

struct Obj_001A1790 {
    int m_pad[3];
    Info_001A1790* mC;
    void Method(int v, int send);
};

extern "C" void* func_001A0718(Obj_001A1790* p);

void Obj_001A1790::Method(int v, int send)
{
    if (send) {
        void* net = D_00392068;
        int id = mC->m18;
        void* p = func_002A52F0(net, id);
        if (p && func_002B1FC8(p)) {
            void* conn = func_002A39E0(net, func_002B30A0(p));
            unsigned char data[2];
            data[1] = v;
            id = mC->m18;
            data[0] = id;
            if (D_0038CBCE != v) {
                Msg_001A1790 msg;
                func_001FA800(&msg);
                msg.m_data = data;
                msg.m_size = 2;
                msg.m_id = 0x3D;
                func_00200C00(conn, &msg);
                D_0038CBCE = v;
            }
        }
    }
    if (func_001A0718(this))
        func_001198C8(func_001A0718(this), v);
}
