struct Table_00139468;
extern "C" void* func_00139A20(Table_00139468* t, unsigned int* key, int n);

class Obj_00139468 {
public:
    int m0;
    int m4;
    Table_00139468* m_table;
    void* Find(unsigned int key);
};

void* Obj_00139468::Find(unsigned int key)
{
    if (!m_table) {
        return 0;
    }
    return func_00139A20(m_table, &key, 1);
}
