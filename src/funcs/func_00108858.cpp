extern "C" void func_0010A070(void*);
extern "C" void* func_0010A080(void*, int);
extern "C" void* func_001083D8(void*, const char*);
extern "C" int func_00108560(void*, void*);
extern "C" void func_0031CD60(const char*, ...);
extern char D_0035AF08[], D_0035AF20[];

struct FileSys_00108858 {
    int m0;
    void* m_arc;
    void* m_item;
    int m_C;
    int m10;
    void* m_list;
    void* Open(const char* name);
};

void* FileSys_00108858::Open(const char* name)
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
    void* arc = func_0010A080(m_list, 0);
    while (arc) {
        void* item = func_001083D8(arc, path);
        if (item) {
            m_arc = arc;
            m_item = item;
            m_C = func_00108560(arc, item);
            func_0031CD60(D_0035AF08, path);
            return item;
        }
        arc = func_0010A080(m_list, 0);
    }
    func_0031CD60(D_0035AF20, path);
    return 0;
}
