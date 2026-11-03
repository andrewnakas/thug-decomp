extern "C" void* func_00105520(void* key);
extern "C" void* func_001E8618(void* self, void* item);

void* Fwd_001E86D0(void* self, void* key)
{
    return func_001E8618(self, func_00105520(key));
}
