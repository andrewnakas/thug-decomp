extern "C" void func_001EE5F8(void* track);
extern "C" void func_001F0DE8(void* obj);

class Child_00184950 {
public:
    char pad[0x2C];
    virtual void V1();
    virtual void V2();
    virtual void Release(void* owner);
    virtual void Changed(void* owner, int value);
    virtual void V5();
    virtual void Attach(void* owner);
};

class Obj_00184950 {
public:
    char pad0[0xC];
    unsigned int m_flags;
    Child_00184950* m_child;
    void* m_track;

    void Restart();
};

void Obj_00184950::Restart()
{
    if (m_track) {
        func_001EE5F8(m_track);
    }
    func_001F0DE8(this);
    Child_00184950* child = m_child;
    m_flags &= 0xFFFFFFFD;
    child->Release(this);
    child->Attach(this);
    m_flags |= 1;
}
