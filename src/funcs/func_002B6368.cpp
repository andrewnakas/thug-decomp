struct Vec_002B6368 {
    float x, y, z, w;
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Part_002B6368 {
    char pad0[0x10];
    Vec_002B6368 m10;
    int m20;
    int m24;
    Part_002B6368* m28;
    Vec_002B6368* GetPos() { return &m10; }
};

struct Tmpl_002B6368 {
    char m0;
    char m1;
    char pad2[2];
    int m4;
    Part_002B6368* m8;
};

struct Inst_002B6368 {
    char m0;
    char m1;
    char pad2[2];
    int m4;
    char pad8[0x10];
    void* m18;
};

extern "C" Part_002B6368* func_002B67D0(void* pool);
extern "C" void func_002B6290(Inst_002B6368* self, Part_002B6368* p);

extern "C" void func_002B6368(Inst_002B6368* self, Tmpl_002B6368* t, Vec_002B6368* pos, int rot, int g)
{
    for (Part_002B6368* p = t->m8; p; p = p->m28) {
        Part_002B6368* q = func_002B67D0(self->m18);
        float x = 0.0f;
        float z = 0.0f;
        switch (rot) {
        case 0:
            x = p->GetPos()->x;
            z = p->GetPos()->z;
            break;
        case 1:
            x = p->GetPos()->z;
            z = -p->GetPos()->x;
            break;
        case 2:
            x = -p->GetPos()->x;
            z = -p->GetPos()->z;
            break;
        case 3:
            x = -p->GetPos()->z;
            z = p->GetPos()->x;
            break;
        }
        float y = p->GetPos()->y;
        x += pos->x;
        y += pos->y;
        z += pos->z;
        q->GetPos()->Set(x, y, z, 1.0f);
        q->m20 = p->m20;
        q->m24 = g;
        func_002B6290(self, q);
    }
    self->m4 = t->m4;
    self->m1 = t->m1;
}
