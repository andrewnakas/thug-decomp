extern "C" void* func_00105520(void* self);
extern "C" void func_001E5488(void* obj, void* arg);

void OwnerCall_001E54B8(void* self, void* arg)
{
    func_001E5488(func_00105520(self), arg);
}
