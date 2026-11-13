/* force: {"kind": "ga", "before": [126, 145]} */
typedef int qword __attribute__((mode(TI)));
union Vec_0029DD68 {
    qword q;
    struct { float x, y, z, w; } f;
    Vec_0029DD68() {}
    Vec_0029DD68(const Vec_0029DD68& o) { q = o.q; }
};

struct Node_0029DD68 {
    int m0;
    void* m4;
    int m8;
    Node_0029DD68* mC;
    Node_0029DD68* Valid() { return (int)m4 != -1 ? this : 0; }
};

struct Game_0029DD68 {
    char pad[0x3C];
    Node_0029DD68* m3C;
    unsigned int Count() {
        unsigned int n = 0;
        for (Node_0029DD68* c = m3C->Valid(); c; c = c->mC->Valid()) n++;
        return n;
    }
};

struct Body_0029DD68 {
    char pad[0x18];
    int m18;
    char pad1C[0x50 - 0x1C];
    Vec_0029DD68 m50;
    int GetId() { return m18; }
};

struct Elem_0029DD68 {
    char pad[0x30];
    int m30;
};

struct Lnk_0029DD68 {
    char pad[0x1C];
    void* m1C;
};

struct Msg_0029DD68 {
    unsigned char type;
    char pad1;
    short len;
    void* data;
    int m8;
    int mC;
    unsigned char m10;
    char pad11[0xF];
};

struct Data_0029DD68 {
    unsigned char m0;
    int m4;
    int m8;
    int mC;
};

struct Obj_0029DD68;
extern void* D_0038FC78;
extern void* D_00392068;
extern "C" int func_001A9E60(void* p);
extern "C" void* func_0022E358(void* g);
extern "C" int func_0024F540(void* p);
extern "C" Body_0029DD68* func_0022DE70(void* g, int i);
extern "C" Elem_0029DD68* func_002A52F0(void* t, unsigned short id);
extern "C" int func_002B3038(Elem_0029DD68* e);
extern "C" Lnk_0029DD68* func_00185578(void*, unsigned int);
extern "C" int func_002392B8(void* p);
extern "C" void* func_002A6070(void* m);
extern "C" unsigned int func_00203018(void* p, unsigned int a, unsigned int b);
extern "C" float sqrtf(float);
extern "C" void func_001FA800(Msg_0029DD68* m);
extern "C" void* func_002A39D8(void* m);
extern "C" void func_00184950(void* p);
extern "C" void* func_001190D0(int n);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7528(void* s, unsigned int name, Vec_0029DD68 v);
extern "C" void func_001E72B0(void* s, unsigned int name, float f);
extern "C" void func_001F0210(int name, void* params, int a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" int func_0029E1D8(Obj_0029DD68* o);
extern "C" unsigned int func_0010FC30();
extern "C" void func_002B3078(Elem_0029DD68* e, unsigned int t);
extern "C" int func_002B3080(Elem_0029DD68* e);
extern "C" void func_001FF970(void* q, int id, Msg_0029DD68* m);
extern "C" int func_002B1FC8(Elem_0029DD68* e);
extern "C" char* func_00206A08(Body_0029DD68* p);
extern "C" void func_001E70C0(void* s, unsigned int name, char* v);
extern "C" void func_0022C4A0(void* g, Body_0029DD68* p, int a);
extern "C" void func_00239198(void* p, int v);

struct Obj_0029DD68 {
    char pad[0xC];
    Body_0029DD68* mC;
    char pad10[0x1C - 0x10];
    void* m1C;
    float m20;
    float m24;
    int m28;
    int m2C;
    Vec_0029DD68 m30;
    int m40;
    void Check();
};

void Obj_0029DD68::Check()
{
    float range = m20 + 48.0f;
    if (func_001A9E60(m1C))
        return;
    if (m40)
        return;
    int flag;
    Game_0029DD68* g = (Game_0029DD68*)D_0038FC78;
    void* mgr = D_00392068;
    unsigned int n = g->Count();
    flag = func_0024F540(func_0022E358(g));
    for (unsigned int i = 0; i < n; i++) {
        Body_0029DD68* p = func_0022DE70(g, i);
        if (p->GetId() == m2C)
            continue;
        Elem_0029DD68* me = func_002A52F0(mgr, m2C);
        Elem_0029DD68* him = func_002A52F0(mgr, p->GetId());
        if (!func_002B3038(him))
            continue;
        void* sk = func_00185578(p, 0xD262802F)->m1C;
        if (func_002392B8(sk) <= 0)
            continue;
        if (flag && me->m30 == him->m30
            && func_00203018(func_002A6070(mgr), 0xE959C43A, 0x21902065) != 0xF81BC89B)
            continue;
        float dist;
        {
            Vec_0029DD68 d;
            float x = p->m50.f.x - mC->m50.f.x;
            float y = p->m50.f.y - mC->m50.f.y;
            float z = p->m50.f.z - mC->m50.f.z;
            float w = p->m50.f.w - mC->m50.f.w;
            d.f.x = x;
            d.f.y = y;
            d.f.z = z;
            d.f.w = w;
            dist = sqrtf(d.f.x * d.f.x + d.f.y * d.f.y + d.f.z * d.f.z);
        }
        if (dist < range) {
            Data_0029DD68 data;
            Msg_0029DD68 msg;
            func_001FA800(&msg);
            void* q = func_002A39D8(D_00392068);
            func_00184950(mC);
            if (m28) {
                Vec_0029DD68 pos = mC->m50;
                void* s = func_001E6978(func_001190D0(8));
                func_001E7528(s, 0x7F261953, pos);
                func_001E7528(s, 0x0C4C809E, m30);
                func_001E72B0(s, 0x13B9DA7B, m24);
                func_001F0210(m28, s, 0, 0, 0);
                if (s)
                    func_001E6AE8(s, 3);
            }
            data.m0 = m2C;
            data.m4 = func_0029E1D8(this);
            msg.type = 0x84;
            msg.data = &data;
            msg.len = 8;
            msg.mC = 2;
            msg.m10 = 8;
            func_002B3078(him, func_0010FC30());
            func_001FF970(q, func_002B3080(him), &msg);
            data.m0 = p->GetId();
            msg.type = 0x85;
            func_001FF970(q, func_002B3080(me), &msg);
            if (func_002392B8(sk) - func_0029E1D8(this) <= 0) {
                if (func_002392B8(sk) > 0 && !func_002B1FC8(him)) {
                    void* s = func_001E6978(func_001190D0(8));
                    func_001E70C0(s, 0xA1DC81F9, func_00206A08(p));
                    func_001F0210(0x9B043179, s, 0, 0, 0);
                    if (s)
                        func_001E6AE8(s, 3);
                    func_0022C4A0(g, p, 1);
                }
                func_00239198(sk, 0);
            } else {
                func_00239198(sk, func_002392B8(sk) - func_0029E1D8(this));
            }
            return;
        }
    }
}
