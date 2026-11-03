struct Obj_002BAB90 {
    char pad[0x34];
    unsigned int m_type;
    bool IsKind();
};

bool Obj_002BAB90::IsKind()
{
    switch (m_type) {
    case 0x8A1576B6:
    case 0x4E2EFD2A:
    case 0x3A784D4C:
    case 0x613C7766:
    case 0xD7EB62B5:
    case 0xCA07B4FC:
    case 0xDC09A6A4:
    case 0xEC82433C:
        return true;
    }
    return false;
}
