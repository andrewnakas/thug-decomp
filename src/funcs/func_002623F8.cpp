extern "C" int func_001E88D8(void* self, unsigned int name, int* out, int req);

struct C_002623F8 {
    char m_pad[0x5C];
    char m4[4];
    bool Get();
};

bool C_002623F8::Get()
{
    int v;
    func_001E88D8(m4, 0x4564BAB1, &v, 1);
    return v != 0;
}
