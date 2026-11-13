/* fuzzy: 96.4 */
/* blocked: 13 words, all spill-slot offsets (0x58-0x68) of the five hoisted addresses &h, &t, &a, &b, pk+0xC; the slot order is reload's, from the PRE/loop invariant pseudo order, not reached by source order. */
struct Elem_002C9FA8;
struct Handle_002C9FA8;

extern "C" void func_00183C98(Elem_002C9FA8* o, Handle_002C9FA8* h);
extern "C" void func_00183CB8(Elem_002C9FA8* o, Handle_002C9FA8* h);

struct Ref_002C9FA8 {
    Elem_002C9FA8* m_obj;
    Handle_002C9FA8* m_prev;
    Handle_002C9FA8* m_next;
    ~Ref_002C9FA8()
    {
        if (m_obj) {
            func_00183CB8(m_obj, (Handle_002C9FA8*)this);
            m_obj = 0;
        }
    }
};

struct Handle_002C9FA8 {
    Elem_002C9FA8* m_obj;
    Handle_002C9FA8* m_prev;
    Handle_002C9FA8* m_next;
    Handle_002C9FA8(const Ref_002C9FA8& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_002C9FA8()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
};

class Struct1E6978 {
public:
    int m_w[2];
    Struct1E6978();
    ~Struct1E6978();
};

struct Array_002C9FA8 {
    int m_w[4];
};

struct Entry_002C9FA8 {
    int id;
    char* name;
};

struct Park_002C9FA8 {
    char pad0[0x8];
    Entry_002C9FA8 m8[0x28];
    int m148;
    int m14C;
    char m150;
    signed char m151;
};

struct Piece_002C9FA8 {
    char pad0[0x8];
    int m8;
    int Locked() { return (m8 & 0x80) != 0; }
};

struct Sub_002C9FA8 {
    int m0;
    void* m4;
};

extern void* D_0038C7B0;
extern void* D_00389A30;

extern char D_0037ABE0[];
extern char D_0037ABB0[];
extern char D_0037ABF8[];
extern char D_0037ABC0[];
extern char D_00392848[];
extern char D_00392850[];
extern char D_0037AC08[];
extern char D_0037AC20[];
extern char D_0037AC30[];
extern char D_0037AC40[];
extern char D_0037AC60[];
extern char D_0037AC78[];
extern char D_00392858[];

extern "C" void* func_002C95E0(int v);
extern "C" int func_002C8C38(void* self);
extern "C" void func_002C86F0(void* self);
extern "C" void* func_001895B0(void* mgr, int id);
extern "C" void func_00189750(void* mgr, unsigned int type, int target, unsigned int id, void* s, int a);
extern "C" void func_001F0370(char* name, Struct1E6978* params, int a, int b);
extern "C" void func_001E73C8(Struct1E6978* s, char* name, int v);
extern "C" void func_001E7268(Struct1E6978* s, char* name, int v);
extern "C" void func_001E7360(Struct1E6978* s, unsigned int name, unsigned int v);
extern "C" void func_001E76D8(Struct1E6978* s, char* name, Array_002C9FA8* arr);
extern "C" Piece_002C9FA8* func_002BE5F0(void* self, int key, int* out);
extern "C" void* func_001E8DD0(Array_002C9FA8* a);
extern "C" void func_001E8DE8(Array_002C9FA8* a, int flags);
extern "C" void func_001E6518(Array_002C9FA8* a);
extern "C" void func_002BB1B0(Piece_002C9FA8* p, Array_002C9FA8* a);
extern "C" int func_001F0D78(char* name);
extern "C" Ref_002C9FA8 func_0012DB48(void* mgr, int id, int a);
extern "C" void func_001239D0(Elem_002C9FA8* o, float* a, float* b);
extern "C" void func_00123A18(Elem_002C9FA8* o, float a, float b, int f);
extern "C" void func_00123DB0(Elem_002C9FA8* o, bool b, int f, float lo, float hi);
extern "C" void func_001262A0(Elem_002C9FA8* o, char* s);

struct Obj_002C9FA8 {
    int m0;
    Sub_002C9FA8 m4;
    char padC[0x10 - 0xC];
    Park_002C9FA8* m10;
    int m14;
    int m18;
    Sub_002C9FA8* GetSub() { return &m4; }
    void Show(Park_002C9FA8* pk, int unused, int mode);
};

void Obj_002C9FA8::Show(Park_002C9FA8* pk, int unused, int mode)
{
    int on = 0;
    int lim = 0;
    if (pk->m151) {
        on = 1;
        lim = func_002C8C38(func_002C95E0(1));
        func_002C86F0(func_002C95E0(1));
    }
    void* mgr = D_0038C7B0;
    if (m10) {
        int id = m10->m8[m18].id;
        if (func_001895B0(mgr, id))
            func_00189750(mgr, 0x4ADF0CD3, id, 0x36B2EE74, 0, 0);
    }
    if (pk != m10) {
        func_001F0370(D_0037ABE0, 0, 0, 0);
        for (int i = 0; i < pk->m148; i++) {
            int id = pk->m8[i].id;
            if (on) {
                Struct1E6978 s;
                func_001E73C8(&s, D_0037ABB0, id);
                if (i < lim)
                    func_001E7268(&s, D_0037ABF8, i + 1);
                else
                    func_001E7360(&s, 0, 0x66DA03B3);
                func_001F0370(D_0037ABC0, &s, 0, 0);
            } else {
                Piece_002C9FA8* p = func_002BE5F0(GetSub()->m4, id, 0);
                Struct1E6978 s;
                func_001E73C8(&s, D_0037ABB0, id);
                if (p->Locked()) {
                    func_001E73C8(&s, D_00392848, id);
                    func_001F0370(D_0037ABC0, &s, 0, 0);
                } else {
                    Array_002C9FA8 a;
                    func_001E8DD0(&a);
                    func_002BB1B0(p, &a);
                    func_001E76D8(&s, D_00392850, &a);
                    func_001F0370(D_0037ABC0, &s, 0, 0);
                    func_001E6518(&a);
                    func_001E8DE8(&a, 2);
                }
            }
        }
        func_001F0370(D_0037AC08, 0, 0, 0);
        Struct1E6978 s;
        func_001E7268(&s, D_0037AC20, mode);
        func_001E7268(&s, D_0037AC30, m14);
        func_001F0370(D_0037AC40, &s, 0, 0);
        m10 = pk;
        m14 = mode;
    }
    if (func_001895B0(mgr, pk->m8[pk->m14C].id))
        func_00189750(mgr, 0x9D3FB516, pk->m8[pk->m14C].id, 0x36B2EE74, 0, 0);
    int sel = pk->m14C;
    m18 = sel;
    int lo = sel - 3;
    int hi = sel + 3;
    int n = pk->m148;
    if (n < 8) {
        hi = n - 1;
        lo = 0;
    } else if (lo < 0) {
        hi -= lo;
        lo = 0;
    } else if (hi >= n) {
        lo += n - hi - 1;
        hi = n - 1;
    }
    void* screen = D_00389A30;
    Handle_002C9FA8 h = func_0012DB48(screen, func_001F0D78(D_0037AC60), 1);
    float a;
    float b;
    func_001239D0(h.m_obj, &a, &b);
    float start = lo * 375.0f / pk->m148;
    float end = (hi + 1) * 375.0f / pk->m148;
    func_00123A18(h.m_obj, start, b, 1);
    func_00123DB0(h.m_obj, 0, 1, (end - start) * 0.25f, 1.0f);
    Handle_002C9FA8 t = func_0012DB48(screen, func_001F0D78(D_0037AC78), 1);
    if (pk->m8[m18].name)
        func_001262A0(t.m_obj, pk->m8[m18].name);
    else
        func_001262A0(t.m_obj, D_00392858);
}
