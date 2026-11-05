extern "C" void* func_00138528(void* key);
extern "C" void* func_00139468(void* self, void* item);

void* Fwd_001394A0(void* self, void* key)
{
    return func_00139468(self, func_00138528(key));
}
