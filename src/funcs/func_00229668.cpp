extern "C" void* func_001E55B8(unsigned int name, int a);
extern "C" void* func_001E9378(void* a, int index);
extern "C" bool func_001E8398(void* s, unsigned int name, unsigned int* out, int required);

extern short D_003F5988[];

short FindNode_00229668(unsigned int name)
{
    void* nodes = func_001E55B8(0xC472ECC5, 0);
    if (!nodes) {
        return -1;
    }
    int h = name & 0x3FFF;
    while (D_003F5988[h] != -1) {
        void* node = func_001E9378(nodes, D_003F5988[h]);
        unsigned int check = 0;
        if (func_001E8398(node, 0xA1DC81F9, &check, 0) && check == name) {
            return D_003F5988[h];
        }
        h = (h + 1) & 0x3FFF;
    }
    return -1;
}
