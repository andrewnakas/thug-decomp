extern int D_00390EF8;
extern "C" void* func_001E53A0(unsigned int name, int a);
extern "C" int func_00263C78(void* self, void* p);

int Set_00263BD8(void* self, unsigned int name)
{
    D_00390EF8 = func_00263C78(self, func_001E53A0(name, 0));
    return D_00390EF8;
}
