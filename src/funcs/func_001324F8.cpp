struct Slot1324F8 {
    char m_pad[0xD4];
    void* mD4;
};

extern Slot1324F8* D_004653B0[4];

extern "C" void* func_001324F8()
{
    for (int i = 0; i < 4; i++) {
        Slot1324F8* s = D_004653B0[i];
        if (s && s->mD4) {
            return s->mD4;
        }
    }
    return 0;
}
