extern "C" void* func_0010A298(void*, const char*, int);
extern "C" void func_0010A398(void*, const char*);
extern "C" void func_00108330(void*, int);

struct FileSys_00109128 {
    char pad[0x14];
    void* m_list;
    int m_18;
    void Unmount(const char* name, int force);
};

void FileSys_00109128::Unmount(const char* name, int force)
{
    if (m_18)
        return;
    void* arc = func_0010A298(m_list, name, 1);
    if (!arc && force)
        return;
    func_0010A398(m_list, name);
    if (arc)
        func_00108330(arc, 3);
}
