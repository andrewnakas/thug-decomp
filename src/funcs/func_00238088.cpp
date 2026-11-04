extern void* D_0038FC78;

struct List_00238088 {
    int pad0;
    int m_count;
    int GetCount() const { return m_count; }
};

struct Entry_00238088 {
    char pad[0x14];
    int m_14[4];
};

struct Obj_00238088 {
    short pad0;
    short m_id;
    int pad4;
    int m_8;
    int m_C;
    char pad10[0x1C];
    List_00238088 m_list;
    char pad34[0x24];
    int m_58;
    int m_5C;
    char pad60[8];
    int m_68;
};

extern "C" Entry_00238088* func_0023B2B8(List_00238088* list, int* i, int a);
extern "C" void* func_0022DF08(void* mgr, int id);
extern "C" void func_00238EF8(Obj_00238088* obj, int score, int mult);
extern "C" int func_002041F8(void* skater);
extern "C" void func_00237040(Obj_00238088* obj, int a);
extern "C" void func_00238780(Obj_00238088* obj, int clear);
extern "C" void func_00238728(Obj_00238088* obj);
extern "C" void func_0023AC30(Obj_00238088* obj, int a);
extern "C" void* func_00185578(void* a, unsigned int key);
extern "C" void func_0029E5C0(void* a);
extern "C" void* func_00240850();
extern "C" void func_0023F9D0(void* a);

void func_00238088(Obj_00238088* obj, int arg)
{
    for (int i = 0; i < obj->m_list.GetCount(); i++) {
        Entry_00238088* e = func_0023B2B8(&obj->m_list, &i, 0);
        for (int j = 0; j < 4; j++)
            e->m_14[j] = 0;
    }
    if (obj->m_58) {
        obj->m_8 = 0;
        if (!arg) {
            void* skater = func_0022DF08(D_0038FC78, obj->m_id);
            func_00238EF8(obj, obj->m_C * obj->m_5C, 0);
            func_00237040(obj, func_002041F8(skater));
        } else {
            func_00238780(obj, 1);
            func_00238EF8(obj, 0, 0);
        }
    }
    func_00238728(obj);
    obj->m_68 = 0;
    func_0023AC30(obj, 0);
    func_0029E5C0(func_00185578(func_0022DF08(D_0038FC78, obj->m_id), 0x8BCE7E66));
    func_0023F9D0(func_00240850());
}
