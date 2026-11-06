extern "C" int func_001E8180(void* self, unsigned int name, int* out, int req);

struct C_00262358 {
    
    char m_pad[0x5C];
    char m4[4];
    int Get();
};

int C_00262358::Get()
{
    int v;
    func_001E8180(m4, 0xDDBEE809, &v, 1);
    return v;
}
