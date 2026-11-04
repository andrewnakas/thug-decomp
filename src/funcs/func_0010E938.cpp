extern "C" int func_00109598(void*);
extern "C" int func_001094F8(void*, int, int);
extern "C" int func_001093F8(void*, int);
extern "C" int func_001092D0();
extern "C" void* func_00109328(const char*, const char*, int);
extern volatile int D_00388C90;
extern char D_00388C88[];

class File_0010E938 {
public:
    volatile int m_result;
    int m4[3];
    int m_op;
    int m14[2];
    int m_1C;
    int m20;
    int m_24;
    int m28[2];
    void* m_archive;
    volatile int m_count;
    int AddCount() { return ++m_count; }
    virtual void V1();
    virtual void Notify(int op, int result, int arg);
    virtual void V3();
    virtual bool OpenDevice(const char* name);
    virtual bool CloseDevice();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual int SeekDevice(int offset, int whence);
    bool Close();
};

bool File_0010E938::Close()
{
    m_op = 6;
    if (m_archive) {
        m_result = func_001093F8(m_archive, 1);
        D_00388C90++;
        AddCount();
        Notify(m_op, m_result, 0);
        return m_result != 0;
    }
    return CloseDevice();
}
