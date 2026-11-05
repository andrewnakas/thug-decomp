struct Mgr_0021DDE8 {
    char pad[0x24];
    void* m24;
};
extern Mgr_0021DDE8* D_0038FC78;
extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);
extern "C" int func_00263AD8(void* p);

bool func_0021DDE8(void* params, void* script)
{
    float v;
    if (func_001E7EB0(params, 0, &v, 0) && (float)func_00263AD8(D_0038FC78->m24) == v)
        return true;
    return false;
}
