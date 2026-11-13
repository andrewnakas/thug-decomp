/* fuzzy: 95.6 */
extern char D_00371C78[];
extern char D_003781B8[];
extern char D_003781C8[];

struct Pool_002A09F8 {
    char pad[0x3EC];
    int m3EC;
};

struct MsgDesc_002A09F8 {
    unsigned char m_Id;
    unsigned char pad1;
    unsigned short m_Length;
    void* m_Data;
    int m8;
    int m_Priority;
    unsigned char m_Queue;
    char pad11[0xF];
};

struct Info_002A09F8 {
    int m0;
    int m4;
    int m8;
    int mC;
    unsigned char m10;
    unsigned char m11;
    int m14;
    char m18[0x10];
    char m28[0x1000];
};

struct Conn_002A09F8 {
    char m0;
    char m1[0x10];
    signed char m11;
    int m14;
    unsigned int m18;
    int m1C;
    int m20;
    int m24;
    int pad28;
    int m2C;
    int m30;
    int pad34;
    int m38;
};

struct Node_002A09F8 {
    int m0;
    Conn_002A09F8* data;
    int m8;
    Node_002A09F8* next;
    Node_002A09F8* prev;
    virtual ~Node_002A09F8();
    Conn_002A09F8* GetData() { return data; }
    Node_002A09F8* Valid()
    {
        if (!~(int)data)
            return 0;
        return this;
    }
    Node_002A09F8* First()
    {
        if (!~(int)next->data)
            return 0;
        return next;
    }
};

struct LNode_002A09F8 {
    int m0;
    void* data;
    int m8;
    LNode_002A09F8* next;
    LNode_002A09F8* Valid()
    {
        if (!~(int)data)
            return 0;
        return this;
    }
    int Count()
    {
        int n = 0;
        for (LNode_002A09F8* x = next->Valid(); x; x = x->next->Valid())
            n++;
        return n;
    }
};

struct Sk_002A09F8 {
    char pad[0x30];
    LNode_002A09F8 m30;
};

struct Sub_002A09F8 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int GetM18() { return m18; }
};

struct Player_002A09F8 {
    char pad0[0x18];
    Sub_002A09F8* m18;
    int m1C;
    char pad20[0x28 - 0x20];
    int m28;
    int m2C;
    unsigned char m30;
    char pad31[3];
    char m34[0x10];
    int m44;
    void* m48;
    char pad4C[0x14C - 0x4C];
    int m14C;
    char pad150[4];
    int m154;
};

struct It_002A09F8 {
    int m0;
    void* cur;
    void* vt;
    It_002A09F8() { vt = D_00371C78; cur = 0; }
    ~It_002A09F8() { vt = D_00371C78; }
};

struct Client_002A09F8 {
    char pad[0x1804];
    unsigned int m1804;
};

struct Mgr_002A09F8 {
    char pad0[0x14];
    Client_002A09F8* m14;
    char pad18[0xF4 - 0x18];
    Node_002A09F8 mF4;
};

struct Obj_002A09F8 {
    char pad0[0x20];
    Mgr_002A09F8* m20;
    void Run();
};

