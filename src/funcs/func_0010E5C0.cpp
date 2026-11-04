extern "C" int func_00109598(void*);
extern "C" int func_001094F8(void*, int, int);
extern "C" int func_00109458(void*, int, int, void*);
extern volatile int D_00388C90;

class File_0010E5C0 {
public:
    volatile int m_result;
    int m4[3];
    int m_op;
    int m14[7];
    void* m_archive;
    volatile int m_count;
    int AddCount() { return ++m_count; }
    virtual void V1();
    virtual void Notify(int op, int result, int arg);
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
    virtual void V13();
    virtual int ReadAllDevice(void* buf);
    virtual int ReadDevice(void* buf, int size, int count);
    int ReadAll(void* buf);
};

int File_0010E5C0::ReadAll(void* buf)
{
    m_op = 2;
    if (m_archive) {
        int size = func_00109598(m_archive);
        func_001094F8(m_archive, 0, 0);
        m_result = func_00109458(buf, 1, size, m_archive);
        D_00388C90++;
        AddCount();
        Notify(m_op, m_result, 0);
        return m_result;
    }
    return ReadAllDevice(buf);
}
