struct Child_0022B940 {
    int m0;
    int m4;
    virtual ~Child_0022B940() = 0;
};

struct Obj_0022B940 {
    char pad[0x60];
    Child_0022B940* m_60;
    void Release();
};

extern "C" void func_00255938(Child_0022B940* c);

void Obj_0022B940::Release()
{
    if (m_60) {
        func_00255938(m_60);
        delete m_60;
        m_60 = 0;
    }
}
