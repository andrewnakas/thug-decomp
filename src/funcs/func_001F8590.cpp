extern "C" int func_003250C0(int cmd, int* res);
extern "C" void func_001FA658(void* self, int v);

int func_001F8590(void* self)
{
    int res[4];
    if (func_003250C0(2, res)) {
        func_001FA658(self, 1);
        return 0;
    }
    return 1;
}
