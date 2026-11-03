extern "C" void* func_00105520(void* self);
extern "C" void func_001E5318(void* obj, void* arg);

void OwnerCall_001E5370(void* self, void* arg)
{
    func_001E5318(func_00105520(self), arg);
}
