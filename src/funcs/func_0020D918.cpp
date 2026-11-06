struct S_0020D918 {
    char m_pad[0x18];
    void* m18;
};
extern "C" int func_001E8398(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E8618(void* a, int v);

extern "C" int func_0020D918(void* params, S_0020D918* script)
{
    int v = 0;
    func_001E8398(params, 0, &v, 0);
    return func_001E8618(script->m18, v);
}
