extern "C" bool func_001E8A30(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E8180(void* params, unsigned int name, int* out, int required);
extern "C" void func_001F1068(void* obj, int a, int b, unsigned int type, bool flag, int c);


bool func_0021AAD0(void* params, void* obj)
{
    int a = 0;
    func_001E8A30(params, 0xF8728BEC, &a, 1);
    int b = 0;
    func_001E8A30(params, 0xA6D2D890, &b, 1);
    unsigned int type = 0x1CA1FF20;
    func_001E8398(params, 0x923FBB3A, &type, 0);
    bool flag = func_001E8708(params, 0x80367192);
    int c = 0;
    func_001E8180(params, 0x7031F10C, &c, 0);
    func_001F1068(obj, a, b, type, flag, c);
    return true;
}
