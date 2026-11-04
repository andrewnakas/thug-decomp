extern "C" int func_001E88D8(void* params, unsigned int name, void* out, int req);
extern "C" int func_001E84E8(void* params, const char* name, void* out, int req);
extern "C" int func_001E5548(int v, int flag);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_001E73C8(void* s, const char* name, int v);
extern "C" void func_001E6AE8(void* s, int flags);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" int func_002A19A8(void* net);
extern "C" void* func_002A39E0(void* net, int i);
extern "C" void func_00200C00(void* conn, void* msg);
extern char D_0038D148[];
extern char D_0038D150[];
extern char D_0038D158[];
extern void* D_00392068;

struct Comp_001B6E48 {
    int m_base[6];
    virtual void V0();
    virtual void V1();
    virtual void Apply(void* s);
};

struct Msg_001B6E48 {
    unsigned char m_id;
    unsigned char m1;
    unsigned short m_size;
    void* m_data;
    int m_pad[6];
};

extern "C" void func_001FA800(Msg_001B6E48* msg);

struct Data_001B6E48 {
    int m0;
    int m4;
    unsigned char m8;
    unsigned char m9;
};

struct Info_001B6E48 {
    int m_pad[6];
    union { int m18; volatile int m18v; };
};

struct C_001B6E48 {
    int m_pad[3];
    Info_001B6E48* mC;
    int m10[3];
    int m1C[2];
    void* Create(int a, int b);
    void Select(int a);
    void Reset();
    int Call(unsigned int name, void* params);
};

extern "C" void* func_001B7128(C_001B6E48* self, int a, int b);
extern "C" void func_001B7288(C_001B6E48* self, int a);
extern "C" void func_001B7338(C_001B6E48* self);

int C_001B6E48::Call(unsigned int name, void* params)
{
    Data_001B6E48 data;
    Msg_001B6E48 msg;
    Msg_001B6E48 msg2;
    switch (name) {
    case 0x827C6BD1: {
        int a;
        int b = 0;
        int c;
        func_001E88D8(params, 0x7F8C98FE, &a, 1);
        func_001E84E8(params, D_0038D148, &b, 0);
        func_001E84E8(params, D_0038D150, &c, 1);
        int v = func_001E5548(c, 1);
        void* obj = func_001B7128(this, a, v);
        void* s = func_001E6978(func_001190D0(8));
        func_001E6AC8(s, params);
        func_001E73C8(s, D_0038D158, mC->m18);
        ((Comp_001B6E48*)func_00185578(obj, 0x5CB5CB7E))->Apply(s);
        if (s) func_001E6AE8(s, 3);
        void* net = D_00392068;
        if (func_002A19A8(net)) {
            func_001FA800(&msg);
            void* conn = func_002A39E0(net, 0);
            data.m8 = mC->m18v;
            data.m0 = c;
            data.m9 = a;
            data.m4 = b;
            msg.m_size = 12;
            msg.m_id = 0x77;
            msg.m_data = &data;
            func_00200C00(conn, &msg);
        }
        break;
    }
    case 0x742188FA: {
        int a;
        func_001E88D8(params, 0x7F8C98FE, &a, 1);
        func_001B7288(this, a);
        void* net = D_00392068;
        if (func_002A19A8(net)) {
            func_001FA800(&msg2);
            void* conn = func_002A39E0(net, 0);
            data.m8 = mC->m18v;
            data.m9 = a;
            msg2.m_size = 12;
            msg2.m_id = 0x78;
            msg2.m_data = &data;
            func_00200C00(conn, &msg2);
        }
        break;
    }
    case 0xA1BAA25E:
        func_001B7338(this);
        break;
    case 0xCE887492: {
        int i;
        if (func_001E88D8(params, 0x7F8C98FE, &i, 0)) return m1C[i] != 0;
        for (int j = 0; j < 2; j++) {
            if (m1C[j]) return 1;
        }
        return 0;
    }
    default:
        return 2;
    }
    return 1;
}
