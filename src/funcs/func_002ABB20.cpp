extern char D_00378BD8[];
extern char D_00378DC8[];
extern char D_00378DD8[];
extern char D_00392270[];
extern char D_00378DE8[];
extern char D_00378DF8[];
extern char D_00378E08[];

struct Msg_002ABB20 {
    unsigned char m_Id;
    unsigned char pad1;
    unsigned short m_Length;
    void* m_Data;
    int pad8;
    int m_Priority;
    unsigned char m_Queue;
    char pad11[0xF];
};

struct Name_002ABB20 {
    long q[4];
};

struct Info_002ABB20 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned int m8;
    unsigned long m10;
    int m18;
    int m1C;
    int m20;
    int m24;
    Name_002ABB20 m28;
};

struct Pair_002ABB20 {
    int m0;
    int m4;
    int m8;
    unsigned char mC;
};

struct Peer_002ABB20 {
    char pad0[0x18];
    int m18;
};

struct Ref_002ABB20 {
    char pad0[0x18];
    Peer_002ABB20* m18;
    int GetId() { return m18->m18; }
};

struct Item_002ABB20 {
    char pad0[0x18];
    int m18;
    int m1C;
    int m20;
};

struct Node_002ABB20 {
    int m0;
    Item_002ABB20* data;
    int m8;
    Node_002ABB20* next;
    Item_002ABB20* GetData() { return data; }
    Node_002ABB20* Valid() { return (int)data != -1 ? this : 0; }
};

static inline Item_002ABB20* DataOf_002ABB20(Node_002ABB20* n)
{
    if (!n)
        return 0;
    return n->GetData();
}

struct It_002ABB20 {
    int m0;
    Node_002ABB20* cur;
    void* vt;
    It_002ABB20() { vt = D_00378BD8; cur = 0; }
    ~It_002ABB20() { vt = D_00378BD8; }
    Item_002ABB20* Next()
    {
        cur = cur->next->Valid();
        if (!cur)
            return 0;
        return cur->GetData();
    }
    Item_002ABB20* First(Node_002ABB20* h)
    {
        cur = h;
        return Next();
    }
};

struct Conn_002ABB20 {
    char pad0[0x14C];
    unsigned int m14C;
};

struct Mgr_002ABB20 {
    char pad0[0x14];
    void* m14;
    char pad18[0x50 - 0x18];
    Name_002ABB20 m50;
    unsigned char m70;
    char pad71[0xBC - 0x71];
    char mBC[0x10C - 0xBC];
    Node_002ABB20 m10C;
    char pad11C[0x16C - 0x11C];
    int m16C;
    int Get16C() { return m16C; }
};

extern void* D_0038EB78;
extern void* D_0038FC78;

extern "C" Conn_002ABB20* func_002A5248(Mgr_002ABB20* m, int id);
extern "C" Msg_002ABB20* func_001FA800(Msg_002ABB20* m);
extern "C" int func_0010FC30();
extern "C" unsigned char func_002A1B30(Mgr_002ABB20* m);
extern "C" int func_002B1FC8(Conn_002ABB20* c);
extern "C" int func_002B1FE8(Conn_002ABB20* c);
extern "C" void func_002AB2E8(Mgr_002ABB20* m, int v);
extern "C" int func_002A8560(Mgr_002ABB20* m);
extern "C" unsigned int func_001F0D78(char* s);
extern "C" void* func_0022E358(void* p);
extern "C" void* func_0022E048(void* p);
extern "C" unsigned int func_0024F938(void* p);
extern "C" unsigned int func_0024EF70(void* p);
extern "C" int func_0024F5F8(void* p);
extern "C" int func_0024F590(void* p);
extern "C" int func_00202FC8(void* p, unsigned int a, unsigned int b);
extern "C" unsigned char func_002A7660(Mgr_002ABB20* m);
extern "C" int func_002A58C0(Mgr_002ABB20* m);
extern "C" int func_001FA648(void* p);
extern "C" int func_002B3080(Conn_002ABB20* c);
extern "C" void func_001FF970(void* client, int conn, Msg_002ABB20* m);
extern "C" int func_002AB438(Mgr_002ABB20* m);
extern "C" void func_002AB468(Mgr_002ABB20* m, int v);
extern "C" int func_002AB4C8(Mgr_002ABB20* m);
extern "C" void* func_002AB4C0(Mgr_002ABB20* m);
extern "C" void func_00200998(void* client, int conn, unsigned char id, unsigned short len, void* data, char* name, unsigned char q, int a, int b);
extern "C" void func_00235F78(void* p, Conn_002ABB20* c);
extern "C" unsigned short func_00266458(void* p, char* buf);
extern "C" void* func_00240850();
extern "C" int func_0023C040(void* p);
extern "C" void* func_0023BB50(void* p, int i);
extern "C" int func_002463A0(void* p);
extern "C" int func_00246258(void* p);
extern "C" Ref_002ABB20* func_002A5820(Mgr_002ABB20* m);
extern "C" int func_002A19A8(Mgr_002ABB20* m);
extern "C" void func_002A4070(Mgr_002ABB20* m, Conn_002ABB20* c);
extern "C" void* memcpy(void* d, const void* s, unsigned int n);

