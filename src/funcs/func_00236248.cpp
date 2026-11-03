struct Obj_00236248 {
    char m_pad[0x24];
    void* m24;
};

extern "C" bool func_00263BD8(void* self, unsigned int name);

unsigned int func_00236248(Obj_00236248* self)
{
    unsigned int flags = 0;
    if (func_00263BD8(self->m24, 0xEEFECF1B)) {
        flags |= 0xEEFECF1B;
    }
    if (func_00263BD8(self->m24, 0xB38341C9)) {
        flags |= 0xB38341C9;
    }
    if (func_00263BD8(self->m24, 0xCD09E062)) {
        flags |= 0xCD09E062;
    }
    if (func_00263BD8(self->m24, 0x69A1CE96)) {
        flags |= 0x69A1CE96;
    }
    if (func_00263BD8(self->m24, 0xEEFECF1B)) {
        flags |= 0xEEFECF1B;
    }
    if (func_00263BD8(self->m24, 0x6B0F24BC)) {
        flags |= 0x6B0F24BC;
    }
    if (func_00263BD8(self->m24, 0x520A66EF)) {
        flags |= 0x520A66EF;
    }
    if (func_00263BD8(self->m24, 0xEBA89179)) {
        flags |= 0xEBA89179;
    }
    if (func_00263BD8(self->m24, 0xC4FFC672)) {
        flags |= 0xC4FFC672;
    }
    if (func_00263BD8(self->m24, 0xD5982173)) {
        flags |= 0xD5982173;
    }
    return flags;
}
