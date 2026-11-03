extern "C" void func_0010A070(void*);
extern "C" void* func_0010A080(void*, int);
extern "C" void* func_001084B0(void*, const char*, int*, char*);

struct FileSys_00109828 {
    int m0;
    void* m_arc;
    void* m_item;
    int m_C;
    int m10;
    void* m_list;
    void* Load(const char* name, int* size, char* buf);
};

void* FileSys_00109828::Load(const char* name, int* size, char* buf)
{
    char path[0x80];
    char* d = path;
    *d = *name;
    while (*d) {
        if (*d == '/')
            *d = '\\';
        name++;
        d++;
        *d = *name;
    }
    func_0010A070(m_list);
    void* arc;
    while ((arc = func_0010A080(m_list, 0))) {
        void* r = func_001084B0(arc, path, size, buf);
        if (r)
            return r;
    }
    return 0;
}