struct Cmd_002ABB20 {
    char pad0[0x14];
    int m14;
    char pad18[4];
    Mgr_002ABB20* m1C;
    int Run();
};

int Cmd_002ABB20::Run()
{
    Mgr_002ABB20* mgr = m1C;
    void* net = D_0038EB78;
    void* ctl = D_0038FC78;
    Conn_002ABB20* c = func_002A5248(mgr, m14);
    if (c && !(c->m14C & 0x40)) {
        It_002ABB20 it;
        Info_002ABB20 info;
        Msg_002ABB20 msg;
        func_001FA800(&msg);
        func_0010FC30();
        c->m14C |= 0x40;
        info.m4 = func_002A1B30(mgr);
        if (func_002B1FC8(c)) {
            func_002AB2E8(mgr, 1);
        } else {
            if (func_002A8560(mgr)) {
                info.m10 = func_001F0D78(D_00378DC8);
                info.m8 = 0;
                info.m20 = 0;
                info.m24 = 0;
            } else {
                info.m10 = func_0024F938(func_0022E358(ctl));
                info.m8 = func_0024EF70(func_0022E358(ctl)) / 1000;
                info.m20 = func_0024F5F8(func_0022E358(ctl));
                info.m24 = func_00202FC8(mgr->mBC, func_001F0D78(D_00378DD8), func_001F0D78(D_00392270));
            }
            info.m2 = func_002A7660(mgr);
            info.m18 = func_002A58C0(mgr);
            info.m1C = func_0024F590(func_0022E358(ctl));
            info.m0 = mgr->m70;
            info.m3 = mgr->Get16C();
            info.m28 = mgr->m50;
            if (func_001FA648(net) == 1)
                info.m1 = 0;
            else
                info.m1 = 1;
            msg.m_Data = &info;
            msg.m_Length = 0x48;
            msg.m_Id = 0x33;
            msg.m_Priority = 2;
            msg.m_Queue = 8;
            func_001FF970(mgr->m14, func_002B3080(c), &msg);
            if (func_002AB438(mgr)) {
                func_002AB468(mgr, func_002A58C0(mgr));
                int conn = func_002B3080(c);
                unsigned short len = func_002AB4C8(mgr);
                func_00200998(mgr->m14, conn, 0x87, len, func_002AB4C0(mgr), D_00378DE8, 8, 0, 1);
            }
            for (Item_002ABB20* d = it.First(&mgr->m10C); d;) {
                Pair_002ABB20 p;
                Msg_002ABB20 m;
                func_001FA800(&m);
                p.m8 = d->m18;
                p.m4 = d->m1C;
                p.m0 = d->m20;
                p.mC = 0;
                m.m_Length = 0x10;
                m.m_Data = &p;
                m.m_Id = 0x49;
                m.m_Priority = 2;
                m.m_Queue = 8;
                func_001FF970(mgr->m14, func_002B3080(c), &m);
                it.cur = it.cur->next->Valid();
                d = DataOf_002ABB20(it.cur);
            }
            if (!func_002B1FC8(c))
                func_00235F78(ctl, c);
            if (func_002B1FE8(c) && func_0024F938(func_0022E358(ctl)) == func_001F0D78(D_00378DF8)) {
                Msg_002ABB20 m;
                char buf[0x110];
                func_001FA800(&m);
                unsigned short len = func_00266458(func_0022E048(ctl), buf);
                m.m_Data = buf;
                m.m_Length = len;
                m.m_Id = 0x5C;
                m.m_Priority = 2;
                m.m_Queue = 8;
                func_00200998(mgr->m14, func_002B3080(c), m.m_Id, m.m_Length, m.m_Data, D_00378E08, 8, 1, 0);
            }
            {
                Msg_002ABB20 m;
                char buf[0x1000];
                int v;
                func_001FA800(&m);
                void* list = func_00240850();
                char* p = buf;
                *p++ = 0;
                int n = func_0023C040(list);
                for (int i = 0; i < n; i++) {
                    void* e = func_0023BB50(list, i);
                    if (func_002463A0(e)) {
                        v = func_00246258(e);
                        memcpy(p, &v, 4);
                        p += 4;
                    }
                }
                v = 0;
                memcpy(p, &v, 4);
                p += 4;
                m.m_Id = 0x6D;
                m.m_Data = buf;
                m.m_Length = p - buf;
                m.m_Priority = 2;
                m.m_Queue = 8;
                func_001FF970(mgr->m14, func_002B3080(c), &m);
            }
            Ref_002ABB20* r = func_002A5820(mgr);
            if (r) {
                Msg_002ABB20 m;
                unsigned char b[1];
                func_001FA800(&m);
                b[0] = r->GetId();
                m.m_Data = b;
                m.m_Length = 1;
                m.m_Id = 0x55;
                m.m_Priority = 2;
                m.m_Queue = 8;
                func_001FF970(mgr->m14, func_002B3080(c), &m);
            }
        }
        {
            Msg_002ABB20 m;
            func_001FA800(&m);
            m.m_Id = 0x42;
            m.m_Priority = 2;
            m.m_Queue = 8;
            func_001FF970(mgr->m14, func_002B3080(c), &m);
        }
        if (func_002A19A8(mgr))
            func_002A4070(mgr, c);
    }
    return 1;
}
