extern "C" char* func_0013C5B8(void* o);

struct Src_00135120 {
    int m0[2];
    char* m_8;
};

struct Obj_00135120 {
    int m0[8];
    void* m_20;
    Src_00135120* m_24;
    char* Get();
};

char* Obj_00135120::Get()
{
    if (m_20)
        return func_0013C5B8(m_20);
    return m_24->m_8 + 0x10;
}
