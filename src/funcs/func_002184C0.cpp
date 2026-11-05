struct Obj_002184C0 {
    char pad[0x1E0];
    int m1E0;
};
extern "C" int func_001E8398(void* params, unsigned int id, int* out, int req);
extern "C" Obj_002184C0* func_00141250(int id);

int func_002184C0(void* params, void* script)
{
    int v;
    func_001E8398(params, 0xA1DC81F9, &v, 1);
    Obj_002184C0* p = func_00141250(v);
    if (p)
        return p->m1E0;
    return 0;
}
