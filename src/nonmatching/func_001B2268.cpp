/* fuzzy: 86.4 */
typedef int qword __attribute__((mode(TI)));
extern "C" float sqrtf(float);
extern "C" float fabsf(float);
struct Vec {
    union {
        qword q;
        float c[4];
    };
    Vec() {}
    Vec(float x, float y, float z, float w) { c[0] = x; c[1] = y; c[2] = z; c[3] = w; }
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    float Length() const { return sqrtf(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]); }
};
static inline Vec operator-(const Vec& a, const Vec& b) { return Vec(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]); }
static inline float Dot(const Vec& a, const Vec& b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }
static inline Vec Cross(const Vec& a, const Vec& b)
{
    return Vec(a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0], 0.0f);
}
struct Mat {
    Vec r[4];
    Vec& operator[](int i) { return r[i]; }
};
struct Node { char pad[0x50]; Vec m_pos; char pad2[0x60]; Mat m_rot; };
struct Comp { char pad[0x30]; float m_30; };
struct Slot { Node* m_node; int m_4; int m_8; };
struct Obj { char pad[0xC]; Node* m_C; char pad2[0x88 - 0x10]; Slot* m_88; };
extern "C" float func_001E5318(unsigned int id, int a);
extern "C" Comp* func_00185578(void* self, unsigned int id);
extern "C" float func_003412F0(float x);
extern "C" void func_001B3038(void* self, float a, float b, float c, float d);
extern "C" int func_001B2268(Obj* self)
{
    int hit = 0;
    Slot* list = self->m_88;
    if (list) {
        Mat m = self->m_C->m_rot;
        float range = func_001E5318(0x7A78F471, 0);
        float speed = func_001E5318(0xD1E6177B, 0);
        Comp* mine = func_00185578(self->m_C, 0x0A015E17);
        Slot* s = list;
        for (int i = 0; i < 50; i++, s++) {
            Node* o = s->m_node;
            if (!o) continue;
            if (o == self->m_C) continue;
            float tol = func_001E5318(0x21B13FFC, 1);
            if (fabsf(self->m_C->m_pos[1] - o->m_pos[1]) > tol) continue;
            float dot = Dot(m[2], o->m_rot[2]);
            if (dot <= 0.0f) {
                Vec to = o->m_pos - self->m_C->m_pos;
                if (Dot(m[2], to) <= 0.0f) continue;
            }
            Comp* other = func_00185578(o, 0x0A015E17);
            if (dot > 0.0f && mine->m_30 <= other->m_30) continue;
            float dist = (self->m_C->m_pos - o->m_pos).Length();
            if (dist <= range) {
                float a = func_003412F0(dot / (m[2].Length() * o->m_rot[2].Length()));
                if (a > 6.283185482f) a -= (int)(a * 0.1591549367f) * 6.283185482f;
                if (fabsf(a - 3.141592741f) < func_001E5318(0xD2E22CEC, 1)) {
                    Vec side = Cross(m[2], o->m_rot[2]);
                    a = 1.570796371f;
                    if (side[1] < 0.0f) a = -1.570796371f;
                }
                hit = 1;
                func_001B3038(self, a, speed, dist, range);
            }
        }
    }
    return hit;
}
