struct Obj_00229E70 {
    char pad[0xC];
    int m_C;
};

extern "C" bool func_001E8248(void* params, unsigned int name, Obj_00229E70** out, int required);

int Get_00229E70(void* params)
{
    Obj_00229E70* p = 0;
    func_001E8248(params, 0x2E7D5EE7, &p, 0);
    if (!p) {
        return 0;
    }
    return p->m_C;
}
