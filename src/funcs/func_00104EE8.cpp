extern "C" void func_00105078(void* self);
extern char D_0035A9E8[];

// List head with its vtable pointer written explicitly (vtable D_0035A9E8),
// as LinkNode1049E0 in func_001049E0.
struct ListHead104EE8 {
    int m0;
    unsigned int m4;
    int m8;
    ListHead104EE8* m_prev;
    ListHead104EE8* m_next;
    void* m_vtbl;

    ListHead104EE8()
    {
        m4 = 0xFFFFFFFF;
        m8 = 0;
        m_prev = this;
        m_next = this;
        m_vtbl = D_0035A9E8;
    }
};

class Obj104EE8 {
public:
    int m0;
    int m4;
    int m8;
    ListHead104EE8 m_list0;
    ListHead104EE8 m_list1;
    void* m3C;
    void* m40;
    int m44;
    int m48;
    Obj104EE8();
};

Obj104EE8::Obj104EE8() : m4(0)
{
    m44 = 0;
    m48 = 0;
    func_00105078(this);
    m40 = m3C;
    m44 = 0;
    m48 = 0;
}
