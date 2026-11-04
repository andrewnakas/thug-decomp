extern "C" void* func_00229DF0(void* p);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void func_00259E40(void* p, void* a);
extern char D_00390AC8[];

struct Arr_00259BA8 {
    char* m0;
};

void* Get_00259BA8(Arr_00259BA8* self, void* a, void* b)
{
    void* p = func_00229DF0(b);
    int i = 0;
    func_001E7E58(p, D_00390AC8, &i, 0);
    func_00259E40(self->m0 + i * 0x258, a);
    return self->m0 + i * 0x258;
}
