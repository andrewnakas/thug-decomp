struct Obj_002CC030 {
    int m0;
    void* m4[32];
    int FreeSlot();
};

int Obj_002CC030::FreeSlot()
{
    for (int i = 0; i < 32; i++) {
        if (!m4[i])
            return i;
    }
    return -1;
}
