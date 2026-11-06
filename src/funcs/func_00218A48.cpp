struct Script_00218A48 {
    char m_pad0[0x18];
    void* m_params;
};

extern int D_00388814;
extern char D_00370E58[];

extern "C" void func_001E73C8(void* params, char* name, unsigned int value);

bool Cmd_00218A48(void* params, Script_00218A48* script)
{
    unsigned int name = 0;
    switch (D_00388814) {
    case 1:
    case 2:
    case 3:
        name = 0x988A3508;
        break;
    case 5:
        name = 0xBCF00D45;
        break;
    case 4:
        name = 0x87D839B8;
        break;
    case 6:
        name = 0x4AF45E2E;
        break;
    }
    func_001E73C8(script->m_params, D_00370E58, name);
    return true;
}
