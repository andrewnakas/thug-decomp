extern "C" void* func_001EE410(void* prev);
extern "C" int func_001F00E8(void* obj, void* a);
extern "C" int func_001EFFE8(void* obj, void* b);
extern "C" void func_001EE9E0(void* obj);
extern "C" void func_001EEB60(void* obj);

extern "C" void func_001F0E98(void* a, void* b)
{
    for (void* o = func_001EE410(0); o; o = func_001EE410(o)) {
        if (!func_001F00E8(o, a))
            continue;
        if (b && !func_001EFFE8(o, b))
            continue;
        func_001EE9E0(o);
        func_001EEB60(o);
    }
}
