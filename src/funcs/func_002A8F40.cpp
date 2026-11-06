extern char D_00371C78[];

struct Iter_002A8F40 {
    int m0;
    int m4;
    void* m8;
    Iter_002A8F40() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A8F40() { m8 = D_00371C78; }
};

struct Msg_002A8F40 {
    unsigned char type;
    char pad1;
    short size;
    void* data;
    char pad8[4];
    int mC;
    unsigned char m10;
    char pad11[0xF];
};

struct Obj_002A8F40 {
    char pad[0x14];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual int Refresh();
};


struct Mgr_002A8F40 {
    char pad[0xA0];
    void* mA0;
    void* mA4;
    char padA8[0x18C - 0xA8];
    int m18C;
};

extern Mgr_002A8F40* D_00392068;
extern char* D_0038C308;
extern void* D_0038FC78;
extern unsigned int D_0039416C;
extern char D_00378888[];
extern char D_003789F8[];
extern char D_00378A18[];
extern char D_00378A28[];

extern "C" int func_00104968(void* p);
extern "C" int func_002A19A8(Mgr_002A8F40* s);
extern "C" int func_002A7668(Mgr_002A8F40* s);
extern "C" int func_001F0D78(char* s);
extern "C" unsigned int func_0010FC30();
extern "C" void func_00105260(void* p, void* q);
extern "C" int func_002A1968(Mgr_002A8F40* s);
extern "C" char* func_002A23F0(Mgr_002A8F40* s);
extern "C" void func_002A7B50(Mgr_002A8F40* s, int a, int b, char* c, int d, int e, char* f, int g, int h);
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F540(void* p);
extern "C" Msg_002A8F40* func_001FA800(Msg_002A8F40* m);
extern "C" void* func_002A39D8(Mgr_002A8F40* s);
extern "C" void* func_002A53F8(Mgr_002A8F40* s, Iter_002A8F40* it, int a);
extern "C" void* func_002A5490(Mgr_002A8F40* s, Iter_002A8F40* it, int a);
extern "C" int func_002B3080(void* item);
extern "C" int func_002B1FC8(void* item);
extern "C" void func_001FF970(void* q, int id, Msg_002A8F40* m);
extern "C" void* func_00240850();
extern "C" int func_0023C040(void* w);
extern "C" Obj_002A8F40* func_0023BB50(void* w, int i);
extern "C" int func_002463A0(Obj_002A8F40* o);
extern "C" int func_00246258(Obj_002A8F40* o);
extern "C" void* memcpy(void* d, const void* s, unsigned int n);

static inline void Show_002A8F40(Mgr_002A8F40* s, int crc, char* name, int ms)
{
    func_002A7B50(s, 1, crc, name, 0, 0, D_00378A18, 1, ms);
}

bool Cmd_002A8F40()
{
    Mgr_002A8F40* s = D_00392068;
    char* g = D_0038C308;
    void* ctl = D_0038FC78;
    if (func_00104968(s->mA0) || func_00104968(s->mA4)) return true;
    s->m18C = 1;
    if (func_002A19A8(s)) {
        if (func_002A7668(s) == func_001F0D78(D_00378888))
            D_0039416C = func_0010FC30() + 8000;
        else
            D_0039416C = func_0010FC30() + 3000;
    } else {
        D_0039416C = func_0010FC30();
    }
    func_00105260(g + 8, s->mA0);
    if (func_002A19A8(s)) {
        if (func_002A1968(s) == 1)
            Show_002A8F40(s, func_001F0D78(D_003789F8), func_002A23F0(s), 3000);
        else
            Show_002A8F40(s, func_001F0D78(D_00378A28), func_002A23F0(s), 3000);
        if (func_0024F540(func_0022E358(ctl))) {
            Iter_002A8F40 it;
            Msg_002A8F40 msg;
            Iter_002A8F40* p = &it;
            func_001FA800(&msg);
            void* q = func_002A39D8(s);
            msg.type = 0x7A;
            msg.mC = 2;
            msg.m10 = 8;
            void* e = func_002A53F8(s, p, 1);
            if (e) do {
                func_001FF970(q, func_002B3080(e), &msg);
                e = func_002A5490(s, &it, 1);
            } while (e);
        }
    }
    if (func_002A19A8(s) && func_002A7668(s) == func_001F0D78(D_00378888)) {
        Msg_002A8F40 msg;
        unsigned char buf[0x1000];
        func_001FA800(&msg);
        Iter_002A8F40 it;
        int v;
        int i = 0;
        void* world = func_00240850();
        void* q = func_002A39D8(s);
        unsigned char* out = buf;
        *out++ = 1;
        int n = func_0023C040(world);
        for (; i < n; i++) {
            Obj_002A8F40* o = func_0023BB50(world, i);
            if (func_002463A0(o)) {
                o->Refresh();
                v = func_00246258(o);
                memcpy(out, &v, 4);
                out += 4;
            }
        }
        v = 0;
        memcpy(out, &v, 4);
        out += 4;
        msg.size = out - buf;
        msg.type = 0x6D;
        msg.mC = 2;
        msg.m10 = 8;
        msg.data = buf;
        void* e = func_002A53F8(s, &it, 1);
        if (e) do {
            if (!func_002B1FC8(e))
                func_001FF970(q, func_002B3080(e), &msg);
            e = func_002A5490(s, &it, 1);
        } while (e);
    }
    return true;
}
