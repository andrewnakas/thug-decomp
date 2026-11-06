extern "C" int func_0031BBD0(int thread);
extern "C" int func_0031BCE0(int sema);
extern "C" int func_0031BCB0(int sema);
extern "C" int func_0031BAB0(int thread);

class Obj_00201200 {
public:
    char m_pad0[0x4294];
    int m_thread;
    int m_sema0;
    int m_sema1;
    int m_sema2;
    int m_sema3;
    char m_pad42A8[0x42D4 - 0x42A8];
    int m_quit;
    char m_pad42D8[0x4358 - 0x42D8];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual int Finish();
    void Shutdown();
};

void Obj_00201200::Shutdown()
{
    m_quit = 1;
    func_0031BBD0(m_thread);
    func_0031BCE0(m_sema3);
    func_0031BCB0(m_sema1);
    func_0031BCB0(m_sema2);
    func_0031BCB0(m_sema0);
    func_0031BCB0(m_sema3);
    func_0031BAB0(m_thread);
    Finish();
}
