extern "C" void* func_00105520(void* key);
extern "C" void* func_001E8708(void* self, void* item);

void* Fwd_001E87B8(void* self, void* key)
{
    return func_001E8708(self, func_00105520(key));
}
