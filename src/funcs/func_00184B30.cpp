extern "C" void func_00183C98(void* list, void* ref);
extern "C" void func_00183CB8(void* list, void* ref);

class Ref_00184B30 {
public:
    void* m_obj;
    Ref_00184B30* m_prev;
    Ref_00184B30* m_next;

    void Set(void* obj)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        m_obj = obj;
        if (obj) {
            func_00183C98(obj, this);
        }
    }
};

struct Sound_00184B30 {
    char pad0[0xBC];
    Ref_00184B30 m_owner;
};

extern "C" Sound_00184B30* func_001F0750(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);

extern "C" Sound_00184B30* func_00184B30(void* owner, int a, int b, int f, int j)
{
    Sound_00184B30* s = func_001F0750(a, b, 0, 0, -1, f, 0, 0, 0, j);
    s->m_owner.Set(owner);
    return s;
}
