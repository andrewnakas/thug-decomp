struct Obj_0012BAA8;
struct Handle_0012BAA8;

extern "C" void func_00183C98(Obj_0012BAA8* o, Handle_0012BAA8* h);
extern "C" void func_00183CB8(Obj_0012BAA8* o, Handle_0012BAA8* h);

struct Sub_0012BAA8 {
    char pad[0x80];
};

struct Obj_0012BAA8 {
    char pad[0xC];
    unsigned int m_flags;
    char pad10[0x50];
    Obj_0012BAA8* m60;
    char pad64[0x1C];
    Sub_0012BAA8 m80;
    char pad100[0x88];
    float m188;
    float m18C;
};

struct Handle_0012BAA8 {
    Obj_0012BAA8* m_obj;
    Handle_0012BAA8* m_prev;
    Handle_0012BAA8* m_next;
    Handle_0012BAA8(Obj_0012BAA8* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    ~Handle_0012BAA8()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012BAA8& operator=(Obj_0012BAA8* o)
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
    Obj_0012BAA8* operator->() const { return m_obj; }
    operator Obj_0012BAA8*() const { return m_obj; }
};

class Struct1E6978 {
public:
    int m_w[2];
    Struct1E6978();
    ~Struct1E6978();
};

struct C_0012BAA8;

extern "C" float func_0012C128(Sub_0012BAA8* s);
extern "C" float func_0012C130(Sub_0012BAA8* s);
extern "C" void func_00125798(C_0012BAA8* self, void* r);
extern "C" void func_00123CD8(Obj_0012BAA8* o, float x, float y);
extern "C" void func_00123A18(Obj_0012BAA8* o, float x, float y, int f);
extern "C" void func_0012B728(C_0012BAA8* o, int a, int b, int c);
extern "C" void func_00189750(void* mgr, unsigned int type, int target, unsigned int id, Struct1E6978* s, int a);
extern "C" void func_001E7268(Struct1E6978* s, char* name, int v);

extern void* D_0038C7B0;
extern char D_0035CF78[];

struct C_0012BAA8 {
    char pad[0xC];
    unsigned int m_flags;
    char pad10[0x44];
    Obj_0012BAA8* m54;
    char pad58[0x78];
    char mD0[0xB8];
    float m188;
    float m18C;
    char pad190[0x10];
    int m1A0;
    int m1A4;
    int m1A8;
    int m1AC;
    float m1B0;
    float m1B4;
    int m1B8;
    float m1BC;
    float m1C0;
    float m1C4;
    void Layout();
};

void C_0012BAA8::Layout()
{
    float total = 0.0f;
    float maxw = total;
    int fixed = m1BC > 0.0001f;
    if (fixed) {
        Handle_0012BAA8 h = m54;
        while (h) {
            float w;
            if (m1B8) {
                w = h->m188;
                w *= func_0012C128(&h->m80);
            } else {
                w = h->m18C;
                w *= func_0012C130(&h->m80);
            }
            total += m1BC;
            if (maxw < w)
                maxw = w;
            h = h->m60;
        }
    } else {
        Handle_0012BAA8 h = m54;
        while (h) {
            float len, w;
            if (m1B8) {
                w = h->m188 * m1C0;
                len = h->m18C * m1C0;
            } else {
                w = h->m18C * m1C0;
                len = h->m188 * m1C0;
            }
            total += len + m1C4;
            if (maxw < w)
                maxw = w;
            h = h->m60;
        }
        total -= m1C4;
    }
    if (m_flags & 0x2000) {
        if (m1B8) {
            if (m18C < total)
                m18C = total;
        } else {
            if (m188 < total)
                m188 = total;
        }
    } else if (m1B8) {
        m188 = maxw;
        m18C = total;
    } else {
        m18C = maxw;
        m188 = total;
    }
    func_00125798(this, mD0);
    m_flags |= 0x400;
    float pos;
    if (m1B8)
        pos = (m1B4 + 1.0f) * (m18C - total) * 0.5f;
    else
        pos = (m1B0 + 1.0f) * (m188 - total) * 0.5f;
    if (fixed) {
        pos += m1BC * 0.5f;
        Handle_0012BAA8 h = m54;
        while (h) {
            if (m1B8) {
                func_00123CD8(h, m1B0, 0.0f);
                func_00123A18(h, (m1B0 + 1.0f) * m188 * 0.5f, pos, 1);
            } else {
                func_00123CD8(h, 0.0f, m1B4);
                func_00123A18(h, pos, (m1B4 + 1.0f) * m18C * 0.5f, 1);
            }
            pos += m1BC;
            h = h->m60;
        }
    } else {
        Handle_0012BAA8 h = m54;
        while (h) {
            if (m1B8) {
                float half = h->m18C * m1C0 * 0.5f;
                func_00123CD8(h, m1B0, 0.0f);
                pos += half;
                func_00123A18(h, (m1B0 + 1.0f) * m188 * 0.5f, pos, 1);
                pos += half;
            } else {
                float half = h->m188 * m1C0 * 0.5f;
                func_00123CD8(h, 0.0f, m1B4);
                pos += half;
                func_00123A18(h, pos, (m1B4 + 1.0f) * m18C * 0.5f, 1);
                pos += half;
            }
            pos += m1C4;
            if (h->m_flags & 0x400)
                m_flags |= 0x400;
            h = h->m60;
        }
    }
    if (!m1A4 && m54 && m1A8) {
        m1A0 = 0;
        func_0012B728(this, 1, 1, 1);
        if (m1A4) {
            Struct1E6978 s;
            func_001E7268(&s, D_0035CF78, m1AC);
            func_00189750(D_0038C7B0, 0x9D3FB516, m1A4, 0x36B2EE74, &s, 0);
        }
    }
}
