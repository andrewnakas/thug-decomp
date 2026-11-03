extern "C" void func_0010A070(void*);
extern "C" void* func_0010A080(void*, int);
extern "C" int func_001083B0(void*, const char*);

struct FileSys_00108960 {
    int m0;
    void* m_arc;
    void* m_item;
    int m_C;
    int m10;
    void* m_list;
    bool Exists(const char* name);
};

bool FileSys_00108960::Exists(const char* name)
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
    while ((arc = func_0010A080(m_list, 0)))
        if (func_001083B0(arc, path))
            return true;
    return false;
}
