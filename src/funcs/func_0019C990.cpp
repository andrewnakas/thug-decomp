/* Static-init for a 0x84-element array of objects whose constructor is empty: only the count-down loop remains. */
inline void* operator new[](unsigned int, void* p) { return p; }

struct Elem_0019C990 {
    Elem_0019C990() {}
    int m0;
};

extern Elem_0019C990 g_table_0019C990[0x84];

void func_0019C990(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize)
        new (g_table_0019C990) Elem_0019C990[0x84];
}
