/* fuzzy: 57.1 */
/* NM 18/30: game peels first iteration and runs a reversed count-9 loop (bnez); tried for/while/do/for(;;)/count-down forms */
struct Ent_001E6178 {
    int m_key;
    void* m_val;
};

extern int D_00388818;
extern Ent_001E6178* D_0038E580;

extern "C" void* func_001E6178(int key)
{
    if (!D_00388818)
        return 0;
    Ent_001E6178* e = &D_0038E580[(key & 0xFFFF) * 10];
    int i = 0;
    while (e->m_val && i < 10) {
        if (e->m_key == key)
            return e->m_val;
        e++;
        i++;
    }
    return 0;
}
