extern "C" void* memcpy(void* d, const void* s, unsigned int n);
extern "C" void* func_002A52F0(void* net, int id);
extern "C" int func_002B1FC8(void* p);
extern "C" int func_002B30A0(void* p);
extern "C" void* func_002A39E0(void* net, int i);
extern "C" void func_00200C00(void* conn, void* msg);
extern void* D_00392068;

struct Comp_001A0F78 {
    int m_base[5];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void Apply(unsigned int name, float a, float b, int k, int arg, float c, float d);
};

struct Msg_001A0F78 {
    unsigned char m_id;
    unsigned char m1;
    unsigned short m_size;
    void* m_data;
    int m8[3];
    int m14;
    int m18[2];
};

extern "C" void func_001FA800(Msg_001A0F78* msg);

struct Info_001A0F78 {
    int m_pad[6];
    union {
        unsigned short m18;
        volatile int m18i;
    };
};

struct Data_001A0F78 {
    unsigned int m_name;
    char m_k;
    char m_id;
    short m_a;
    short m_b;
    short m_c;
    short m_d;
};

struct C_001A0F78 {
    int m_pad[3];
    Info_001A0F78* mC;
};

extern "C" Comp_001A0F78* func_001A0718(C_001A0F78* p);
extern "C" int func_001A1AE0(C_001A0F78* p);
extern "C" void func_001A2728(C_001A0F78* p);
extern "C" void func_001A07E0(C_001A0F78* p, float c);
extern "C" int func_001A2CE0(C_001A0F78* p);
extern "C" void func_001A11C0(C_001A0F78* p);
extern "C" void func_001A11F0(C_001A0F78* p, unsigned int name);

extern "C" void func_001A0F78(C_001A0F78* self, unsigned int name, int send, float a, float b, int k, float c, float d)
{
    name = name ? name : 0x1CA1FF20;
    if (send) {
        void* net = D_00392068;
        void* p = func_002A52F0(net, self->mC->m18);
        if (p && func_002B1FC8(p)) {
            Data_001A0F78 data;
            Msg_001A0F78 msg;
            func_001FA800(&msg);
            void* conn = func_002A39E0(net, func_002B30A0(p));
            data.m_name = name;
            data.m_id = self->mC->m18i;
            data.m_k = k;
            data.m_a = (int)(a * 4096.0f);
            data.m_b = (int)(b * 4096.0f);
            data.m_c = (int)(c * 4096.0f);
            data.m_d = (int)(d * 4096.0f);
            char buf[0x520];
            char* w = buf;
            *w++ = data.m_k;
            *w++ = data.m_id;
            memcpy(w, &data.m_name, 4);
            w += 4;
            memcpy(w, &data.m_a, 2);
            w += 2;
            memcpy(w, &data.m_b, 2);
            w += 2;
            memcpy(w, &data.m_c, 2);
            w += 2;
            memcpy(w, &data.m_d, 2);
            msg.m_data = buf;
            msg.m_size = 0xE;
            msg.m_id = 0x29;
            func_00200C00(conn, &msg);
        }
    }
    if (c == 0.0f || !func_001A1AE0(self)) {
        func_001A2728(self);
    }
    func_001A07E0(self, c);
    func_001A0718(self)->Apply(name, a, b, k, func_001A2CE0(self), c, d);
    func_001A11C0(self);
    func_001A11F0(self, name);
}
