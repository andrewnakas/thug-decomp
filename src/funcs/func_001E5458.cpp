extern "C" void* func_00105520(void* self);
extern "C" void func_001E5430(void* obj, void* arg);

void OwnerCall_001E5458(void* self, void* arg)
{
    func_001E5430(func_00105520(self), arg);
}
