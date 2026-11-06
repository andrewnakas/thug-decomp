extern "C" int func_001E7DE8(void* s, unsigned int name, void* out, int req);

struct Obj_00184078 {
    int m0[9];
    void* m_24;
    int Get(unsigned int name, void* out);
};

int Obj_00184078::Get(unsigned int name, void* out)
{
    if (m_24)
        return func_001E7DE8(m_24, name, out, 0);
    return 0;
}
