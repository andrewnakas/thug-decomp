extern "C" int func_001E88D8(void* self, unsigned int name, int* out, int req);

struct C_00261EE0 {
    
    char m_pad[0x5C];
    char m4[4];
    int Get();
};

int C_00261EE0::Get()
{
    int v;
    func_001E88D8(m4, 0x471FC4DD, &v, 1);
    return v;
}
