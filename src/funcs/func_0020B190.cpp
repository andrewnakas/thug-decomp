extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_001EFFB0(void* o, int v);
extern "C" void func_001EFF90(void* o, int v);
extern "C" void func_001EFFA0(void* o, int v);

bool Cmd_0020B190(void* params, void* o)
{
    float t = 0.0f;
    func_001E7EB0(params, 0, &t, 0);
    if (func_001E8708(params, 0xD029F619) || func_001E8708(params, 0x49E0EE96)) {
        func_001EFFB0(o, (int)(t * 1000.0f));
        return true;
    }
    if (func_001E8708(params, 0xFC37DF05) || func_001E8708(params, 0xB99AE3D6) ||
        func_001E8708(params, 0xDCD4CE73)) {
        func_001EFF90(o, (int)t);
        return true;
    }
    if (func_001E8708(params, 0x4A07C332) || func_001E8708(params, 0x019176C5)) {
        func_001EFFB0(o, (int)(t * 16.66666794f));
        return true;
    }
    if (func_001E8708(params, 0xECAA3345)) {
        func_001EFFA0(o, (int)t);
        return true;
    }
    func_001EFFB0(o, (int)t);
    return true;
}
