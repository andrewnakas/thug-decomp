typedef int qword __attribute__((mode(TI)));

struct Vec_001B7B28 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001B7B28() {}
    Vec_001B7B28(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Mat_001B7B28 {
    Vec_001B7B28 r[4];
};

struct Obj_001B7B28 {
    char pad0[0x50];
    Vec_001B7B28 m_pos;
    char pad60[0x70 - 0x60];
    Mat_001B7B28 m_mat;
};

struct Node_001B7B28 {
    char pad0[0x20];
    Node_001B7B28* m_next;
};

struct Geom_001B7B28 {
    int m0;
    Node_001B7B28* m_first;
};

class Base_001B7B28 {
public:
    char pad0[0x18];
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
    virtual Geom_001B7B28* GetGeom();
};

struct C_001B7B28 {
    char pad0[0xC];
    Obj_001B7B28* m_obj;
    char pad10[0x20 - 0x10];
    Base_001B7B28* m_model;
    int FindClosest(Vec_001B7B28* out, Vec_001B7B28* target);
};

extern "C" void func_0026B5B8(Geom_001B7B28* g, Mat_001B7B28* m);
extern "C" void func_0026B6A8(Vec_001B7B28* out, Geom_001B7B28* g, Node_001B7B28* n);
extern "C" void func_001016A8(Vec_001B7B28* v, Vec_001B7B28* m);

int C_001B7B28::FindClosest(Vec_001B7B28* out, Vec_001B7B28* target)
{
    int best = -1;
    Base_001B7B28* model = m_model;
    Obj_001B7B28* o = m_obj;
    if (model && o) {
        Geom_001B7B28* g = model->GetGeom();
        if (g) {
            Mat_001B7B28 m = o->m_mat;
            m.r[0].w = 0.0f;
            m.r[1].w = 0.0f;
            m.r[2].w = 0.0f;
            m.r[3] = o->m_pos;
            m.r[3].w = 1.0f;
            func_0026B5B8(g, &m);
            Node_001B7B28* n = g->m_first;
            Vec_001B7B28 bestPos(0.0f, 0.0f, 0.0f, 1.0f);
            float bestDist = 1.000000004e+14f;
            int i = 0;
            for (; n; n = n->m_next, i++) {
                Vec_001B7B28 v;
                func_0026B6A8(&v, g, n);
                v.x = v.x - o->m_pos.x;
                v.y = v.y - o->m_pos.y;
                v.z = v.z - o->m_pos.z;
                v.w = v.w - o->m_pos.w;
                func_001016A8(&v, &o->m_mat.r[1]);
                v.x = v.x + o->m_pos.x;
                v.y = v.y + o->m_pos.y;
                v.z = v.z + o->m_pos.z;
                v.w = v.w + o->m_pos.w;
                Vec_001B7B28 d(v.x - target->x, v.y - target->y, v.z - target->z, v.w - target->w);
                float dist = d.x * d.x + d.y * d.y + d.z * d.z;
                if (dist < bestDist) {
                    bestDist = dist;
                    best = i;
                    bestPos = v;
                }
            }
            *out = bestPos;
        }
    }
    return best;
}
