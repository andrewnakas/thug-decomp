typedef int qword __attribute__((mode(TI)));

struct Vec_00114FC0 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        } f;
    };
};

struct Quat_00114FC0 {
    float x, y, z, w;
};

struct Mat_00114FC0 {
    Vec_00114FC0 r[4];
    void Ident()
    {
        r[0].f.x = 1.0f; r[0].f.y = 0.0f; r[0].f.z = 0.0f; r[0].f.w = 0.0f;
        r[1].f.x = 0.0f; r[1].f.y = 1.0f; r[1].f.z = 0.0f; r[1].f.w = 0.0f;
        r[2].f.x = 0.0f; r[2].f.y = 0.0f; r[2].f.z = 1.0f; r[2].f.w = 0.0f;
        r[3].f.x = 0.0f; r[3].f.y = 0.0f; r[3].f.z = 0.0f; r[3].f.w = 1.0f;
    }
};

struct Obj_00114FC0 {
    int m_0;
    int m_4;
    void* m_vt;
    void* m_C;
    void* m_10;
    int pad14[3];
    Vec_00114FC0 m_dir;
    float m_30;
};

extern char D_0035C4C8[];

extern "C" void func_00114F70(Obj_00114FC0* self);
extern "C" void* func_00131F98(int w, int h, int a, int b);
extern "C" void func_00131FB8(void* t, void* src, int);
extern "C" void func_003233B8(Vec_00114FC0* out, Vec_00114FC0* in);
extern "C" void* func_001046B0(int size);
extern "C" void* func_00114C30(void* p);
extern "C" void func_00114E08(void* p, Quat_00114FC0* q);
extern "C" void func_00114E20(void* p, Mat_00114FC0* m);
extern "C" void func_0013EE68(void* src, int);

extern "C" Obj_00114FC0* func_00114FC0(Obj_00114FC0* self, void* src, const Vec_00114FC0& dir, float f)
{
    func_00114F70(self);
    self->m_vt = D_0035C4C8;
    self->m_4 = 1;
    self->m_10 = func_00131F98(0x100, 0x100, 0x10, 0x10);
    func_00131FB8(self->m_10, src, 0);
    self->m_30 = f;
    self->m_dir.q = dir.q;
    func_003233B8(&self->m_dir, &self->m_dir);
    self->m_C = func_00114C30(func_001046B0(0xC0));
    Quat_00114FC0 q;
    q.x = 0.0f;
    q.y = 0.0f;
    q.z = 0.0f;
    q.w = 1.0f;
    func_00114E08(self->m_C, &q);
    Mat_00114FC0 m;
    m.Ident();
    m.r[2].q = self->m_dir.q;
    func_003233B8(&m.r[2], &m.r[2]);
    m.r[0].f.x = m.r[2].f.z;
    m.r[0].f.y = -m.r[2].f.x;
    m.r[0].f.z = -m.r[2].f.y;
    m.r[1].f.x = m.r[2].f.y;
    m.r[1].f.y = -m.r[2].f.z;
    m.r[1].f.z = -m.r[2].f.x;
    func_00114E20(self->m_C, &m);
    func_0013EE68(src, 1);
    return self;
}
