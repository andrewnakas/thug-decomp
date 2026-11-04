struct Slot1324B8 {
    char m_pad[0xD4];
    void* mD4;
};

extern Slot1324B8* D_004653B0[4];

extern "C" void* func_001324B8()
{
    for (int i = 0; i < 4; i++) {
        Slot1324B8* s = D_004653B0[i];
        if (s && s->mD4) {
            return s->mD4;
        }
    }
    return 0;
}