extern Pool_002A09F8* D_00388A70;
extern Sk_002A09F8* D_0038FC78;
extern void* D_0038EB78;

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" int func_0010FC30();
extern "C" void func_001FA800(MsgDesc_002A09F8* desc);
extern "C" int func_00202B30(int a);
extern "C" int func_001FA648(void* a);
extern "C" Player_002A09F8* func_002A3CC8(Mgr_002A09F8* m, void* a, int b, int c);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" void func_002B1F60(Player_002A09F8* p, int v);
extern "C" void func_002A47B8(Mgr_002A09F8* m, Player_002A09F8* p);
extern "C" bool func_002B1FC8(Player_002A09F8* p);
extern "C" bool func_002B1FE8(Player_002A09F8* p);
extern "C" int func_002B3080(Player_002A09F8* p);
extern "C" void func_001FF970(Client_002A09F8* client, int conn, MsgDesc_002A09F8* desc);
extern "C" Player_002A09F8* func_002A53F8(Mgr_002A09F8* m, It_002A09F8* it, int all);
extern "C" Player_002A09F8* func_002A5490(Mgr_002A09F8* m, It_002A09F8* it, int all);
extern "C" int func_002616E0(void* x, char* buf, int size, int f);
extern "C" int func_002B1108(Mgr_002A09F8* m, int v);
extern "C" int func_002A58C0(Mgr_002A09F8* m);
extern "C" void* func_002C0368();
extern "C" void func_002BCDF8(void* a);
extern "C" void* func_002BCE20(void* a, int b);
extern "C" void func_00200998(Client_002A09F8* client, int conn, int id, int size, void* data, char* name, int queue, int a, int b);
extern "C" void* func_0029C320();
extern "C" void* func_0029A2C8(void* a);
extern "C" bool func_002A19A8(Mgr_002A09F8* m);
extern "C" int func_00202768(int a);
extern "C" void* func_0022C6E0(Sk_002A09F8* g, int a, int b, int c, int d);
extern "C" void func_002B1E70(Player_002A09F8* p, void* s);
extern "C" void func_00206968(void* s);
extern "C" void func_00206920(Sub_002A09F8* s);
extern "C" void func_002B2F40(Player_002A09F8* p, int t);
extern "C" void func_002B3168(Conn_002A09F8* c, int f);

