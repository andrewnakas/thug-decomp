extern "C" void func_0010A070(void*);
extern "C" void* func_0010A080(void*, int);
extern "C" int func_00108560(void*, void*);

struct FileSys_00108A00 {
    int m0;
    void* m_arc;
    void* m_item;
    int m_C;
    void* m_missing;
    void* m_list;
    int Select(void* item);
};

int FileSys_00108A00::Select(void* item)
{
    if (m_missing == item)
        return 0;
    if (m_item == item)
        return m_C;
    func_0010A070(m_list);
    void* arc;
    while ((arc = func_0010A080(m_list, 0))) {
        int r = func_00108560(arc, item);
        if (r) {
            m_arc = arc;
            m_item = item;
            m_C = r;
            return r;
        }
    }
    m_missing = item;
    return 0;
}
