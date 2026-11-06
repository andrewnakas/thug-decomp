typedef int qword __attribute__((mode(TI)));

struct Vec_001B4828 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_001B4828() {}
    Vec_001B4828(const Vec_001B4828& o) { q = o.q; }
    Vec_001B4828& operator=(const Vec_001B4828& o) { q = o.q; return *this; }
};

extern "C" void func_00183CB8(int obj, int* ref);

static inline void Release_001B4828(int* ref)
{
    if (*ref) {
        func_00183CB8(*ref, ref);
        *ref = 0;
    }
}

struct Face8_001B4828 {
    char pad0[4];
    unsigned char v[3];
    char pad7;
};

struct Face10_001B4828 {
    char pad0[4];
    unsigned short v[3];
};

struct Geom_001B4828 {
    char pad0[0xA];
    unsigned char m_small;
    char padB;
    void* m_faces;
    int Vert(int face, int k)
    {
        if (m_small) return ((Face8_001B4828*)m_faces)[face].v[k];
        return ((Face10_001B4828*)m_faces)[face].v[k];
    }
};

struct Sector_001B4828 {
    int m0;
    int m4;
    Geom_001B4828* m_geom;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual Vec_001B4828 GetVertex(int i);
};

struct Feeler_001B4828 {
    Vec_001B4828 m_start;
    Vec_001B4828 m_end;
    char pad20[0x50 - 0x20];
    int m_face;
    char pad54[0x6C - 0x54];
    int m6C;
    Sector_001B4828* m_sector;
    char pad74[0xA0 - 0x74];
    Vec_001B4828 m_point;
    Vec_001B4828 m_normal;
    int m_ref;
    char padC4[0xE0 - 0xC4];
    ~Feeler_001B4828()
    {
        Release_001B4828(&m_ref);
    }
};

extern "C" void func_00209240(Feeler_001B4828* f);
extern "C" int func_002099C0(Feeler_001B4828* f, void* a, void* b, int c);

struct Obj_001B4828 {
    int Probe(void* start, void* end, Vec_001B4828* point, Vec_001B4828* verts);
};

extern "C" void func_001B4C60(Obj_001B4828* self, int a);

int Obj_001B4828::Probe(void* start, void* end, Vec_001B4828* point, Vec_001B4828* verts)
{
    Feeler_001B4828 f;
    func_00209240(&f);
    if (func_002099C0(&f, start, end, 0)) {
        Sector_001B4828* s = f.m_sector;
        int face = f.m_face;
        Geom_001B4828* g = s->m_geom;
        verts[0] = s->GetVertex(g->Vert(face, 0));
        verts[1] = s->GetVertex(g->Vert(face, 1));
        verts[2] = s->GetVertex(g->Vert(face, 2));
        *point = f.m_point;
        func_001B4C60(this, f.m6C);
        return 1;
    }
    return 0;
}
