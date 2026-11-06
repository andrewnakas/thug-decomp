extern void* D_00389A30;
extern void* D_0038C7B0;
extern "C" void* func_0012E438(void* o, void* params, unsigned int name);
extern "C" void* func_001895B0(void* mgr, void* o);

bool Has_0018A370(void* params)
{
    return func_001895B0(D_0038C7B0, func_0012E438(D_00389A30, params, 0x40C698AF)) != 0;
}
