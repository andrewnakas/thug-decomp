extern void* D_0038FC78;
extern void* D_0038C608;
extern "C" void* func_0022DE70(void* self, int index);
extern "C" void* func_00187278(void* a, unsigned int name);
extern "C" void func_00291DE8(void* a);

bool Cmd_00223CA8(void* params, void* script)
{
    void* mgr = D_0038FC78;
    for (int i = 0; i < 8; i++) {
        if (func_0022DE70(mgr, i)) {
            func_00291DE8(func_00187278(D_0038C608, 0x43686585));
        }
    }
    return true;
}
