extern "C" void* func_00105520(void* key);
extern "C" void* func_001E7360(void* self, void* item, void* arg);

void* Fwd_001E73C8(void* self, void* key, void* arg)
{
    return func_001E7360(self, func_00105520(key), arg);
}
