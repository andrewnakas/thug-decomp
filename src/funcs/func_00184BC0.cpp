extern "C" void func_00183C98(void* list, void* ref);
extern "C" void func_00183CB8(void* list, void* ref);

class Ref_00184BC0 {
public:
    void* m_obj;
    Ref_00184BC0* m_prev;
    Ref_00184BC0* m_next;

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

struct Sound_00184BC0 {
    char pad0[0xBC];
    Ref_00184BC0 m_owner;
};

extern "C" Sound_00184BC0* func_001F0750(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);

extern "C" void func_001F0638(int a, int b, int c, int d);
extern "C" void func_001EFDC0(Sound_00184BC0* s);

extern "C" void func_00184BC0(void* owner, int a, int c, int flag, int d, int b)
{
    if (flag) {
        func_001F0638(a, 0, c, d);
    }
    Sound_00184BC0* s = func_001F0750(a, b, 0, 0, c, 0, 0, 0, 0, 0);
    s->m_owner.Set(owner);
    func_001EFDC0(s);
}
