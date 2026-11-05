extern "C" void* func_00240850();
extern "C" int func_0023EE50(void* owner);
extern "C" void* func_0023BAD8(void* owner, int id, int create);
extern "C" void func_0024AE60(void* obj);

bool Cmd_00242280(void* params, void* script)
{
    void* owner = func_00240850();
    int id = func_0023EE50(owner);
    if (id) {
        func_0024AE60(func_0023BAD8(owner, id, 1));
    }
    return true;
}
