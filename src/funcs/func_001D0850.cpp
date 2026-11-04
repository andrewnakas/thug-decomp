extern "C" void* func_001F0D78(void* key);
extern "C" void* func_001D0820(void* self, void* item);

void* Fwd_001D0850(void* self, void* key)
{
    return func_001D0820(self, func_001F0D78(key));
}
