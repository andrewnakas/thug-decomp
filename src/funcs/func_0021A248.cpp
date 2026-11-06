extern "C" bool func_001E8398(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" bool func_0020B0A0(int a, int b, int c);

bool Cmd_0021A248(void* params)
{
    int a = 0;
    func_001E8398(params, 0x40C698AF, &a, 0);
    int b = 0;
    func_001E7DE8(params, 0x9FD29151, &b, 0);
    int c = func_001E8708(params, 0x10C1C887);
    return func_0020B0A0(a, b, c);
}
