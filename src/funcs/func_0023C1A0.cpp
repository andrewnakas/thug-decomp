class Obj_0023C1A0 {
public:
    char pad0[0x14];
    virtual ~Obj_0023C1A0() = 0;
    virtual void V1();
};

struct Entry_0023C1A0 {
    char pad0[0x18];
    void* m18;
};

struct Table_0023C1A0 {
    int m0;
    int m_count;
};

struct It_0023C1A0 {
    Table_0023C1A0* m_table;
};


struct Self_0023C1A0;
extern "C" int func_0023C040(Self_0023C1A0* s);
extern "C" Entry_0023C1A0* func_00243C18(void* table, int* idx, void* pos);
extern "C" void func_00249DC8(void* p);
extern "C" It_0023C1A0* func_00243D58(It_0023C1A0* it, void* table);
extern "C" void func_00243CD0(Table_0023C1A0* t, int* pos);

struct Self_0023C1A0 {
    int m0;
    char m4[0x20 - 4];
    int m20;

    void Clear();
};

void Self_0023C1A0::Clear()
{
    int i = 0;
    int pos;
    m20 = 0;
    while (i < func_0023C040(this)) {
        func_00249DC8(func_00243C18(m4, &i, &pos)->m18);
        i++;
    }
    It_0023C1A0 it;
    It_0023C1A0* p = &it;
    func_00243D58(p, m4);
    int n = it.m_table->m_count;
    for (int k = 0; k < n; k++) {
        {
            int idx = 0;
            int pos2;
            Obj_0023C1A0* o = (Obj_0023C1A0*)func_00243C18(p->m_table, &idx, &pos2);
            func_00243CD0(p->m_table, &pos2);
            if (o)
                delete o;
        }
    }
}
