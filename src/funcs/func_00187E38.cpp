extern void* D_0038C7B0;
extern "C" void func_00183C98(void* list, void* ref);
extern "C" void func_00183CB8(void* list, void* ref);
extern "C" void func_00189C88(void* mgr, void* voice);

class Ref_00187E38 {
public:
    void* m_obj;
    Ref_00187E38* m_prev;
    Ref_00187E38* m_next;

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

class Voice_00187E38 {
public:
    Ref_00187E38 m_owner;

    void Attach(void* owner);
};

void Voice_00187E38::Attach(void* owner)
{
    m_owner.Set(owner);
    func_00189C88(D_0038C7B0, this);
}
