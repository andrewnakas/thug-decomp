extern int D_0038C6D4;
extern "C" void func_00184000(void* obj, unsigned int key, int value);

class Child_00183E90 {
public:
    char pad[0x2C];
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void Changed(void* owner, int value);
};

class Obj_00183E90 {
public:
    char pad0[0x10];
    Child_00183E90* m_child;
    int m14;
    int m18;

    void Set18(int value);
};

void Obj_00183E90::Set18(int value)
{
    if (m18 != D_0038C6D4 && m_child) {
        m_child->Changed(this, value);
    }
    m18 = value;
    func_00184000(this, 0x40C698AF, value);
}
