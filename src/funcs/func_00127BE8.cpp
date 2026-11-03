struct Obj_00127BE8;

extern "C" void func_00183C98(Obj_00127BE8* o, void* h);
extern "C" void func_00183CB8(Obj_00127BE8* o, void* h);

struct Handle_00127BE8 {
    Obj_00127BE8* m_obj;
    Handle_00127BE8* m_prev;
    Handle_00127BE8* m_next;
    Handle_00127BE8(Obj_00127BE8* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    ~Handle_00127BE8()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_00127BE8& operator=(const Handle_00127BE8& h)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
        return *this;
    }
};

struct Obj_00127BE8 {
    char pad0[0x60];
    Obj_00127BE8* m60;
    char pad64[0x1A0 - 0x64];
    char* m1A0;
};

struct C_00127BE8 {
    char pad0[0x54];
    Obj_00127BE8* m54;
    bool GetText(char* buf, int size);
};

extern char D_003897B0[];
extern char D_003897C0[];
extern "C" int func_00331BB8(const char* s);
extern "C" char* func_00331678(char* d, const char* s);

bool C_00127BE8::GetText(char* buf, int size)
{
    *buf = D_003897B0[0];
    int len = 0;
    Handle_00127BE8 h(Handle_00127BE8(m54).m_obj);
    while (h.m_obj) {
        Handle_00127BE8 next(Handle_00127BE8(h.m_obj->m60).m_obj);
        char* t = h.m_obj->m1A0;
        len += func_00331BB8(t);
        if (next.m_obj)
            len++;
        if (len < size) {
            func_00331678(buf, t);
            if (next.m_obj)
                func_00331678(buf, D_003897C0);
        } else
            return false;
        h = next;
    }
    return true;
}
