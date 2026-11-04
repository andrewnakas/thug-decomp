extern "C" void* func_00105520(void* self);
extern "C" void func_001E54E8(void* obj, void* arg);

void OwnerCall_001E5518(void* self, void* arg)
{
    func_001E54E8(func_00105520(self), arg);
}
