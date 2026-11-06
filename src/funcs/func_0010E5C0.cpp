extern volatile int D_00388C90;
extern "C" int func_00109598(void* h);
extern "C" int func_001094F8(void* h, int off, int whence);
extern "C" int func_00109458(void* buf, int n, int size, void* h);

class File_0010E5C0 {
public:
    volatile int m_result;
    int m4[3];
    int m_op;
    int m14[2];
    volatile int m1C;
    int m20[2];
    volatile int m28;
    volatile int m2C;
    void* m_handle;
    volatile int m_count;
    virtual void V0();
    virtual void Done(int op, int result, int z);
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual int ReadAllAsync(void* buf);
    int ReadAll(void* buf);
    int Bump() { return ++m_count; }
};

int File_0010E5C0::ReadAll(void* buf)
{
    m_op = 2;
    if (m_handle) {
        int size = func_00109598(m_handle);
        func_001094F8(m_handle, 0, 0);
        m_result = func_00109458(buf, 1, size, m_handle);
        D_00388C90++;
        Bump();
        Done(m_op, m_result, 0);
        return m_result;
    }
    return ReadAllAsync(buf);
}
