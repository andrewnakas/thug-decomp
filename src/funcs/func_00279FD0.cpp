struct Vec_00279FD0 {
    float x, y, z, w;
};

extern char D_00376AF0[];

extern "C" bool func_001E5628(unsigned int name, int a);
extern "C" int func_0033ECA8(float f);
extern "C" void func_00103F28(const char* fmt, void* self, int ax, int ay, int az, int bx, int by, int bz);

void func_00279FD0(void* self, const Vec_00279FD0* a, const Vec_00279FD0* b)
{
    if (func_001E5628(0x19FB78FA, 1)) {
        func_00103F28(D_00376AF0, self, func_0033ECA8(a->x), func_0033ECA8(a->y), func_0033ECA8(a->z),
                      func_0033ECA8(b->x), func_0033ECA8(b->y), func_0033ECA8(b->z));
    }
}
