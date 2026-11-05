extern "C" int func_001E88D8(void* self, unsigned int name, int* out, int req);

struct C_0024F750 {
    int m0;
    char m4[4];
    int Get();
};

int C_0024F750::Get()
{
    int v;
    func_001E88D8(m4, 0x4D42E61D, &v, 1);
    return v;
}
