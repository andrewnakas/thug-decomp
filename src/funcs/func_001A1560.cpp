extern "C" void* func_002A52F0(void* net, int id);
extern "C" int func_002B1FC8(void* p);
extern "C" int func_002B30A0(void* p);
extern "C" void* func_002A39E0(void* net, int i);
extern "C" int func_001A1448(int idx, float v);
extern "C" void func_00200C00(void* conn, void* msg);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E72B0(void* s, unsigned int name, float v);
extern "C" void func_001E6AE8(void* s, int flags);
extern void* D_00392068;
extern char D_0038CBCD;

struct Comp_001A1560 {
    int m_base[5];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual int Call(unsigned int name, void* params, void* script);
};

extern "C" Comp_001A1560* func_001A0718(void* p);

struct Msg_001A1560 {
    unsigned char m_id;
    unsigned char m1;
    unsigned short m_size;
    void* m_data;
    int m8[3];
    int m14;
    int m18[2];
};

extern "C" void func_001FA800(Msg_001A1560* msg);

struct Data_001A1560 {
    char m0;
    char m1;
};

struct Info_001A1560 {
    int m_pad[6];
    union {
        unsigned short m18;
        volatile int m18i;
    };
};

struct C_001A1560 {
    int m_pad[3];
    Info_001A1560* mC;
    void Set(float* v, int send);
};

void C_001A1560::Set(float* v, int send)
{
    if (send) {
        void* net = D_00392068;
        void* p = func_002A52F0(net, mC->m18);
        if (p && func_002B1FC8(p)) {
            void* conn = func_002A39E0(net, func_002B30A0(p));
            Data_001A1560 data;
            data.m0 = 0;
            data.m0 |= func_001A1448(0, v[0]);
            data.m0 |= func_001A1448(1, v[1]) << 2;
            data.m0 |= func_001A1448(2, v[2]) << 3;
            data.m0 |= func_001A1448(3, v[3]) << 4;
            data.m0 |= func_001A1448(4, v[4]) << 5;
            data.m1 = mC->m18i;
            if (D_0038CBCD != data.m0) {
                Msg_001A1560 msg;
                func_001FA800(&msg);
                msg.m_id = 0x3C;
                msg.m_size = 2;
                msg.m14 = 1;
                msg.m_data = &data;
                func_00200C00(conn, &msg);
                D_0038CBCD = data.m0;
            }
        }
    }
    if (func_001A0718(this)) {
        void* s = func_001E6978(func_001190D0(8));
        func_001E72B0(s, 0xFD266A26, v[0]);
        func_001E72B0(s, 0x642F3B9C, v[1]);
        func_001E72B0(s, 0x0F43FD49, v[2]);
        func_001E72B0(s, 0x964AACF3, v[3]);
        func_001E72B0(s, 0xF90B0824, v[4]);
        func_001A0718(this)->Call(0xEA6D0EFD, s, 0);
        if (s) func_001E6AE8(s, 3);
    }
}
