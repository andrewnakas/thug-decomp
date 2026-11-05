extern "C" int func_001E88D8(void* self, unsigned int name, int* out, int req);

struct C_0024F5F8 {
    int m0;
    char m4[4];
    int Get();
};

int C_0024F5F8::Get()
{
    int v;
    func_001E88D8(m4, 0x8D38A280, &v, 1);
    return v;
}
