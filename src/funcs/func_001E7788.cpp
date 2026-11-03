extern "C" void* func_00105520(void* key);
extern "C" void* func_001E7720(void* self, void* item, void* arg);

void* Fwd_001E7788(void* self, void* key, void* arg)
{
    return func_001E7720(self, func_00105520(key), arg);
}
