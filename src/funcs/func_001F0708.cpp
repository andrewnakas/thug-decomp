struct Obj_001F0708 {
    char pad[0xAC];
    int mAC;
};
extern "C" Obj_001F0708* func_001EE410(Obj_001F0708* prev);

Obj_001F0708* func_001F0708(int id)
{
    Obj_001F0708* p = 0;
    while ((p = func_001EE410(p)) != 0) {
        if (p->mAC == id)
            return p;
    }
    return 0;
}