void Obj_002A09F8::Run()
{
    func_0010A950(D_00388A70, D_00388A70->m3EC);
    Sk_002A09F8* sk = D_0038FC78;
    Mgr_002A09F8* m = m20;
    MsgDesc_002A09F8 msg;
    Info_002A09F8 info;
    int time;
    Node_002A09F8* n;
    Node_002A09F8* next;
    func_001FA800(&msg);
    void* eb = D_0038EB78;
    msg.m_Priority = 2;
    msg.m_Queue = 8;
    for (n = m->mF4.First(); n; n = next) {
        It_002A09F8 it;
        Conn_002A09F8* c = n->GetData();
        next = n->next->Valid();
        if (m->m14->m1804 < c->m18)
            break;
        int flag = 0;
        if (func_00202B30(c->m14) == 1 || func_001FA648(eb) == 1)
            flag = 1;
        func_0010A950(D_00388A70, D_00388A70->m3EC);
        Player_002A09F8* p = func_002A3CC8(m, 0, c->m14, c->m20);
        func_0010A9B0(D_00388A70);
        func_00331A9C(p->m34, c->m1);
        func_002B1F60(p, c->m1C);
        p->m154 = c->m24;
        p->m28 = c->m2C;
        p->m2C = c->m30;
        p->m44 = c->m38;
        func_002A47B8(m, p);
        time = func_0010FC30();
        if (!func_002B1FC8(p)) {
            info.m10 = c->m11;
            info.m11 = p->m30;
            info.m0 = p->m28;
            info.m4 = p->m2C;
            info.m14 = p->m44;
            info.mC = 0;
            func_00331A9C(info.m18, c->m1);
            info.m8 = 1;
            if (p->m14C & 0x10)
                info.m8 |= 0x10;
            if (func_002B1FE8(p))
                info.m8 |= 4;
            msg.m_Data = 0;
            msg.m_Id = 0x79;
            msg.m8 = 0xFF;
            msg.m_Length = 0;
            func_001FF970(m->m14, func_002B3080(p), &msg);
            msg.m_Data = &info;
            msg.m_Length = 0x28;
            msg.m_Id = 0x22;
            func_001FF970(m->m14, func_002B3080(p), &msg);
        }
        Player_002A09F8* q;
        if (!func_002B1FE8(p)) {
            for (q = func_002A53F8(m, &it, 1); q; q = func_002A5490(m, &it, 1)) {
                if (p == q)
                    continue;
                if (func_002B1FC8(q))
                    continue;
                info.m10 = c->m11;
                info.m8 = 0;
                info.m11 = p->m30;
                info.m0 = p->m28;
                info.m4 = p->m2C;
                info.m14 = p->m44;
                info.mC = 0;
                func_00331A9C(info.m18, p->m34);
                msg.m_Length = func_002616E0(p->m48, info.m28, 0x1000, 0) + 0x28;
                msg.m_Data = &info;
                msg.m_Id = 0x22;
                msg.m8 = 0x80;
                msg.m_Priority = 2;
                msg.m_Queue = 8;
                func_001FF970(m->m14, func_002B3080(q), &msg);
            }
        }
        if (p->m14C & 0x10) {
            for (q = func_002A53F8(m, &it, 0); q; q = func_002A5490(m, &it, 0)) {
                if (p == q)
                    continue;
                if (q->m154 != p->m154)
                    continue;
                info.m10 = q->m18->GetM18();
                info.m8 = q->m14C & 0x7880;
                info.m11 = q->m30;
                info.m0 = q->m28;
                info.m4 = q->m2C;
                info.m14 = q->m44;
                info.mC = 0;
                func_00331A9C(info.m18, q->m34);
                msg.m_Length = func_002616E0(q->m48, info.m28, 0x1000, flag) + 0x28;
                msg.m_Data = &info;
                msg.m_Id = 0x22;
                msg.m8 = 0x80;
                msg.m_Priority = 2;
                msg.m_Queue = 8;
                func_001FF970(m->m14, func_002B3080(p), &msg);
            }
        } else {
            for (q = func_002A53F8(m, &it, 0); q; q = func_002A5490(m, &it, 0)) {
                if (p == q)
                    continue;
                if (func_002B1FC8(p))
                    continue;
                info.m10 = q->m18->GetM18();
                info.m8 = q->m14C & 0x7880;
                info.m11 = q->m30;
                info.m0 = q->m28;
                info.m4 = q->m2C;
                info.m14 = q->m44;
                info.mC = func_002B1108(m, q->m18->GetM18());
                func_00331A9C(info.m18, q->m34);
                msg.m_Length = func_002616E0(q->m48, info.m28, 0x1000, flag) + 0x28;
                msg.m_Data = &info;
                msg.m_Id = 0x22;
                msg.m8 = 0x80;
                msg.m_Priority = 2;
                msg.m_Queue = 8;
                func_001FF970(m->m14, func_002B3080(p), &msg);
            }
            int r = func_002A58C0(m);
            if (!func_002B1FC8(p) && r == (int)0xB664035D) {
                func_002BCDF8(func_002C0368());
                int conn = func_002B3080(p);
                func_00200998(m->m14, conn, 0x6C, 15000, func_002BCE20(func_002C0368(), 0), D_003781B8, 8, 0, 1);
                conn = func_002B3080(p);
                func_0029C320();
                func_00200998(m->m14, conn, 0x88, 0x1132, func_0029A2C8(func_0029C320()), D_003781C8, 8, 0, 1);
            }
            msg.m_Length = 4;
            msg.m_Id = 0x53;
            msg.m8 = 0x80;
            int mode = r;
            msg.m_Data = &mode;
            msg.m_Priority = 2;
            msg.m_Queue = 8;
            func_001FF970(m->m14, func_002B3080(p), &msg);
        }
        if (!func_002B1FE8(p)) {
            int cnt;
            if (!func_002B1FC8(p) || !func_002A19A8(m))
                cnt = sk->m30.Count();
            else
                cnt = 0;
            void* s = func_0022C6E0(sk, c->m1C, func_00202768(p->m1C), c->m11, cnt);
            func_002B1E70(p, s);
            if (!func_002B1FC8(p))
                func_00206968(s);
            for (q = func_002A53F8(m, &it, 1); q; q = func_002A5490(m, &it, 1)) {
                if (p == q)
                    continue;
                msg.m_Length = 4;
                msg.m_Data = &time;
                msg.m_Id = 0x25;
                msg.m8 = 0x80;
                msg.m_Priority = 2;
                msg.m_Queue = 8;
                func_001FF970(m->m14, func_002B3080(q), &msg);
                if (func_002B1FC8(q))
                    continue;
                if (func_002B1FE8(q))
                    continue;
                func_00206920(q->m18);
                func_002B2F40(q, time);
            }
        }
        msg.m_Data = &time;
        msg.m_Length = 4;
        msg.m_Id = 0x25;
        msg.m8 = 0x80;
        msg.m_Priority = 2;
        msg.m_Queue = 8;
        func_001FF970(m->m14, func_002B3080(p), &msg);
        func_002B2F40(p, time);
        if (c)
            func_002B3168(c, 3);
        delete n;
    }
    func_0010A9B0(D_00388A70);
}
