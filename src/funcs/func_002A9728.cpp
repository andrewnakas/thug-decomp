extern char D_00371C78[];
extern char D_00378A58[];

struct Iter_002A9728 {
    int m0;
    int m4;
    void* m8;
    Iter_002A9728() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A9728() { m8 = D_00371C78; }
};

struct MsgB_002A9728 {
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
struct Msg_002A9728 : MsgB_002A9728 {
    Msg_002A9728();
};

struct Info_002A9728 {
    char pad[0x18];
    int m18;
};

struct Skater_002A9728 {
    char pad[0x18];
    Info_002A9728* m18;
    char pad1c[0x30 - 0x1C];
    int m30;
};

extern void* D_00392068;
extern void* D_0038FC78;
extern "C" void func_001FA800(MsgB_002A9728* m);
extern "C" int func_001E7DE8(void* p, unsigned int key, int* out, int req);
extern "C" int func_002A1A38(void* s);
extern "C" void* func_002A39E0(void* s, int a);
extern "C" void* func_002A39D8(void* s);
extern "C" void func_00200C00(void* w, MsgB_002A9728* m);
extern "C" void* func_0022E358(void* g);
extern "C" int func_0024F540(void* p);
extern "C" void func_0024F418(void* p, int n);
extern "C" int func_0022DD38(void* g);
extern "C" void func_0022CF78(void* g, int v);
extern "C" void func_001F0370(char* s, int a, int b, int c);
extern "C" Skater_002A9728* func_002A53F8(void* self, Iter_002A9728* it, int a);
extern "C" Skater_002A9728* func_002A5490(void* self, Iter_002A9728* it, int a);
extern "C" int func_002B1FC8(Skater_002A9728* s);
extern "C" int func_002B3080(Skater_002A9728* s);
extern "C" void func_001FF970(void* q, int id, Msg_002A9728* m);

bool Cmd_002A9728(void* params, void* script)
{
    void* m = D_00392068;
    void* g = D_0038FC78;
    Iter_002A9728 it1;
    Iter_002A9728 it2;
    unsigned char pair[2];
    Msg_002A9728 msg;
    MsgB_002A9728 msg2;
    unsigned char b74[1];
    unsigned char b75[1];
    int val;
    val = 0;
    func_001E7DE8(params, 0, &val, 0);
    if (!func_002A1A38(m)) {
        func_001FA800(&msg2);
        void* w = func_002A39E0(m, 0);
        b74[0] = val;
        msg2.m_data = b74;
        msg2.m_size = 1;
        msg2.m_type = 0x66;
        msg2.m_C = 2;
        msg2.m_10 = 8;
        func_00200C00(w, &msg2);
        return true;
    }
    if (val > 0 && !func_0024F540(func_0022E358(g))) {
        func_0024F418(func_0022E358(g), val);
        if (func_0022DD38(g)) {
            func_001F0370(D_00378A58, 0, func_0022DD38(g), 0);
            func_0022CF78(g, func_0022DD38(g));
        }
    } else {
        func_0024F418(func_0022E358(g), val);
    }
    void* q = func_002A39D8(m);
    if (q) {
        b75[0] = val;
        msg.m_data = b75;
        msg.m_size = 1;
        msg.m_type = 0x69;
        msg.m_C = 2;
        msg.m_10 = 8;
        Skater_002A9728* p;
        for (p = func_002A53F8(m, &it2, 1); p; p = func_002A5490(m, &it2, 1)) {
            if (!func_002B1FC8(p)) func_001FF970(q, func_002B3080(p), &msg);
        }
        msg.m_data = pair;
        msg.m_size = 2;
        msg.m_type = 0x68;
        msg.m_C = 2;
        msg.m_10 = 8;
        for (Skater_002A9728* s = func_002A53F8(m, &it1, 0); s; s = func_002A5490(m, &it1, 0)) {
            if (s->m30 >= val) {
                pair[1] = 0;
                int ty = s->m18->m18;
                pair[0] = ty;
                for (p = func_002A53F8(m, &it2, 1); p; p = func_002A5490(m, &it2, 1)) {
                    if (!func_002B1FC8(p)) func_001FF970(q, func_002B3080(p), &msg);
                }
                s->m30 = 0;
            }
        }
    }
    return true;
}
