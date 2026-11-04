extern "C" void* func_00105520(void* self);
extern "C" void func_001E55B8(void* obj, void* arg);

void OwnerCall_001E55F8(void* self, void* arg)
{
    func_001E55B8(func_00105520(self), arg);
}
