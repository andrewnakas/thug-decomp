class Data_001351D0 {
public:
    int m0[3];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual int Count();
};

extern "C" int func_0013C668(void* model);

class Obj_001351D0 {
public:
    char pad0[0x20];
    void* m_model;
    Data_001351D0* m_data;
    int Count();
};

int Obj_001351D0::Count()
{
    if (m_model) {
        return func_0013C668(m_model);
    }
    return m_data->Count();
}
