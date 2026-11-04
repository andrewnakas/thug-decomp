extern "C" void* func_00105520(void* key);
extern "C" void* func_001E6B90(void* self, void* item);

void* Fwd_001E6C28(void* self, void* key)
{
    return func_001E6B90(self, func_00105520(key));
}
