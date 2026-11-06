struct Obj_0021DE40 { char pad[0x24]; int m24; };
extern Obj_0021DE40* D_0038FC78;
extern "C" int func_001E7EB0(void* params, int name, float* out, int required);
extern "C" int func_00263B58(int v);

bool Cmd_0021DE40(void* params, void* script)
{
    float v;
    if (func_001E7EB0(params, 0, &v, 0)) {
        if (v < (float)func_00263B58(D_0038FC78->m24)) {
            return true;
        }
    }
    return false;
}
