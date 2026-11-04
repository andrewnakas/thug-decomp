extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);

struct Ent_00149BD0 {
    unsigned int m_name;
    char pad[0x44];
};

extern "C" unsigned short func_00181AB0(Ent_00149BD0* e);
extern "C" unsigned short func_00181AD0(Ent_00149BD0* e);
extern "C" unsigned char func_00181AF0(Ent_00149BD0* e);
extern "C" unsigned char func_00181B58(Ent_00149BD0* e);
extern "C" unsigned char func_00181BB0(Ent_00149BD0* e);

struct Src_00149BD0 {
    char pad[0x18];
    int m_count;
    char pad1C[8];
    Ent_00149BD0* m_ents;
};

class T_00149BD0 {
public:
    unsigned int m0;
    int m4;
    void* m8;
    unsigned short m_w;
    unsigned short m_h;
    unsigned char m10;
    unsigned char m11;
    unsigned char m12;
    int m14;
    int m18;
    void* m1C;
    Ent_00149BD0* m20;
    char pad24[0xC];
    T_00149BD0(int a);
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

class M_00149BD0 {
public:
    char pad[0x14];
    Src_00149BD0* m14;
    void* Find(unsigned int name);
    void Add(T_00149BD0* t);
    void Load();
};

void M_00149BD0::Load()
{
    for (int i = 0; i < m14->m_count; i++) {
        if (!Find(m14->m_ents[i].m_name)) {
            T_00149BD0* t = new T_00149BD0(0);
            t->m0 = m14->m_ents[i].m_name;
            t->m_w = func_00181AB0(&m14->m_ents[i]);
            t->m_h = func_00181AD0(&m14->m_ents[i]);
            t->m10 = func_00181AF0(&m14->m_ents[i]);
            t->m11 = func_00181B58(&m14->m_ents[i]);
            t->m12 = func_00181BB0(&m14->m_ents[i]);
            t->m20 = &m14->m_ents[i];
            Add(t);
        }
    }
}
