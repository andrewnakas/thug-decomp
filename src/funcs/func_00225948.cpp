extern void* D_0038FC78;
extern "C" void* func_0022E050(void* self);
extern "C" int func_002628F0(void* obj);
extern "C" void func_00262D10(void* obj, void* a, int flag);

void Apply_00225948(void* a)
{
    void* obj = func_0022E050(D_0038FC78);
    if (!func_002628F0(obj)) {
        func_00262D10(obj, a, 0);
    } else {
        func_00262D10(obj, a, 1);
    }
}
