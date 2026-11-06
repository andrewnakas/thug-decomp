/* sym: __12Str_00251B70RC12Str_00251B70 = 0x00104068 */
/* sym: __as__12Str_00251B70RC12Str_00251B70 = 0x00104170 */
/* sym: _$_12Str_00251B70 = 0x001040A8 */
struct Str_00251B70 {
    int m0[4];
    Str_00251B70(const Str_00251B70& o);
    Str_00251B70& operator=(const Str_00251B70& o);
    ~Str_00251B70();
};

struct Entry_00251B70 {
    Str_00251B70 m_name;
    int m_10;
    int m_14[3];
    int m_20;
};

struct Obj_00251B70;
extern "C" int func_00252188(Obj_00251B70* self);
extern "C" int func_00250C50(Entry_00251B70* e, int mode);

struct Obj_00251B70 {
    int m0;
    int m4;
    int m8;
    Entry_00251B70 m_ent[8];
    void Sort();
};

void Obj_00251B70::Sort()
{
    int mode = m8;
    if (func_00252188(this)) {
        mode = 2;
    }
    for (int i = 0; i < 7; i++) {
        int best = i;
        for (int j = i + 1; j < 8; j++) {
            if (func_00250C50(&m_ent[j], mode) > func_00250C50(&m_ent[best], mode)) {
                best = j;
            } else if (m_ent[j].m_10 == 0 && func_00250C50(&m_ent[j], mode) == func_00250C50(&m_ent[best], mode)) {
                best = j;
            }
        }
        if (best != i) {
            Entry_00251B70 tmp = m_ent[best];
            m_ent[best] = m_ent[i];
            m_ent[i] = tmp;
        }
    }
}
