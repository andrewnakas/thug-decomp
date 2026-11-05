extern char* D_00394144;
extern void* D_00394140;
extern char D_003F5390[];
extern "C" int func_00111038(void* buf, int size, int n, void* file);

extern "C" void func_0020AED8()
{
    int len = D_00394144 - D_003F5390;
    if (len) {
        func_00111038(D_003F5390, len, 1, D_00394140);
        D_00394144 = D_003F5390;
    }
}
