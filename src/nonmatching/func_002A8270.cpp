/* fuzzy: 98.6 */
/* nonmatch func_002A8270: best earlier draft (thug-claude-lane3/work/w53/p1/func_002A8270.fail), 3 of 138 words differ. */
extern "C" void func_00183C98(void* p, void* r);
extern "C" void func_00183CB8(void* p, void* r);

struct Ref_002A8270 {
    void* p;
    Ref_002A8270& operator=(void* q) {
        if (p) {
            func_00183CB8(p, this);
            p = 0;
        }
        p = q;
        if (q) func_00183C98(q, this);
        return *this;
    }
};

struct Base_002A8270 {
    char pad[0x14];
    virtual ~Base_002A8270();
};

struct Data_002A8270 : Base_002A8270 {
    int m18;
    int m1C;
    int m20;
};

struct Node_002A8270 {
    int m0;
    Data_002A8270* data;
    int m8;
    Node_002A8270* next;
    Data_002A8270* GetData() { return data; }
    Node_002A8270* Valid() { return (int)data != -1 ? this : 0; }
};

extern char D_00378BD8[];

struct It_002A8270 {
    int m0;
    Node_002A8270* cur;
    void* vt;
    It_002A8270() { vt = D_00378BD8; cur = 0; }
    ~It_002A8270() { vt = D_00378BD8; }
    Data_002A8270* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002A8270* Advance(Node_002A8270* c) {
        cur = c->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002A8270* First(Node_002A8270* h) {
        cur = h;
        return Next();
    }
};

struct Pool_002A8270 {
    char pad[0xDC];
    int mDC;
};

struct Ent_002A8270 {
    char pad[0xBC];
    Ref_002A8270 mBC;
};

extern Pool_002A8270* D_00388A70;
extern void* D_0038E0A0;
extern void* D_0038FC78;
extern char D_003789A8[];
extern char D_003789C0[];
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_00235F58(void* p);
extern "C" void func_00235F68(void* p);
extern "C" float func_001DD618(void* p);
extern "C" void func_001DD5A0(void* p, float f);
extern "C" void func_001F0370(char* s, int a, int b, int c);
extern "C" Ent_002A8270* func_001F0750(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
extern "C" void* func_0022E040(void* p);
extern "C" void* func_00187B48(void* p, int v);
extern "C" int func_001EFDC0(Ent_002A8270* p);
extern "C" void func_001F09E8(Ent_002A8270* p);

struct Obj_002A8270 {
    char pad[0x10C];
    Node_002A8270 m10C;
    void Run();
};

void Obj_002A8270::Run()
{
    It_002A8270 it;
    void* snd = D_0038E0A0;
    void* ctl = D_0038FC78;
    func_0010A950(D_00388A70, D_00388A70->mDC);
    func_00235F58(ctl);
    float vol = func_001DD618(snd);
    func_001DD5A0(snd, 0.0f);
    func_001F0370(D_003789A8, 0, 0, 0);
    Data_002A8270* d = it.First(&m10C);
    It_002A8270* p = &it;
    if (d) {
        do {
            Data_002A8270* nx = p->Next();
            Ent_002A8270* e = func_001F0750(d->m20, 0, 0, 0, d->m18, 0, 0, 0, 0, 0);
            e->mBC = func_00187B48(func_0022E040(ctl), d->m1C);
            while (func_001EFDC0(e))
                ;
            func_001F09E8(e);
            delete d;
            d = nx;
        } while (d);
    }
    func_001F0370(D_003789C0, 0, 0, 0);
    func_001DD5A0(snd, vol);
    func_00235F68(ctl);
    func_0010A9B0(D_00388A70);
}
