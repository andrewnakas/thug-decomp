extern "C" int func_001E6D18(void* p, unsigned int key);

struct Obj_00246C10 {
    char pad[0x20];
    void* m_p;
    int Lookup();
};

int Obj_00246C10::Lookup()
{
    return func_001E6D18(m_p, 0x38221DF4);
}
