extern "C" void* func_0023BAD8(void* owner, int id, int create);
extern "C" void func_00248700(void* obj, int value);

void Fwd_0023F560(void* owner, int id, int value)
{
    func_00248700(func_0023BAD8(owner, id, 1), value);
}
