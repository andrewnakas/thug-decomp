extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void func_001DF8E8(unsigned int v);

void Cmd_0021ADC0(void* params)
{
    unsigned int v;
    func_001E8398(params, 0, &v, 1);
    func_001DF8E8(v);
}
