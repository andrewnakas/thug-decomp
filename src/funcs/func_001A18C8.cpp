extern "C" void* func_002A52F0(void* net, int id);
extern "C" int func_002B1FC8(void* p);
extern "C" int func_002B30A0(void* p);
extern "C" void* func_002A39E0(void* net, int i);
extern "C" void func_00200C00(void* conn, void* msg);
extern "C" float func_00119890(void* p);
extern "C" void func_00119880(void* p, float v);
extern "C" long func_0010FA80();
extern "C" int func_0033ECA8(float v);
extern "C" void func_00103F28(char* fmt, int a, int b);
extern void* D_00392068;
extern int D_0038ED10;
extern char D_00362338[];

struct Msg_001A18C8 {
    unsigned char m_id;
    unsigned char m1;
    unsigned short m_size;
    void* m_data;
    int m8[3];
    int m14;
    int m18[2];
};

extern "C" void func_001FA800(Msg_001A18C8* msg);

struct Data_001A18C8 {
    float m0;
    char m4;
};

struct Info_001A18C8 {
    int m_pad[6];
    union {
        unsigned short m18;
        volatile int m18i;
    };
};

struct Node_001A18C8 {
    int m0;
    int m_tag;
    int m8;
    Node_001A18C8* m_next;
    Node_001A18C8* m_prev;
};

static inline Node_001A18C8* Valid_001A18C8(Node_001A18C8* n)
{
    Node_001A18C8* r = 0;
    if (n->m_tag != -1) r = n;
    return r;
}

extern "C" void* func_001A0718(void* p);

struct C_001A18C8 {
    int m_pad[3];
    Info_001A18C8* mC;
    int m10[3];
    Node_001A18C8 m_head;
    void Set(float v, int send, int all);
};

void C_001A18C8::Set(float v, int send, int all)
{
    if (!func_001A0718(this)) return;
    float cur = func_00119890(func_001A0718(this));
    if (!all && __builtin_fabsf(cur - v) < 0.05f) return;
    if (send) {
        void* net = D_00392068;
        void* p = func_002A52F0(net, mC->m18);
        if (p && func_002B1FC8(p)) {
            void* conn = func_002A39E0(net, func_002B30A0(p));
            if (conn) {
                Data_001A18C8 data;
                Msg_001A18C8 msg;
                func_001FA800(&msg);
                data.m0 = v;
                data.m4 = mC->m18i;
                msg.m_size = 8;
                msg.m_id = 0x41;
                msg.m_data = &data;
                func_00200C00(conn, &msg);
            }
        }
    }
    if (all) {
        for (Node_001A18C8* n = Valid_001A18C8(m_head.m_next); n; n = Valid_001A18C8(n->m_next))
            func_00119880(n, v);
    } else {
        func_00119880(func_001A0718(this), v);
    }
    if (D_0038ED10 && !mC->m18i) {
        func_00103F28(D_00362338, func_0010FA80(), func_0033ECA8(v));
    }
}
