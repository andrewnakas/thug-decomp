typedef int qword __attribute__((mode(TI)));

union Vec_0029CEA0 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
    void Set(float x, float y, float z, float w) { f.x = x; f.y = y; f.z = z; f.w = w; }
};
static inline void Add_0029CEA0(Vec_0029CEA0* r, const Vec_0029CEA0& a, const Vec_0029CEA0& b) { r->f.x = a.f.x + b.f.x; r->f.y = a.f.y + b.f.y; r->f.z = a.f.z + b.f.z; r->f.w = a.f.w; }


struct Mat_0029CEA0 {
    Vec_0029CEA0 r[4];
    void Ident()
    {
        r[0].f.x = 1.0f; r[0].f.y = 0.0f; r[0].f.z = 0.0f; r[0].f.w = 0.0f;
        r[1].f.x = 0.0f; r[1].f.y = 1.0f; r[1].f.z = 0.0f; r[1].f.w = 0.0f;
        r[2].f.x = 0.0f; r[2].f.y = 0.0f; r[2].f.z = 1.0f; r[2].f.w = 0.0f;
        r[3].f.x = 0.0f; r[3].f.y = 0.0f; r[3].f.z = 0.0f; r[3].f.w = 1.0f;
    }
};

struct Line_0029CEA0 {
    Vec_0029CEA0 p;
    Vec_0029CEA0 n;
};

extern "C" void func_00183CB8(void* p, void* pp);

struct Coll_0029CEA0 {
    char pad[0xA0];
    Vec_0029CEA0 hit;
    Vec_0029CEA0 normal;
    struct Ref {
        void* p;
        ~Ref() {
            if (p) {
                func_00183CB8(p, this);
                p = 0;
            }
        }
    } mC0;
    char pad2[0xE0 - 0xC4];
};

struct Snd_0029CEA0 {
    int m0;
    int m4;
    virtual void F0();
    virtual void F1();
    virtual void Play(Line_0029CEA0* l, Mat_0029CEA0* m, Vec_0029CEA0* n);
};

extern "C" void func_00209240(Coll_0029CEA0* c);
extern "C" void func_00209360(Coll_0029CEA0* c, Vec_0029CEA0* a);
extern "C" void func_00209370(Coll_0029CEA0* c, Line_0029CEA0* b);
extern "C" bool func_002093E8(Coll_0029CEA0* c, int a, int b);

struct Obj_0029CEA0;
extern "C" void func_0029CE00(Obj_0029CEA0* o);
extern "C" void func_0029CE58(Obj_0029CEA0* o);

struct Obj_0029CEA0 {
    char pad[0x40];
    Vec_0029CEA0 pos;
    char pad2[0x8C - 0x50];
    float m8C;
    char pad3[0xA0 - 0x90];
    Snd_0029CEA0* mA0;
    void Update();
};

void Obj_0029CEA0::Update()
{
    Vec_0029CEA0 start = pos;
    start.f.y += m8C;
    Coll_0029CEA0 c;
    func_00209240(&c);
    func_00209360(&c, &start);
    Line_0029CEA0 l;
    l.n.Set(0.0f, -10000.0f, 0.0f, 0.0f);
    Add_0029CEA0(&l.p, start, l.n);
    func_00209370(&c, &l);
    if (func_002093E8(&c, 1, 0)) {
        func_0029CE00(this);
        Mat_0029CEA0 m;
        m.Ident();
        Vec_0029CEA0 n;
        l.p = c.hit;
        l.n = c.normal;
        n = c.normal;
        mA0->Play(&l, &m, &n);
    } else {
        func_0029CE58(this);
    }
}
