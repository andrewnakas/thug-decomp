extern "C" void* func_001F0D78(void* key);
extern "C" void* func_001D0638(void* self, void* item, void* arg);

void* Fwd_001D06C0(void* self, void* key, void* arg)
{
    return func_001D0638(self, func_001F0D78(key), arg);
}
