extern void* D_00351DF8[];
extern "C" int func_001E36D8(int voice, float vol);
extern "C" int func_001E3548(int voice, float x, float y);
extern "C" bool func_001E3038(void* v);

extern "C" bool func_001E3AD0(int voice, float x, float y, float vol)
{
    func_001E36D8(voice, vol);
    func_001E3548(voice, x, y);
    return func_001E3038(D_00351DF8[voice]);
}
