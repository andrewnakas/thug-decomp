extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void func_0023D500(void* owner, int id);

bool Cmd_00241478(void* params, void* script)
{
    unsigned int id;
    if (func_001E8398(params, 0xA1DC81F9, &id, 0)) {
        func_0023D500(func_00240850(), id);
        return true;
    }
    return false;
}
