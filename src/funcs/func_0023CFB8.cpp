extern "C" void* func_0023BAD8(void* owner, int id, int create);
extern "C" void func_00245888(void* obj, int value);

void Fwd_0023CFB8(void* owner, int id, int value)
{
    func_00245888(func_0023BAD8(owner, id, 1), value);
}
