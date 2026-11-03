extern "C" void* func_00229DF0(void* self);
extern "C" void func_00229F00(void* obj, void* arg);

void OwnerCall_00229F48(void* self, void* arg)
{
    func_00229F00(func_00229DF0(self), arg);
}
