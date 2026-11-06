/* fuzzy: 77.3 */
struct C_001B3A48 {
    char pad0[0x20];
    unsigned long m_flags;
    void Handle(void* params);
};

extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" void func_001B4D68(C_001B3A48* self, void* params);
extern "C" void func_001B4E70(C_001B3A48* self, void* params);
extern "C" void func_001B6220(C_001B3A48* self, void* params, int flag);
extern "C" void func_001B5A20(C_001B3A48* self, void* params, int flag);
extern "C" void func_001B5070(C_001B3A48* self, void* params);
extern "C" void func_001B4F20(C_001B3A48* self, void* params, int flag);
extern "C" void func_001B6188(C_001B3A48* self, void* params);
extern "C" void func_001B52C0(C_001B3A48* self, void* params);
extern "C" void func_001B5388(C_001B3A48* self, void* params);
extern "C" void func_001B5DA8(C_001B3A48* self, void* params);

void C_001B3A48::Handle(void* params)
{
    if (m_flags & 0xC0)
        return;
    unsigned int id;
    if (!func_001E8398(params, 0x963DC198, &id, 0))
        return;
    switch (id) {
    case 0x255ED86F:
    case 0xE6DFAEC7:
        func_001B4D68(this, params);
        break;
    case 0xC870BCE5:
        func_001B4E70(this, params);
        break;
    case 0xBA1D1E94:
        func_001B6220(this, params, 0);
        break;
    case 0xE8F91257:
        func_001B6220(this, params, 1);
        break;
    case 0x12797A1B:
        func_001B5A20(this, params, 0);
        break;
    case 0x7D9D0008:
        func_001B5A20(this, params, 1);
        break;
    case 0x554DBD64:
        func_001B5070(this, params);
        break;
    case 0x584CF9E9:
        func_001B4F20(this, params, 0);
        break;
    case 0xD5B4F014:
        func_001B4F20(this, params, 1);
        break;
    case 0x6D3144BF:
        func_001B6188(this, params);
        break;
    case 0xEF24413B:
        func_001B52C0(this, params);
        break;
    case 0x9403A0ED:
        func_001B5388(this, params);
        break;
    case 0x46A9E949:
        func_001B5DA8(this, params);
        break;
    case 0xE41199AF:
    case 0xEC1CD520:
        break;
    }
}
