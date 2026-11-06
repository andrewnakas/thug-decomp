extern "C" bool func_001DC418(void* a, void* b);
extern "C" int func_001DC840(void* a, void* b);
extern "C" void func_001E1DB0(int id);

extern "C" bool func_001DD448(void* a, void* b)
{
    if (func_001DC418(a, b))
        return true;
    int id = func_001DC840(a, b);
    if (id >= 0) {
        func_001E1DB0(id);
        return true;
    }
    return false;
}
