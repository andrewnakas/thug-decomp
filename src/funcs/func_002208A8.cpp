extern int D_0038881C;
extern void* D_0038FC78;
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_0022E048(void* self);
extern "C" void func_00265DF8(void* obj, int v);

bool Cmd_002208A8(void* params, void* script)
{
    if (!D_0038881C) {
        int v = 0;
        func_001E7DE8(params, 0, &v, 0);
        func_00265DF8(func_0022E048(D_0038FC78), v);
    }
    return true;
}
