extern "C" void* func_002C95E0(int a);
extern "C" int func_002C8AB8(void* p);
extern "C" void func_002C8788(void* p);
extern "C" void func_002C8818(void* p);
extern "C" void func_002C86F0(void* p);

extern "C" int func_002CB838()
{
    int r = func_002C8AB8(func_002C95E0(1));
    if (r) {
        func_002C8788(func_002C95E0(1));
        func_002C8818(func_002C95E0(1));
    }
    func_002C86F0(func_002C95E0(1));
    return r;
}
