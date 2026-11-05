extern "C" void* func_00132FD0(void* self, int key);
extern "C" void* func_00133418(void* self, void* e);

void* Get_001333D8(void* self, int key)
{
    void* e = func_00132FD0(self, key);
    if (e)
        return func_00133418(self, e);
    return 0;
}
