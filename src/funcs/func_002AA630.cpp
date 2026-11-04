extern char D_00371C78[];

struct Iter_002AA630 {
    int m0;
    int m4;
    void* m8;
    Iter_002AA630() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002AA630() { m8 = D_00371C78; }
};

struct Msg_002AA630 {
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

struct Small_002AA630 {
    unsigned char m0;
    unsigned char m1;
    char name[0x10];
};

struct Skater_002AA630 {
    char pad0[0x18];
    void* m18;
    char pad1c[0x34 - 0x1C];
    char name[0x10];
    char pad44[0x14C - 0x44];
    int m14C;
};

extern void* D_00392068;
extern void* D_0038FC78;
extern "C" void func_001FA800(Msg_002AA630* m);
extern "C" Skater_002AA630* func_002A53F8(void* self, Iter_002AA630* it, int a);
extern "C" Skater_002AA630* func_002A5490(void* self, Iter_002AA630* it, int a);
extern "C" int func_002A1A38(void* s);
extern "C" int func_002B1FE8(Skater_002AA630* s);
extern "C" void func_002A5A88(void* m, Skater_002AA630* s, int a);
extern "C" void func_0022CF98(void* a, void* b);
extern "C" void* func_002A39E0(void* s, int a);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" void func_00200C00(void* w, Msg_002AA630* m);

bool Cmd_002AA630(void* params, void* script)
{
    void* m = D_00392068;
    Iter_002AA630 it;
    Small_002AA630 sm;
    Msg_002AA630 msg;
    int i = 0;
    for (Skater_002AA630* p = func_002A53F8(m, &it, 1); p; p = func_002A5490(m, &it, 1), i++) {
        if (p->m14C & 0x400) {
            if (func_002A1A38(m)) {
                void* x = p->m18;
                int r = func_002B1FE8(p);
                func_002A5A88(m, p, 4);
                if (!r) func_0022CF98(D_0038FC78, x);
            } else {
                func_001FA800(&msg);
                void* w = func_002A39E0(m, 0);
                sm.m0 = 0;
                sm.m1 = i;
                func_00331A9C(sm.name, p->name);
                msg.m_data = &sm;
                msg.m_size = 0x12;
                msg.m_type = 0x61;
                msg.m_C = 2;
                msg.m_10 = 8;
                func_00200C00(w, &msg);
            }
            break;
        }
    }
    return true;
}
