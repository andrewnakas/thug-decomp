struct Obj_001EEB60 {
    char pad[0xDC];
    void* mDC;
    void Detach();
};
extern "C" void func_00188BA8(void* o, Obj_001EEB60* self);
extern "C" void func_00188558(void* o, unsigned int id);

void Obj_001EEB60::Detach()
{
    if (mDC) {
        func_00188BA8(mDC, this);
        func_00188558(mDC, 0x8B713E0E);
    }
}
