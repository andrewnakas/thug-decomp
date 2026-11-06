/* fuzzy: 97.9 */
struct Msg_002AC6D8 {
    unsigned char m0;
    char pad1;
    unsigned short m2;
    void* m4;
    char pad[0x18];
};

struct Ent_002AC6D8 {
    char m0;
    char m1[0x10];
    signed char m11;
    char pad12[2];
    void* m14;
    int m18;
    void* m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
};

struct Info_002AC6D8 {
    char pad0[4];
    signed char m4;
    char pad5[0x10 - 5];
    int m10;
    int m14;
    signed char m18;
    char pad19[3];
    int m1C;
    char m20[0x10];
    char m30[0x10];
};

struct Sk_002AC6D8 {
    char pad0[0x48];
    int m48;
    int m4C;
    unsigned short m50;
    char pad52[0x68 - 0x52];
    int m68;
};

extern "C" void func_002B3100(Ent_002AC6D8* e);
extern "C" void func_002B3168(Ent_002AC6D8* e, int flags);
extern "C" int func_00202778(Sk_002AC6D8* s);
extern "C" int func_002012A0(void* p);
extern "C" Sk_002AC6D8* func_001FEAE8(void* p, int a, unsigned short b, int c);
extern "C" void func_00202B38(Sk_002AC6D8* s, int v);
extern "C" void func_002027E8(Sk_002AC6D8* s, int v);
extern "C" int func_002B0E70(void* mgr, int* out, Info_002AC6D8* info, Sk_002AC6D8* s);
extern "C" void func_001FA800(Msg_002AC6D8* m);
extern "C" void func_001FF970(void* q, int id, Msg_002AC6D8* m);
extern "C" void func_00202710(Sk_002AC6D8* s);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" int func_002A50D8(void* mgr);
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F938(void* p);
extern "C" int func_002A8560(void* mgr);
extern "C" int func_00202768(Sk_002AC6D8* s);
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void* func_0022E3C8(void* p, int id);
extern "C" int func_002616E0(void* p, void* buf, int size, int v);
extern "C" void func_002617C8(void* p, void* buf);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_002A44C0(void* mgr, Ent_002AC6D8* e, int v);
static inline void ClearMask_002AC6D8(Sk_002AC6D8* s, const unsigned int& m) { s->m68 &= ~m; }
static inline void SetMask_002AC6D8(Sk_002AC6D8* s, const unsigned int& m) { s->m68 |= m; }
static inline void Clear_002AC6D8(Sk_002AC6D8* s, int f) { ClearMask_002AC6D8(s, f); }
static inline void Set_002AC6D8(Sk_002AC6D8* s, int f) { SetMask_002AC6D8(s, f); }
static inline void SetData_002AC6D8(Msg_002AC6D8* m, const unsigned char& d) { m->m4 = (void*)&d; }
static inline void Fill_002AC6D8(Msg_002AC6D8* m, unsigned char t, unsigned short l, const unsigned char& d) { m->m2 = l; m->m4 = (void*)&d; m->m0 = t; }
extern void* D_0038FC78;
extern void* D_00388A70;
extern unsigned int D_00388830;

struct Obj_002AC6D8 {
    Info_002AC6D8* m0;
    char pad4[0xC];
    void* m10;
    Sk_002AC6D8* m14;
    int m18;
    void* m1C;
    int Run();
};

int Obj_002AC6D8::Run()
{
    Ent_002AC6D8 e;
    void* g = D_0038FC78;
    func_002B3100(&e);
    void* mgr = m1C;
    Info_002AC6D8* info = m0;
    if (func_00202778(m14)) {
        if ((m18 & 1) && func_002012A0(m10)) {
            Sk_002AC6D8* s = func_001FEAE8(m10, m14->m4C, m14->m50, 2);
            if (info->m18) {
                func_00202B38(s, 0);
                func_002027E8(s, 1000 / D_00388830 * 2);
            } else {
                func_00202B38(s, 1);
                func_002027E8(s, 1000 / D_00388830 * 2);
            }
            m14 = s;
            Msg_002AC6D8 msg;
            int out;
            if (!func_002B0E70(mgr, &out, info, s)) {
                func_001FA800(&msg);
                Fill_002AC6D8(&msg, 0x47, 1, out & 0xFF);
                func_001FF970(m10, m14->m48, &msg);
                func_00202710(m14);
                func_002B3168(&e, 2);
                return 2;
            }
        } else {
            func_002B3168(&e, 2);
            return 3;
        }
    }
    func_00331A9C(e.m1, info->m20);
    e.m11 = func_002A50D8(mgr);
    e.m14 = m14;
    e.m20 = 0;
    e.m2C = info->m10;
    e.m30 = info->m14;
    e.m38 = info->m1C;
    if (info->m4 == 0) {
        if (func_0024F938(func_0022E358(g)) != 0x1C471C60 && !func_002A8560(mgr)) {
            e.m20 |= 0xC;
        }
    } else {
        e.m20 = 4;
    }
    if (func_00202768(m14)) {
        void* buf = func_0010A638(D_00388A70, 0x1000, 1, 0);
        func_002616E0(func_0022E3C8(g, e.m11), buf, 0x1000, 0);
        func_002617C8(e.m1C, buf);
        func_0010A8D8(D_00388A70, buf);
        e.m20 = 1;
        func_002A44C0(mgr, &e, 0);
    } else {
        if (info->m4 == 0) func_002617C8(e.m1C, info->m30);
        func_002A44C0(mgr, &e, 10);
        Clear_002AC6D8(m14, 1);
        Set_002AC6D8(m14, 2);
    }
    func_002B3168(&e, 2);
    return 1;
}
