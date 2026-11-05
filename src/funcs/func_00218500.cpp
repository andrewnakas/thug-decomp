struct Obj_00218500 {
    char pad[0x1E0];
    int m1E0;
};

extern char D_0038F368[];
extern "C" bool func_001E84E8(void* params, char* name, unsigned int* out, int required);
extern "C" Obj_00218500* func_00141250(unsigned int id);

extern "C" bool func_00218500(void* params, void* script)
{
    unsigned int id;
    func_001E84E8(params, D_0038F368, &id, 1);
    Obj_00218500* p = func_00141250(id);
    if (p)
        p->m1E0 = 1;
    return p != 0;
}
