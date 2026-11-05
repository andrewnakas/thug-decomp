struct Obj_001F51F8 {
    char pad0[0xC];
    volatile int mC;
    void Dec();
};

void Obj_001F51F8::Dec()
{
    if (mC > 0) mC--;
}
