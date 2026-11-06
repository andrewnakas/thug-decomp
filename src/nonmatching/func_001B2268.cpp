/* fuzzy: 66.1 */
typedef int qword __attribute__((mode(TI)));
extern "C" float sqrtf(float);
extern "C" float fabsf(float);
typedef union Vec { qword q; float c[4]; } Vec;
typedef struct Mat { Vec r[4]; } Mat;
typedef struct Node { char pad[0x50]; Vec m_pos; char pad2[0x60]; Mat m_rot; } Node;
typedef struct Comp { char pad[0x30]; float m_30; } Comp;
typedef struct Slot { Node* m_node; int m_4; int m_8; } Slot;
typedef struct Obj { char pad[0xC]; Node* m_C; char pad2[0x88 - 0x10]; Slot* m_88; } Obj;
static inline float Len(const Vec* v) { return sqrtf(v->c[0] * v->c[0] + v->c[1] * v->c[1] + v->c[2] * v->c[2]); }
static inline float Dot(const Vec* a, const Vec* b) { return a->c[0] * b->c[0] + a->c[1] * b->c[1] + a->c[2] * b->c[2]; }
static inline void Sub(Vec* r, const Vec* a, const Vec* b)
{
    float x = a->c[0] - b->c[0]; float y = a->c[1] - b->c[1]; float z = a->c[2] - b->c[2]; float w = a->c[3] - b->c[3];
    r->c[0] = x; r->c[1] = y; r->c[2] = z; r->c[3] = w;
}
static inline void Cross(Vec* r, const Vec* a, const Vec* b)
{
    float x = a->c[1] * b->c[2] - a->c[2] * b->c[1];
    float y = a->c[2] * b->c[0] - a->c[0] * b->c[2];
    float z = a->c[0] * b->c[1] - a->c[1] * b->c[0];
    r->c[0] = x; r->c[1] = y; r->c[2] = z; r->c[3] = 0.0f;
}
extern "C" float func_001E5318(unsigned int id, int a);
extern "C" Comp* func_00185578(void* self, unsigned int id);
extern "C" float func_003412F0(float x);
extern "C" void func_001B3038(void* self, float a, float b, float c, float d);
extern "C" int func_001B2268(Obj* self)
{
    int hit = 0;
    Slot* list = self->m_88;
    if (list) {
        Slot* s = list;
        Mat m;
        m.r[0].q = self->m_C->m_rot.r[0].q;
        m.r[1].q = self->m_C->m_rot.r[1].q;
        m.r[2].q = self->m_C->m_rot.r[2].q;
        m.r[3].q = self->m_C->m_rot.r[3].q;
        float range = func_001E5318(0x7A78F471, 0);
        float speed = func_001E5318(0xD1E6177B, 0);
        Comp* mine = func_00185578(self->m_C, 0x0A015E17);
        int i;
        for (i = 0; i < 50; i++, s++) {
            Node* n = s->m_node;
            if (!n) continue;
            Node* o = n;
            if (o == self->m_C) continue;
            float tol = func_001E5318(0x21B13FFC, 1);
            if (fabsf(self->m_C->m_pos.c[1] - o->m_pos.c[1]) > tol) continue;
            Vec* fwd = &m.r[2];
            Vec* ofwd = &o->m_rot.r[2];
            float dot = Dot(fwd, ofwd);
            Vec d;
            if (dot <= 0.0f) {
                Sub(&d, &o->m_pos, &self->m_C->m_pos);
                if (Dot(fwd, &d) <= 0.0f) continue;
            }
            Comp* other = func_00185578(o, 0x0A015E17);
            if (dot > 0.0f && mine->m_30 <= other->m_30) continue;
            Sub(&d, &self->m_C->m_pos, &o->m_pos);
            float dist = Len(&d);
            if (dist <= range) {
                float a = func_003412F0(dot / (Len(fwd) * Len(ofwd)));
                if (a > 6.283185482f) a -= (int)(a * 0.1591549367f) * 6.283185482f;
                if (fabsf(a - 3.141592741f) < func_001E5318(0xD2E22CEC, 1)) {
                    Cross(&d, fwd, &n->m_rot.r[2]);
                    a = 1.570796371f;
                    if (d.c[1] < 0.0f) a = -1.570796371f;
                }
                hit = 1;
                func_001B3038(self, a, speed, dist, range);
            }
        }
    }
    return hit;
}
