extern "C" void* func_00136D58(int id);
extern "C" void* func_00136F08(void* light);
extern "C" void func_00132A80(void* list);
extern "C" void* func_00132A90(void* list, int a);
extern "C" void* func_00134F18(void* o);
extern "C" void func_00137130(void* o);

extern "C" void func_00137528(void* scene, int id)
{
    if (!id)
        return;
    void* light = func_00136D58(id);
    if (!light)
        return;
    void* list = func_00136F08(light);
    if (!list)
        return;
    func_00132A80(list);
    void* o;
    while ((o = func_00132A90(list, 0)) != 0) {
        if (func_00134F18(o))
            func_00137130(o);
    }
}
