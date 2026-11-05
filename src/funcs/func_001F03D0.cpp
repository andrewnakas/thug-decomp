extern "C" void* func_001EE410(void* prev);
extern "C" void func_001EE4D8(void* o, int chrg);
extern int D_0038E7E4;
extern int D_0038E7E8;

struct Obj_001F03D0 {
    char pad0[0xCC];
    unsigned int m_CC;
};

void Purge_001F03D0()
{
    if (D_0038E7E4) {
        D_0038E7E8 = 1;
        return;
    }
    Obj_001F03D0* o = (Obj_001F03D0*)func_001EE410(0);
    while (o) {
        Obj_001F03D0* next = (Obj_001F03D0*)func_001EE410(o);
        unsigned int f = o->m_CC;
        if ((f & 1) && ((f >> 1) & 1) == 0 && o) {
            func_001EE4D8(o, 3);
        }
        o = next;
    }
}
