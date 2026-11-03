struct FileSys_00109328 {
    int m0;
    void* m_arc;
};

extern FileSys_00109328* D_00388A30;
extern int D_00388A34;
extern "C" void* func_00108858(FileSys_00109328*, const char*);
extern "C" void func_00108688(void*, int);
extern "C" void func_001085E0(void*);
extern "C" void func_001086A8(void*, int);

void* func_00109328(const char* name, const char* mode, int arg)
{
    void* h = func_00108858(D_00388A30, name);
    if (h) {
        func_00108688(D_00388A30->m_arc, arg);
        int bad = 0;
        for (const char* p = mode; *p; p++) {
            char c = *p;
            if (c != 'r' && c != 'b')
                bad = 1;
        }
        if (!bad) {
            func_001085E0(D_00388A30->m_arc);
            D_00388A34 = 1;
            return h;
        }
        func_001086A8(D_00388A30->m_arc, arg);
    }
    D_00388A34 = 0;
    return 0;
}
