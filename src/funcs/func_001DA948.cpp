typedef int qword __attribute__((mode(TI)));

struct Vec_001DA948 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Box_001DA948 {
    Vec_001DA948 min;
    Vec_001DA948 max;
};

class Ent_001DA948 {
public:
    int m0;
    unsigned short m4;
    char pad6[6];
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
    virtual void V11();
    virtual void V12();
    virtual int Touches(Box_001DA948* b);
};

struct Node_001DA948 {
    int m0;
    Ent_001DA948* m4;
    int m8;
    Node_001DA948* mC;
    Node_001DA948* Valid() { if (~(int)m4 == 0) return 0; return this; }
};

struct Query_001DA948 {
    Box_001DA948 m_box;
    void Run(Box_001DA948* b);
};

extern Node_001DA948 D_003E82E0;
extern float D_0038DE44;
extern "C" void func_001DA8F0(Query_001DA948* q);
extern "C" void func_00101F40(Box_001DA948* out, Vec_001DA948* a, Vec_001DA948* b);
extern "C" int func_001324B8(Box_001DA948* b);
extern "C" Ent_001DA948** func_00208E80(int w, Box_001DA948* b);
extern "C" Box_001DA948* func_001022D8(Box_001DA948* b);
extern "C" void func_00102358(Box_001DA948* b, Vec_001DA948* p);
extern "C" void func_001DAB38(Query_001DA948* q, Ent_001DA948* e);
extern "C" void func_001DAB78(Query_001DA948* q, Ent_001DA948* e);

void Query_001DA948::Run(Box_001DA948* b)
{
    func_001DA8F0(this);
    Box_001DA948 tmp;
    func_00101F40(&tmp, &b->min, &b->max);
    int w = func_001324B8(&tmp);
    if (!w) return;
    m_box.min.q = b->min.q;
    m_box.max.q = b->max.q;
    Ent_001DA948** list = func_00208E80(w, &tmp);
    Box_001DA948 bb;
    func_001022D8(&bb);
    float h = D_0038DE44;
    Vec_001DA948 v;
    v.q = b->max.q;
    v.x += h;
    v.y += h;
    v.z += h;
    func_00102358(&bb, &v);
    v.q = b->min.q;
    v.x -= h;
    v.y -= h;
    v.z -= h;
    func_00102358(&bb, &v);
    Ent_001DA948* e;
    while ((e = *list) != 0) {
        if (e->Touches(&bb)) func_001DAB38(this, e);
        list++;
    }
    Node_001DA948* n = D_003E82E0.mC->Valid();
    while (n) {
        e = n->m4;
        if (e && !(e->m4 & 6)) {
            if (e->Touches(&bb)) func_001DAB78(this, e);
        }
        n = n->mC->Valid();
    }
}
