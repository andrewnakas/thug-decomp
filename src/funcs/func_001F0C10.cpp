extern "C" void* func_001EE410(void* prev);
extern "C" int func_001F00E8(void* obj, int a);
extern "C" void func_001EE9E0(void* obj);
extern "C" void func_001EEB60(void* obj);

struct Obj_001F0C10 {
    char pad0[0xC8];
    int m_C8;
    int m_CC;
};

void Kill_001F0C10(int type, int id, Obj_001F0C10* skip)
{
    Obj_001F0C10* o = (Obj_001F0C10*)func_001EE410(0);
    while (o) {
        Obj_001F0C10* next = (Obj_001F0C10*)func_001EE410(o);
        if ((o->m_CC & 1) && o != skip && func_001F00E8(o, type) && o->m_C8 == id) {
            func_001EE9E0(o);
            func_001EEB60(o);
        }
        o = next;
    }
}
