/* fuzzy: 92.0 */
/* r102 w1: for(;;)+break insert loop (175 words) reproduces the lui s3/s5 + sll hoists and id in s4, but the loop is laid out differently. Lane-3 base (166 words): create path matches; local (non-215EE0) path differs: game hoists lui D_00372918/D_00372930 into s3/s5 and sll id<<16 before the sorted-insert loop (loop.c treats the following calls as in-loop), and its 'return s' paths branch to the shared epilogue. vptr needs base-with-fields + vbase split (vptr goes after a class's own fields). */
extern char D_00372900[];
extern char D_00372918[];
extern char D_00372930[];
extern char D_00372948[];
extern char D_00372960[];
extern char D_00372978[];
extern char D_00372998[];
extern char D_0038FC88[];
extern void* D_00392068;
extern void* D_0038C608;
extern void* D_0038FC80;
extern void* D_0038FC84;

struct Heap_0022C6E0 {
    char pad[0x148];
    int m148[1];
};

extern Heap_0022C6E0* D_00388A70;

struct Node_0022C6E0 {
    int m0;
    int m_data;
    int m_pri;
    Node_0022C6E0* m_next;
    Node_0022C6E0* m_prev;
    Node_0022C6E0* Valid()
    {
        return ~m_data ? this : 0;
    }
    void Remove()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
    void InsertBefore(Node_0022C6E0* n)
    {
        m_prev = n->m_prev;
        m_next = n;
        n->m_prev->m_next = this;
        n->m_prev = this;
    }
};

static inline void Insert_0022C6E0(Node_0022C6E0* head, Node_0022C6E0* node)
{
    int pri = node->m_pri;
    Node_0022C6E0* n = head;
    while ((n = n->m_next->Valid()) != 0) {
        if (n->m_pri == pri)
            return;
        if (pri < n->m_pri) {
            node->InsertBefore(n);
            return;
        }
    }
    node->InsertBefore(head);
}

struct Base_0022C6E0 {
    char pad0[8];
};

class CompV_0022C6E0 : public Base_0022C6E0 {
public:
    virtual ~CompV_0022C6E0();
};

class Comp_0022C6E0 : public CompV_0022C6E0 {
public:
    unsigned int m_flags;
};

class SkaterV_0022C6E0 : public Base_0022C6E0 {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void Init(char* profile);
};

class Skater_0022C6E0 : public SkaterV_0022C6E0 {
public:
    char padC[0xC];
    int m18;
    char pad1C[0x300];
    int m31C;
    int m320;
};

struct Mgr_0022C6E0 {
    char pad0[0x30];
    Node_0022C6E0 m30;
    char pad44[0x3C];
    void* m80;
};

extern "C" int func_00215EE0(int a, int b);
extern "C" char* func_002629A8(void* profiles, int index);
extern "C" void func_0011F930(void* dst, void* src);
extern "C" void func_001F0370(char* s, void* a, void* b, int c);
extern "C" Skater_0022C6E0* func_0022DD38(Mgr_0022C6E0* self);
extern "C" Node_0022C6E0* func_00206918(Skater_0022C6E0* self);
extern "C" int func_002041F8(Skater_0022C6E0* skater);
extern "C" void func_0010A950(Heap_0022C6E0* p, int v);
extern "C" void func_00183E90(Skater_0022C6E0* self, int a);
extern "C" void func_0010A9B0(Heap_0022C6E0* p);
extern "C" void* func_00203360(Skater_0022C6E0* p);
extern "C" void func_00236D48(void* p, int id);
extern "C" Comp_0022C6E0* func_00187B48(void* mgr, unsigned int id);
extern "C" bool func_002A19A8(void* net);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_001BABD8(void* p);
extern "C" void func_0010BFC0(const char* name);
extern "C" int func_0022C510(Mgr_0022C6E0* self, int a);
extern "C" void* func_001046B0(int size);
extern "C" void* func_0022E040(Mgr_0022C6E0* mgr);
extern "C" void* func_0022E358(Mgr_0022C6E0* p);
extern "C" bool func_0024F860(void* p);
extern "C" Skater_0022C6E0* func_00204200(void* mem, int a, void* b, int c, int d, int e, bool f);
extern "C" void func_0022CF08(Mgr_0022C6E0* self, Skater_0022C6E0* it, int a, int b);
extern "C" void func_00230338(Mgr_0022C6E0* mgr);
extern "C" void func_00103F28(void* p);
extern "C" void func_00206B60(Skater_0022C6E0* obj, void* params);
extern "C" void func_00206D58(Skater_0022C6E0* obj, void* params);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001AB7C0(void* comp, char* profile);
extern "C" void func_0010BFC8();

