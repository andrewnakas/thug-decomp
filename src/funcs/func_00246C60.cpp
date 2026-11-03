extern "C" int func_001E8618(void* p, unsigned int key);

struct Obj_00246C60 {
    char pad[0x20];
    void* m_p;
    int Lookup();
};

int Obj_00246C60::Lookup()
{
    return func_001E8618(m_p, 0xD15EA00);
}
