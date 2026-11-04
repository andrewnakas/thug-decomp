extern "C" void* func_00105520(void* self);
extern "C" void func_00229C20(void* obj, void* arg);

void OwnerCall_00229C98(void* self, void* arg)
{
    func_00229C20(func_00105520(self), arg);
}
