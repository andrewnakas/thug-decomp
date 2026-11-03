typedef int qword __attribute__((mode(TI)));

struct Vec_001187A0 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        } f;
    };
};

struct Mat_001187A0 {
    Vec_001187A0 r[4];
};

struct Obj_001187A0 {
    char pad0[0x18];
    int m_18;
    int pad1C;
    Vec_001187A0 m_rot;
    Vec_001187A0 m_pos;
};

extern "C" int func_001E5628(unsigned int crc, int);
extern "C" Vec_001187A0* func_00114E18(void* xf);
extern "C" Mat_001187A0* func_00114E48(void* xf);
extern "C" int func_00118348(Obj_001187A0* self, int);

static inline void QuatToMat_001187A0(Mat_001187A0* m, const Vec_001187A0& q)
{
    Vec_001187A0 sq;
    Vec_001187A0 c;
    Vec_001187A0 w;
    sq.f.x = q.f.x * q.f.x;
    sq.f.y = q.f.y * q.f.y;
    sq.f.z = q.f.z * q.f.z;
    c.f.x = q.f.y * q.f.z;
    c.f.y = q.f.z * q.f.x;
    c.f.z = q.f.x * q.f.y;
    w.f.x = q.f.w * q.f.x;
    w.f.y = q.f.w * q.f.y;
    w.f.z = q.f.w * q.f.z;
    m->r[0].f.x = 1.0f - (sq.f.y + sq.f.z + (sq.f.y + sq.f.z));
    m->r[0].f.y = (c.f.z + w.f.z) + (c.f.z + w.f.z);
    m->r[0].f.z = (c.f.y - w.f.y) + (c.f.y - w.f.y);
    m->r[0].f.w = 0.0f;
    m->r[1].f.x = (c.f.z - w.f.z) + (c.f.z - w.f.z);
    m->r[1].f.y = 1.0f - (sq.f.x + sq.f.z + (sq.f.x + sq.f.z));
    m->r[1].f.z = (c.f.x + w.f.x) + (c.f.x + w.f.x);
    m->r[1].f.w = 0.0f;
    m->r[2].f.x = (c.f.y + w.f.y) + (c.f.y + w.f.y);
    m->r[2].f.y = (c.f.x - w.f.x) + (c.f.x - w.f.x);
    m->r[2].f.z = 1.0f - (sq.f.x + sq.f.y + (sq.f.x + sq.f.y));
    m->r[2].f.w = 0.0f;
}

extern "C" int func_001187A0(Obj_001187A0* self, void* xf)
{
    if (!self->m_18) {
        return 0;
    }
    func_001E5628(0x2F510F45, 0);
    Vec_001187A0* pos = func_00114E18(xf);
    Mat_001187A0* m = func_00114E48(xf);
    pos->q = self->m_pos.q;
    Vec_001187A0 t;
    t.f.x = 0.0f;
    t.f.y = 0.0f;
    t.f.z = 0.0f;
    t.f.w = 1.0f;
    Vec_001187A0 q;
    q.q = self->m_rot.q;
    q.f.x = -q.f.x;
    q.f.y = -q.f.y;
    q.f.z = -q.f.z;
    QuatToMat_001187A0(m, q);
    m->r[3].q = t.q;
    m->r[3].f.w = 1.0f;
    func_00118348(self, 1);
    return 1;
}
