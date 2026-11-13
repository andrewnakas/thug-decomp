struct Obj_001276E0;
struct Handle_001276E0;

extern "C" void func_00183C98(Obj_001276E0* o, Handle_001276E0* h);
extern "C" void func_00183CB8(Obj_001276E0* o, Handle_001276E0* h);

struct Handle_001276E0 {
    Obj_001276E0* m_obj;
    Handle_001276E0* m_prev;
    Handle_001276E0* m_next;
    Handle_001276E0(Obj_001276E0* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    Handle_001276E0(const Handle_001276E0& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_001276E0()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_001276E0& operator=(const Handle_001276E0& h)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
        return *this;
    }
    Obj_001276E0* operator->() const { return m_obj; }
    operator Obj_001276E0*() const { return m_obj; }
};

struct Obj_001276E0 {
    unsigned int pad0[3];
    unsigned int mC;
    char pad10[8];
    unsigned int m18;
    char pad1C[0x38];
    Handle_001276E0 m54;
    Handle_001276E0 m60;
    char pad6C[0x18C - 0x6C];
    float m18C;
    char pad190[0x10];
    int m1A0;
    char** m1A4;
    int m1A8;
    int m1AC;
    int m1B0;
    int m1B4;
    int m1B8;
    char pad1BC[8];
    float m1C4;
    float m1C8;
    float m1CC;
    int m1D0;
    char pad1D4[8];
    int m1DC;
};

struct Mgr_001276E0 {
    char pad[0x2C];
    virtual void V0();
    virtual void Add(Obj_001276E0* o);
};

struct Heap_001276E0 {
    char pad[0xE4];
    void* mE4;
};

extern Heap_001276E0* D_00388A70;
extern Mgr_001276E0* D_00389A30;
extern char D_003897B8[];

extern "C" void func_00124118(Obj_001276E0* self, int a);
extern "C" void func_0012D8B0(Mgr_001276E0* m, unsigned int id, int a, int b, int c);
extern "C" void func_0012DA10(Mgr_001276E0* m, const Handle_001276E0& parent, const Handle_001276E0& child, int a);
extern "C" void func_0010A950(void* heap, void* sub);
extern "C" void func_0010A9B0(void* heap);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void* func_001046B0(int size);
extern "C" Obj_001276E0* func_00125F10(void* mem);
extern "C" void func_00128078(Obj_001276E0* self, char* str);
extern "C" void* func_00130B80(int font);
extern "C" void func_00135890(void* font, char* str, float* w, float* h);
extern "C" void func_00126260(Obj_001276E0* e, int font);
extern "C" void func_001262A0(Obj_001276E0* e, char* str);
extern "C" void func_00123DB0(Obj_001276E0* e, int a, int b, float sx, float sy);

static inline Handle_001276E0 First_001276E0(Obj_001276E0* o)
{
    return Handle_001276E0(o->m54.m_obj);
}


extern "C" void func_001276E0(Obj_001276E0* self, char** strs, int n)
{
    Mgr_001276E0* mgr = D_00389A30;
    func_00124118(self, 0);
    Handle_001276E0 h(First_001276E0(self).m_obj);
    while (h) {
        Handle_001276E0 next(Handle_001276E0(h->m60.m_obj).m_obj);
        func_0012D8B0(mgr, h->m18, 1, 0, 0);
        h = next;
    }
    func_0010A950(D_00388A70, D_00388A70->mE4);
    char** lines = (char**)func_0010A638(D_00388A70, 0x50, 1, 0);
    self->m1A4 = lines;
    lines[0] = (char*)func_0010A638(D_00388A70, 0x780, 1, 0);
    func_0010A9B0(D_00388A70);
    for (int j = 1; j < 20; j++)
        self->m1A4[j] = self->m1A4[0] + j * 0x60;
    for (int k = 0; k < 20; k++)
        self->m1A4[k][0] = 0;
    self->m1B0 = 0;
    self->m1A8 = 0;
    self->m1AC = 0;
    self->m1B4 = 0;
    if (self->m1DC) {
        self->m18C = 0.0f;
        self->m1B8 = 0;
    }
    int i;
    for (i = 0; i < n; i++)
        func_00128078(self, strs[i]);
    if (n) {
        self->m1A8++;
        self->m1AC++;
    }
    self->m1D0 = self->m1AC;
    int line = 0;
    if (self->m1A8 >= self->m1B8) {
        if (self->m1DC) {
            float w, ht;
            func_00135890(func_00130B80(self->m1A0), D_003897B8, &w, &ht);
            float lh = ht * self->m1C4 * self->m1C8;
            float tot = self->m1A8 * lh;
            self->m18C = tot;
            int lines = (int)tot / (int)lh;
            self->m1B0 = 0;
            self->m1A8 = 0;
            self->m1AC = 0;
            self->m1B4 = 0;
            self->m1B8 = lines;
            for (i = 0; i < n; i++)
                func_00128078(self, strs[i]);
            self->m1D0 = self->m1B8;
        } else {
            line = self->m1A8 % self->m1B8;
            self->m1D0 = self->m1B8;
        }
    }
    self->m1CC = 0.0f;
    for (int k = 0; k < self->m1D0; k++) {
        func_0010A950(D_00388A70, D_00388A70->mE4);
        Obj_001276E0* e = func_00125F10(func_001046B0(0x1E0));
        func_0010A9B0(D_00388A70);
        mgr->Add(e);
        func_0012DA10(mgr, Handle_001276E0(self), Handle_001276E0(e), 1);
        func_00126260(e, self->m1A0);
        func_001262A0(e, self->m1A4[line]);
        line++;
        func_00123DB0(e, 0, 0, self->m1C4, self->m1C4);
        self->m1CC += e->m18C * self->m1C4 * self->m1C8;
        if (line >= self->m1B8)
            line = 0;
    }
    func_0010A8D8(D_00388A70, self->m1A4[0]);
    func_0010A8D8(D_00388A70, self->m1A4);
    func_00124118(self, 1);
    self->mC |= 0x1000;
}
