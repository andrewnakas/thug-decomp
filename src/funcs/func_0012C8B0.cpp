struct Obj_0012C8B0;
struct Handle_0012C8B0;

extern "C" void func_00183C98(Obj_0012C8B0* o, Handle_0012C8B0* h);
extern "C" void func_00183CB8(Obj_0012C8B0* o, Handle_0012C8B0* h);

struct Obj_0012C8B0 {
    char pad[0x54];
    Obj_0012C8B0* m54;
    char pad58[0x8];
    Obj_0012C8B0* m60;
};

struct Handle_0012C8B0 {
    Obj_0012C8B0* m_obj;
    Handle_0012C8B0* m_prev;
    Handle_0012C8B0* m_next;
    Handle_0012C8B0(Obj_0012C8B0* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    Handle_0012C8B0(const Handle_0012C8B0& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012C8B0()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012C8B0& operator=(Obj_0012C8B0* o)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        m_obj = o;
        if (o)
            func_00183C98(o, this);
        return *this;
    }
    Obj_0012C8B0* operator->() const { return m_obj; }
    operator Obj_0012C8B0*() const { return m_obj; }
};

static inline Handle_0012C8B0 Make_0012C8B0(const Handle_0012C8B0& t)
{
    return t;
}

struct C_0012C8B0;

extern "C" Obj_0012C8B0* func_001241E8(Obj_0012C8B0* o, int a, int* idx);
extern "C" Obj_0012C8B0* func_00124238(Obj_0012C8B0* o, int i);
extern "C" int func_00124288(Obj_0012C8B0* o);
extern "C" void func_00123CD8(Obj_0012C8B0* o, float x, float y);
extern "C" void func_001239D0(Obj_0012C8B0* o, float* x, float* y);
extern "C" void func_00123A18(Obj_0012C8B0* o, float x, float y, int f);
extern "C" void func_00123EB0(Obj_0012C8B0* o, float a, int f);
extern "C" void func_0012CD50(C_0012C8B0* self, Handle_0012C8B0* h, float* x, float* y, float* w, float* hh);

struct C_0012C8B0 {
    char pad[0x1BC];
    Obj_0012C8B0* m1BC;
    int m1C0;
    char pad1C4[0xC];
    int m1D0;
    float m1D4;
    float m1D8;
    int m1DC;
    float m1E0;
    float m1E4;
    int m1E8;
    void Scroll();
};

void C_0012C8B0::Scroll()
{
    Handle_0012C8B0 sel = Make_0012C8B0(0);
    float after = 0.0f;
    float before = 0.0f;
    int idx = 0;
    if (m1BC) {
        if (m1C0)
            sel = func_001241E8(m1BC, m1C0, &idx);
        else
            sel = func_00124238(m1BC, 0);
        if (sel) {
            int n = func_00124288(m1BC);
            float s = m1E4;
            if (0.0f <= s) {
                int half = m1DC / 2;
                if (!(idx < half))
                    before = s * (float)((m1DC - 1) / 2);
                if (idx < n - half)
                    after = s * (float)half;
            }
        }
    }
    if (sel) {
        func_00123CD8(m1BC, -1.0f, -1.0f);
        float ox, oy;
        func_001239D0(m1BC, &ox, &oy);
        float r0, pos, r2, size, r4, r5;
        if (m1E8)
            func_0012CD50(this, &sel, &r0, &pos, &r2, &size);
        else
            func_0012CD50(this, &sel, &pos, &r4, &size, &r5);
        float s = m1E4;
        if (0.0f <= s) {
            size = s;
            pos = s * (float)idx;
        }
        float cur = m1D4;
        if (pos < cur + before) {
            m1D4 = cur - m1D8;
            if (m1D4 < pos)
                m1D4 = pos - before;
            m1D0 = 1;
        } else if (cur + m1E0 - after < pos + size) {
            m1D4 = cur + m1D8;
            if (pos + size < m1D4 + m1E0)
                m1D4 = pos + size - m1E0 + after;
            m1D0 = 1;
        }
        if (m1D0) {
            if (m1E8)
                func_00123A18(m1BC, ox, -m1D4, 1);
            else
                func_00123A18(m1BC, -m1D4, oy, 1);
            idx = 0;
            Handle_0012C8B0 it = Make_0012C8B0(m1BC->m54);
            while (it) {
                if (m1E8)
                    func_0012CD50(this, &it, &r0, &pos, &r2, &size);
                else
                    func_0012CD50(this, &it, &pos, &r4, &size, &r5);
                float s2 = m1E4;
                if (0.0f <= s2) {
                    size = s2;
                    pos = s2 * (float)idx;
                }
                if (pos >= m1D4 && pos + size <= m1D4 + m1E0)
                    func_00123EB0(it, 1.0f, 1);
                else
                    func_00123EB0(it, 0.0f, 1);
                it = it->m60;
                idx++;
            }
            m1D0 = 0;
        }
    }
}
