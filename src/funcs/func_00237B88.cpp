struct MsgDesc_00237B88 {
    unsigned char m_id;
    char pad1;
    unsigned short m_length;
    void* m_data;
    int m8;
    int m_priority;
    unsigned char m_queue;
    char pad11[0xF];
};

struct MsgData_00237B88 {
    char m0;
    int m4;
};

struct Skater_00237B88 {
    char pad[0x320];
    int m320;
};

struct List_00237B88 {
    int pad0;
    int m_count;
    int GetCount() const { return m_count; }
};

struct Entry_00237B88 {
    char pad[0x4];
    int m4[4];
    int m14[4];
};

struct Obj_00237B88 {
    short pad0;
    short m_id;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    List_00237B88 m_list;
    char pad34[0x24];
    int m58;
    int m5C;
    char pad60[8];
    int m68;
    void Update();
};

extern void* D_0038FC78;
extern void* D_00392068;
extern char D_00373570[];
extern char D_00373580[];
extern char D_00373598[];

extern "C" void* func_0022E358(void* mgr);
extern "C" void func_00238480(Obj_00237B88* obj);
extern "C" Skater_00237B88* func_0022DF08(void* mgr, int id);
extern "C" bool func_001E5400(char* name, int a);
extern "C" void* func_00240850();
extern "C" void func_0023F678(void* a);
extern "C" bool func_0024F8D8(void* a, char* name);
extern "C" void func_002393A8(Obj_00237B88* obj, int pts);
extern "C" void* func_00185578(void* a, unsigned int key);
extern "C" void func_001B0EB8(void* a, int b);
extern "C" void func_0023AC30(Obj_00237B88* obj, int a);
extern "C" bool func_002A19A8(void* net);
extern "C" int func_0024F938(void* gm);
extern "C" MsgDesc_00237B88* func_001FA800(MsgDesc_00237B88* d);
extern "C" char func_002A7660(void* net);
extern "C" void* func_002A39E0(void* net, int id);
extern "C" void func_00200C00(void* conn, MsgDesc_00237B88* d);
extern "C" bool func_0024F4F8(void* gm);
extern "C" Entry_00237B88* func_0023B2B8(List_00237B88* list, int* i, int a);
extern "C" void func_0023AC98(Obj_00237B88* obj);
extern "C" void func_00238EF8(Obj_00237B88* obj, int score, int mult);
extern "C" int func_002041F8(void* skater);
extern "C" void func_00236F80(Obj_00237B88* obj, int a);
extern "C" void func_00238728(Obj_00237B88* obj);
extern "C" int func_002392B8(Obj_00237B88* obj);
extern "C" bool func_0024F908(void* a, unsigned int key);
extern "C" bool func_0024F4C0(void* self);
extern "C" bool func_0024F328(void* self);
extern "C" bool func_0024F360(void* self);
extern "C" bool func_0024F488(void* self);
extern "C" bool func_002A1A38(void* net);
extern "C" void func_00239198(Obj_00237B88* obj, int a);
extern "C" void func_00239030(Obj_00237B88* obj, int a, int b);
extern "C" void func_0029E5C0(void* a);

void Obj_00237B88::Update()
{
    void* mgr = D_0038FC78;
    void* net = D_00392068;
    void* gm = func_0022E358(mgr);
    func_00238480(this);
    int pts = mC * m5C;
    Skater_00237B88* sk = func_0022DF08(mgr, m_id);
    bool dbg = func_001E5400(D_00373570, 0) != 0;
    func_0023F678(func_00240850());
    if (dbg || (func_0024F8D8(gm, D_00373580) && pts > 0))
        func_002393A8(this, pts);
    func_001B0EB8(func_00185578(sk, 0x270F56E1), 0);
    if (!func_001E5400(D_00373598, 0)) {
        m68 += mC * m5C;
        if (m68 >= 3000) {
            func_0023AC30(this, 1);
            m68 = 3000;
        }
        if (m68 < 0)
            m68 = 0;
    } else {
        m1C = 0;
    }
    if (m5C > m20)
        m20 = m5C;
    if (m18 > m24)
        m24 = m18;
    if (m18 > m28) {
        if (func_002A19A8(net) && func_0024F938(gm) != 0x1C471C60) {
            MsgDesc_00237B88 d;
            MsgData_00237B88 x;
            func_001FA800(&d);
            x.m4 = m18;
            x.m0 = func_002A7660(net);
            d.m_id = 0x86;
            d.m_data = &x;
            d.m_priority = 2;
            d.m_length = 8;
            d.m_queue = 8;
            func_00200C00(func_002A39E0(net, sk->m320), &d);
        }
        m28 = m18;
    }
    if (!func_0024F4F8(gm)) {
        for (int i = 0; i < m_list.GetCount(); i++) {
            Entry_00237B88* e = func_0023B2B8(&m_list, &i, 0);
            for (int j = 0; j < 4; j++) {
                e->m4[j] = 0;
                e->m14[j] = 0;
            }
        }
        func_0023AC98(this);
    } else {
        for (int i = 0; i < m_list.GetCount(); i++) {
            Entry_00237B88* e = func_0023B2B8(&m_list, &i, 0);
            for (int j = 0; j < 4; j++) {
                e->m4[j] += e->m14[j];
                e->m14[j] = 0;
            }
        }
    }
    if (m58) {
        m8 = 1;
        int t = mC * m5C;
        m14 = 150;
        m10 = t;
        func_00238EF8(this, t, 0);
        func_00236F80(this, func_002041F8(sk));
    }
    func_00238728(this);
    int before = func_002392B8(this);
    if (!func_0024F908(gm, 0x11941568) && func_0024F4C0(gm)) {
        if (func_0024F328(gm) || (func_0024F360(gm) && func_002392B8(this) < pts)) {
            if (!func_002A1A38(net)) {
                MsgData_00237B88 x;
                MsgDesc_00237B88 d;
                func_001FA800(&d);
                x.m0 = func_002A7660(net);
                d.m_id = 0x52;
                d.m_priority = 2;
                x.m4 = pts;
                d.m_data = &x;
                d.m_length = 8;
                d.m_queue = 8;
                func_00200C00(func_002A39E0(net, sk->m320), &d);
            }
            if (func_0024F360(gm))
                func_00239198(this, pts);
            else
                func_00239198(this, m4 + pts);
        } else if (!func_0024F360(gm) && !func_0024F488(gm)) {
            func_00239198(this, pts);
        }
    }
    func_00239030(this, before, func_002392B8(this));
    func_0029E5C0(func_00185578(sk, 0x8BCE7E66));
}
