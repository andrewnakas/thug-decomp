struct Park_002CB940;
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" Park_002CB940* func_002C0368();
extern "C" void func_002BD268(Park_002CB940* p, int v);

bool func_002CB940(void* params, void* script)
{
    int v = 0;
    func_001E7DE8(params, 0x688A18F7, &v, 0);
    func_002BD268(func_002C0368(), v);
    return true;
}
