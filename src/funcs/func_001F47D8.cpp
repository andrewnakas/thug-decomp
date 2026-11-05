struct Obj_001F47D8 {
    char pad[0xAA0];
    void* mAA0;
    void* mAA4;
    void* mAA8;
    void Set(void* p);
};
extern "C" void* func_00185578(void* o, unsigned int id);

void Obj_001F47D8::Set(void* p)
{
    mAA0 = p;
    if (!p) {
        mAA4 = 0;
        mAA8 = 0;
    } else {
        mAA4 = func_00185578(p, 0x43686585);
        mAA8 = func_00185578(mAA0, 0xD9151D4D);
    }
}