Skater_0022C6E0* func_0022C6E0(Mgr_0022C6E0* self, char* profile, int local, int id, int index)
{
    void* net = D_00392068;
    if (local) {
        char* dst = profile + 4;
        char* p;
        if (func_00215EE0(0, 0))
            p = func_002629A8(self->m80, index);
        else
            p = func_002629A8(self->m80, 0);
        func_0011F930(dst, p + 4);
    }
    if (local) {
        func_001F0370(D_00372900, 0, 0, 0);
        Skater_0022C6E0* s = func_0022DD38(self);
        if (s) {
            if (func_00215EE0(0, 0)) {
                if (s->m18 != id)
                    goto create;
            } else if (s->m18 != id) {
                Node_0022C6E0* node = func_00206918(s);
                node->m_pri = id;
                node->Remove();
                Node_0022C6E0* head = &self->m30;
                int pri = node->m_pri;
                Node_0022C6E0* n = head;
                for (;;) {
                    n = n->m_next->Valid();
                    if (!n) {
                        node->InsertBefore(head);
                        break;
                    }
                    if (n->m_pri == pri)
                        break;
                    if (pri < n->m_pri) {
                        node->InsertBefore(n);
                        break;
                    }
                }
                func_0010A950(D_00388A70, D_00388A70->m148[func_002041F8(s)]);
                func_001F0370(D_00372918, 0, s, 0);
                func_00183E90(s, id);
                func_001F0370(D_00372930, 0, s, 0);
                func_0010A9B0(D_00388A70);
                func_00236D48(func_00203360(s), (short)id);
                return s;
            }
            return s;
        }
        Comp_0022C6E0* c = func_00187B48(D_0038C608, 0x967C138C);
        if (c) {
            c->m_flags &= ~2;
            delete c;
        }
    } else if (func_002A19A8(net)) {
        Skater_0022C6E0* s = func_0022DD38(self);
        if (s) {
            void* c = func_00185578(s, 0x404EB936);
            if (c)
                func_001BABD8(c);
        }
    }
create:
    func_002A19A8(net);
    func_0010BFC0(D_0038FC88);
    int heap = func_0022C510(self, local);
    func_0010A950(D_00388A70, D_00388A70->m148[heap]);
    void* mem = func_001046B0(0x390);
    void* a = func_0022E040(self);
    Skater_0022C6E0* s = func_00204200(mem, index, a, local, id, heap, !func_0024F860(func_0022E358(self)));
    s->Init(profile);
    if (!s->m31C)
        func_001F0370(D_00372948, 0, s, 0);
    Node_0022C6E0* node = func_00206918(s);
    node->m_pri = s->m18;
    Insert_0022C6E0(&self->m30, node);
    if (func_0024F860(func_0022E358(self))) {
        func_0022CF08(self, s, -1, 0);
        func_001F0370(D_00372960, 0, 0, 0);
    }
    func_00230338(self);
    if (s->m31C && !s->m320) {
        if (D_0038FC80) {
            func_00103F28(D_00372978);
            func_00206B60(s, D_0038FC80);
            if (D_0038FC80)
                func_001E6AE8(D_0038FC80, 3);
            D_0038FC80 = 0;
        }
        if (D_0038FC84) {
            func_00103F28(D_00372998);
            func_00206D58(s, D_0038FC84);
            if (D_0038FC84)
                func_001E6AE8(D_0038FC84, 3);
            D_0038FC84 = 0;
        }
    }
    if (s->m18 == 1 && func_00215EE0(0, 0))
        func_001AB7C0(func_00185578(s, 0x270F56E1), profile);
    func_0010BFC8();
    func_0010A9B0(D_00388A70);
    return s;
}
