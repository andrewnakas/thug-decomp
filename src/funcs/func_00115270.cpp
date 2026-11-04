typedef int qword __attribute__((mode(TI)));

struct Vec_00115270 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        } f;
    };
};

struct Quat_00115270 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        } f;
    };
    void Ident()
    {
        f.x = 0.0f;
        f.y = 0.0f;
        f.z = 0.0f;
        f.w = 1.0f;
    }
};

struct Mat_00115270 {
    Vec_00115270 r[4];
    void Ident()
    {
        r[0].f.x = 1.0f; r[0].f.y = 0.0f; r[0].f.z = 0.0f; r[0].f.w = 0.0f;
        r[1].f.x = 0.0f; r[1].f.y = 1.0f; r[1].f.z = 0.0f; r[1].f.w = 0.0f;
        r[2].f.x = 0.0f; r[2].f.y = 0.0f; r[2].f.z = 1.0f; r[2].f.w = 0.0f;
        r[3].f.x = 0.0f; r[3].f.y = 0.0f; r[3].f.z = 0.0f; r[3].f.w = 1.0f;
    }
};

struct Obj_00115270 {
    int m_0;
    int m_4;
    void* m_vt;
    void* m_C;
    void* m_10;
    int pad14[3];
    Vec_00115270 m_dir;
    float m_30;
};


extern "C" void func_003233B8(Vec_00115270* out, Vec_00115270* in);
extern "C" void func_00114E08(void* p, Quat_00115270* q);
extern "C" void func_00114E20(void* p, Mat_00115270* m);

extern "C" Quat_00115270* func_00114E18(void* p);
extern "C" void func_00132018(void* tex, void* xform);

extern "C" void func_00115270(Obj_00115270* self, const Vec_00115270& dir)
{
    Quat_00115270 saved;
    saved.q = func_00114E18(self->m_C)->q;
    self->m_dir.q = dir.q;
    func_003233B8(&self->m_dir, &self->m_dir);
    Quat_00115270 q;
    q.Ident();
    func_00114E08(self->m_C, &q);
    Mat_00115270 m;
    m.Ident();
    m.r[2].q = self->m_dir.q;
    m.r[0].f.x = m.r[2].f.z;
    m.r[0].f.y = -m.r[2].f.x;
    m.r[0].f.z = -m.r[2].f.y;
    m.r[1].f.x = m.r[2].f.y;
    m.r[1].f.y = -m.r[2].f.z;
    m.r[1].f.z = -m.r[2].f.x;
    func_00114E20(self->m_C, &m);
    func_00114E08(self->m_C, &saved);
    func_00132018(self->m_10, self->m_C);
}
