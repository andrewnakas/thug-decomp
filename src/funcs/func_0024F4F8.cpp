extern "C" int func_001E88D8(void* self, unsigned int name, int* out, int req);

struct C_0024F4F8 {
    int m0;
    char m4[4];
    bool Get();
};

bool C_0024F4F8::Get()
{
    int v;
    func_001E88D8(m4, 0xCA37E639, &v, 1);
    return v != 0;
}
