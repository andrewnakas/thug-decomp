struct Obj_00219BE0 {
    char m0;
    char m1;
    unsigned char m2;
};
extern "C" int func_001E8398(void* params, unsigned int id, int* out, int req);
extern "C" Obj_00219BE0* func_001E5040(int id);

bool func_00219BE0(void* params, void* script)
{
    int v = 0;
    func_001E8398(params, 0, &v, 0);
    Obj_00219BE0* p = func_001E5040(v);
    if (p && p->m2 == 7)
        return true;
    return false;
}
