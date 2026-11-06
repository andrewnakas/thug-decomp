extern "C" void func_00183C98(void* list, void* ref);
extern "C" void func_00183CB8(void* list, void* ref);

class Ref_00184C88 {
public:
    void* m_obj;
    Ref_00184C88* m_prev;
    Ref_00184C88* m_next;

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

struct Sound_00184C88 {
    char pad0[0xBC];
    Ref_00184C88 m_owner;
};

extern "C" void* func_00121960(int size);
extern "C" Sound_00184C88* func_001EE428(void* p);
extern "C" void func_001EEF18(Sound_00184C88* track, int a, int b);

class Obj_00184C88 {
public:
    char pad0[0x14];
    Sound_00184C88* m_track;

    void Play(int a, int b);
};

void Obj_00184C88::Play(int a, int b)
{
    if (!m_track) {
        Sound_00184C88* t = func_001EE428(func_00121960(0xF4));
        m_track = t;
        t->m_owner.Set(this);
    }
    func_001EEF18(m_track, a, b);
}
