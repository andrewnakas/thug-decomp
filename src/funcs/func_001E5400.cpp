extern "C" void* func_00105520(void* self);
extern "C" void func_001E53A0(void* obj, void* arg);

void OwnerCall_001E5400(void* self, void* arg)
{
    func_001E53A0(func_00105520(self), arg);
}
