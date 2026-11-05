extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);

struct C_002466E0 {
    char m_pad[0x20];
    void* m20;
    int Get();
};

int C_002466E0::Get()
{
    int v = -1;
    func_001E7DE8(m20, 0x78FFB85C, &v, 0);
    return v;
}
