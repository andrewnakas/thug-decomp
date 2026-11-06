struct Vec_002695E8 {
    float x, y, z, w;
    Vec_002695E8() {}
    Vec_002695E8(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Rot_002695E8 {
    float m[4][4];
};

struct Node_002695E8 {
    char pad[0x30];
    Vec_002695E8 m_pos;
    char pad40[0x50 - 0x40];
    Node_002695E8* m_next;
    Node_002695E8* m_prev;
    unsigned int m_flags;
    char pad5C[4];
};

extern "C" float fabsf(float);
extern "C" bool func_001CB7B8(Node_002695E8* n, int a);

struct Rail_002695E8;
extern "C" void func_0026B208(Rot_002695E8* out, Rail_002695E8* self, Node_002695E8* n);
extern "C" bool func_001CBE60(void* a, Vec_002695E8* p0, Vec_002695E8* p1, Rot_002695E8* r, void* b);
extern "C" bool func_001CC188(void* a, Vec_002695E8* p0, Vec_002695E8* p1, Rot_002695E8* r, void* b);

struct Rail_002695E8 {
    char pad[0x50];
    Node_002695E8* m_nodes;
    char pad54[0x5C - 0x54];
    int m_count;
    bool Find(Vec_002695E8* p, int fwd, void* a, float r, float h, void* b, Node_002695E8** out);
};

bool Rail_002695E8::Find(Vec_002695E8* p, int fwd, void* a, float r, float h, void* b, Node_002695E8** out)
{
    float r2 = r * r;
    for (int i = m_count; --i != -1;) {
        Node_002695E8* n = &m_nodes[i];
        if (!(n->m_flags & 0x20)) {
            continue;
        }
        if (!func_001CB7B8(n, 2)) {
            continue;
        }
        float dx = n->m_pos.x - p->x;
        if (fabsf(dx) > r) {
            continue;
        }
        float dz = n->m_pos.z - p->z;
        if (fabsf(dz) > r) {
            continue;
        }
        float dy = n->m_pos.y - p->y;
        if (fabsf(dy) > h) {
            continue;
        }
        Vec_002695E8 d(dx, dy, dz, n->m_pos.w - p->w);
        if (d.x * d.x + d.z * d.z > r2) {
            continue;
        }
        Node_002695E8* o = n->m_next;
        if (!o) {
            o = n->m_prev;
        }
        Rot_002695E8 rot;
        bool miss;
        if (fwd) {
            Vec_002695E8* from = &n->m_pos;
            Vec_002695E8* to = &o->m_pos;
            func_0026B208(&rot, this, n);
            miss = !func_001CBE60(a, from, to, &rot, b);
        } else {
            Vec_002695E8* from = &o->m_pos;
            Vec_002695E8* to = &n->m_pos;
            func_0026B208(&rot, this, o);
            miss = !func_001CC188(a, from, to, &rot, b);
        }
        if (miss) {
            continue;
        }
        if (fwd) {
            *out = n;
        } else {
            *out = o;
        }
        return true;
    }
    return false;
}
