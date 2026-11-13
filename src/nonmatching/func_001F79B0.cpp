/* fuzzy: 90.0 */
extern int D_0038EAA4;
extern int D_00394118;
extern int D_0038EAA8;
extern "C" int func_00345160(int mode);

static inline void WaitField_001F79B0(int field)
{
    while (func_00345160(0) == field) {
    }
}

extern "C" void func_001F79B0(int field)
{
    WaitField_001F79B0(field);
    D_0038EAA4 = 1;
    D_00394118 = 0;
    D_0038EAA8 = 0;
}
