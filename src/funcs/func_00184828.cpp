class Obj_00184828;
extern "C" void func_00183C98(Obj_00184828* list, void* ref);
extern "C" void func_00183CB8(Obj_00184828* list, void* ref);
extern "C" void func_001F1200(void* track, int a, int b);

class Ptr_00184828 {
public:
    Obj_00184828* m_obj;
    Ptr_00184828* m_prev;
    Ptr_00184828* m_next;

    Ptr_00184828(Obj_00184828* obj)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = obj;
        if (m_obj) {
            func_00183C98(m_obj, this);
        }
    }
    ~Ptr_00184828()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
};

class Ref_00184828 {
public:
    Obj_00184828* m_obj;
    Ref_00184828* m_prev;
    Ref_00184828* m_next;

    Ref_00184828(const Ptr_00184828& o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o.m_obj;
        if (m_obj) {
            func_00183C98(m_obj, this);
        }
    }
    ~Ref_00184828()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
};

class Obj_00184828 {
public:
    char pad0[0x14];
    void* m_track;

    bool Play(int a, int b);
};

bool Obj_00184828::Play(int a, int b)
{
    if (!m_track) {
        return true;
    }
    Ref_00184828 self(this);
    func_001F1200(m_track, a, b);
    return self.m_obj != 0;
}
