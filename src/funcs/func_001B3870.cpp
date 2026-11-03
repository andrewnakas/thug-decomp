extern "C" void* func_00229DF0(void* e);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);

int func_001B3870(void* self, void* e)
{
    unsigned int type;
    if (!func_001E8398(func_00229DF0(e), 0x963DC198, &type, 0)) return 0;
    if (type == 0x7D9D0008 || type == 0x554DBD64 || type == 0xE6DFAEC7 || type == 0xDA0723DA
        || type == 0xE8F91257 || type == 0xD5B4F014) return 1;
    return 0;
}
