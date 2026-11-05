extern char D_00388E38[];
extern "C" void* func_00110E38(void* a, char* mode);
extern "C" void func_00110EF8(void* f);

bool Try_001105C8(void* a)
{
    void* f = func_00110E38(a, D_00388E38);
    if (f) {
        func_00110EF8(f);
        return true;
    }
    return false;
}
