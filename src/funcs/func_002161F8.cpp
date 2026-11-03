struct Mgr_002161F8 {
    char pad[0x24];
    void* m_list;
};

extern Mgr_002161F8* D_0038FC78;
extern "C" void* func_001E53A0(unsigned int name, int flags);
extern "C" void func_00263C48(void* list, void* item);

bool Cmd_002161F8(void* params, void* script)
{
    void* list = D_0038FC78->m_list;
    func_00263C48(list, func_001E53A0(0x13D5B5DB, 0));
    func_00263C48(list, func_001E53A0(0x8ADCE461, 0));
    func_00263C48(list, func_001E53A0(0xFDDBD4F7, 0));
    func_00263C48(list, func_001E53A0(0x63BF4154, 0));
    func_00263C48(list, func_001E53A0(0x14B871C2, 0));
    func_00263C48(list, func_001E53A0(0x8DB12078, 0));
    func_00263C48(list, func_001E53A0(0xFAB610EE, 0));
    func_00263C48(list, func_001E53A0(0x6A090D7F, 0));
    func_00263C48(list, func_001E53A0(0x1D0E3DE9, 0));
    func_00263C48(list, func_001E53A0(0x37CBEE45, 0));
    func_00263C48(list, func_001E53A0(0x40CCDED3, 0));
    func_00263C48(list, func_001E53A0(0xD9C58F69, 0));
    func_00263C48(list, func_001E53A0(0xAEC2BFFF, 0));
    func_00263C48(list, func_001E53A0(0x30A62A5C, 0));
    func_00263C48(list, func_001E53A0(0x47A11ACA, 0));
    func_00263C48(list, func_001E53A0(0xDEA84B70, 0));
    func_00263C48(list, func_001E53A0(0xA9AF7BE6, 0));
    func_00263C48(list, func_001E53A0(0x39106677, 0));
    func_00263C48(list, func_001E53A0(0x4E1756E1, 0));
    func_00263C48(list, func_001E53A0(0x1CE6BD86, 0));
    func_00263C48(list, func_001E53A0(0x6BE18D10, 0));
    func_00263C48(list, func_001E53A0(0xF2E8DCAA, 0));
    func_00263C48(list, func_001E53A0(0x85EFEC3C, 0));
    return true;
}
