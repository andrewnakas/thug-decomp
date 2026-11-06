class Obj_00133418 {
public:
    char pad0[0x28];
    virtual ~Obj_00133418();
};

class Scene_00133418;
extern "C" int func_00135500(Obj_00133418* o);
extern "C" void func_00135580(Obj_00133418* o, int f);
extern "C" unsigned int func_00134F08(Obj_00133418* o);
extern "C" Obj_00133418* func_00132FD0(Scene_00133418* s, unsigned int id);
extern "C" void func_00114EB8(void* table, unsigned int* id);

class Scene_00133418 {
public:
    char pad0[0xD0];
    void* m_table;
    bool Remove(Obj_00133418* o);
};

bool Scene_00133418::Remove(Obj_00133418* o)
{
    if (func_00135500(o) & 0x40) {
        func_00135580(o, 8);
        return false;
    }
    if (func_00132FD0(this, func_00134F08(o)) == o) {
        unsigned int id = func_00134F08(o);
        func_00114EB8(m_table, &id);
    }
    if (o) {
        delete o;
    }
    return true;
}
