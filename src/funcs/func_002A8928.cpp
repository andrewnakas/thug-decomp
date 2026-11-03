extern char D_00371C78[];

struct Iter_002A8928 {
    int m0;
    int m4;
    void* m8;
    Iter_002A8928() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A8928() { m8 = D_00371C78; }
};

struct Data_002A8928 {
    unsigned char m0;
    unsigned char m1;
};

struct Msg_002A8928 {
    unsigned char type;
    char pad1;
    short size;
    Data_002A8928* data;
    char pad8[4];
    int mC;
    unsigned char m10;
    char pad11[0xF];
};

extern void* D_00392068;
extern char D_003921A0[];
extern char D_003789D8[];
extern "C" void func_001FA800(Msg_002A8928* m);
extern "C" void func_001E7E58(void* p, char* name, int* out, int v);
struct Sk_002A8928;
extern "C" Sk_002A8928* func_002A52F0(void* self, unsigned short id);
extern "C" void* func_002A39D8(void* m);
extern "C" void* func_002A53F8(void* self, Iter_002A8928* it, int a);
extern "C" void* func_002A5490(void* self, Iter_002A8928* it, int a);
extern "C" int func_002B1FC8(void* item);
extern "C" int func_002B3080(void* item);
extern "C" void func_001FF970(void* q, int id, Msg_002A8928* m);
struct Comp_002A8928 {
    char pad[0x1C];
    void* m1C;
};
struct Sk_002A8928 {
    char pad[0x18];
    void* m18;
    char pad1C[0x14D - 0x1C];
    unsigned char m14D;
    unsigned long IsSel() { unsigned long v = m14D; return v >> 7; }
};
extern "C" Comp_002A8928* func_00185578(void* p, unsigned int id);
extern "C" int func_002392B8(void* p);
extern "C" void func_00239198(void* p, int v);
extern "C" int func_002B22C8(Sk_002A8928* s);
extern "C" void func_002B2328(Sk_002A8928* s, int v);

bool Cmd_002A8928(void* params, void* script)
{
    void* mgr = D_00392068;
    Iter_002A8928 it;
    Data_002A8928 d;
    Msg_002A8928 msg;
    int a;
    func_001FA800(&msg);
    func_001E7E58(params, D_003921A0, &a, 0);
    Sk_002A8928* sk = func_002A52F0(mgr, a);
    if (!sk) return true;
    if (sk->IsSel()) return true;
    int c = func_002B22C8(sk);
    d.m0 = a;
    msg.data = &d;
    msg.size = 2;
    msg.type = 0x72;
    d.m1 = c;
    msg.mC = 2;
    msg.m10 = 8;
    void* q = func_002A39D8(mgr);
    void* e = func_002A53F8(mgr, &it, 1);
    if (e) do {
        if (func_002B1FC8(e)) {
            void* x = func_00185578(sk->m18, 0xD262802F)->m1C;
            func_00239198(x, func_002392B8(x) + 1);
            func_002B2328(sk, c);
        } else
            func_001FF970(q, func_002B3080(e), &msg);
        e = func_002A5490(mgr, &it, 1);
    } while (e);
    return true;
}
