/* force: {"kind": "sched", "pass": 2, "block": 12, "clock": 1, "first": 480} */
/* force: {"kind": "sched", "pass": 2, "block": 12, "clock": 1, "first": 250} */
extern char D_00379E70[];
extern char D_003799A0[];
extern unsigned int D_00392448;
extern int D_00392430;
extern unsigned int D_0039242C;

struct Node_002B3718 {
    int m0;
    Node_002B3718* data;
    int m8;
    Node_002B3718* next;
    Node_002B3718* prev;
    Node_002B3718* GetData() { return data; }
    Node_002B3718* Valid() { return (int)data != -1 ? this : 0; }
    int Count()
    {
        int n = 0;
        for (Node_002B3718* x = next->Valid(); x; x = x->next->Valid())
            n++;
        return n;
    }
    void Append(Node_002B3718* s)
    {
        s->prev = prev;
        s->next = this;
        prev->next = s;
        prev = s;
    }
    void Remove()
    {
        prev->next = next;
        next->prev = prev;
        next = this;
        prev = this;
    }
};

struct It_002B3718 {
    int m0;
    Node_002B3718* cur;
    void* vt;
    It_002B3718() { vt = D_00379E70; cur = 0; }
    ~It_002B3718() { vt = D_00379E70; }
    Node_002B3718* Advance(Node_002B3718* c)
    {
        cur = c->next->Valid();
        if (!cur)
            return 0;
        return cur->GetData();
    }
    Node_002B3718* First(Node_002B3718* h)
    {
        cur = h;
        return Advance(cur);
    }
};

struct Mgr_002B3718 {
    char pad[0x124];
    Node_002B3718 m124;
    char pad138[4];
    Node_002B3718 m13C;
};

extern "C" unsigned int func_0010FC30();
extern "C" void func_002B4D80(Mgr_002B3718* m, int v);
extern "C" void func_002B3D38(Mgr_002B3718* m, Node_002B3718* s, int n);
extern "C" void func_001F0370(char* s, void* a, int b, int c);

static inline bool Elapsed_002B3718(unsigned int ms, unsigned int now, unsigned int start)
{
    return now - start > ms;
}

struct Obj_002B3718 {
    char pad[0x20];
    Mgr_002B3718* m20;
    void Update();
};

void Obj_002B3718::Update()
{
    Mgr_002B3718* m = m20;
    if (Elapsed_002B3718(3000, func_0010FC30(), D_00392448)) {
        D_00392448 = func_0010FC30();
        return;
    }
    if (!D_00392430)
        return;
    if (func_0010FC30() - D_0039242C <= 500)
        return;
    It_002B3718 it;
    func_002B4D80(m, 1);
    Node_002B3718* s = it.First(&m->m13C);
    It_002B3718* p = &it;
    while (s) {
            Node_002B3718* n = p->Advance(it.cur);
            s->Remove();
            func_002B3D38(m, s, m->m124.Count());
            m->m124.Append(s);
            s = n;
    }
    func_001F0370(D_003799A0, 0, 0, 0);
    D_00392430 = 0;
}
