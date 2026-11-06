extern "C" void* func_001EE410(void* prev);
extern "C" void func_001EE9E0(void* p);
extern "C" void func_001EEB60(void* p);

extern "C" void func_001F0D98()
{
    for (void* p = func_001EE410(0); p; p = func_001EE410(p)) {
        func_001EE9E0(p);
        func_001EEB60(p);
    }
}
